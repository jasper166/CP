#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#define TASK "INP"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif
#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int fact[MAX], invs[MAX];
int Power (int A, int B) {
        int64_t res = 1;
        for (; B ; B >>= 1, A = (1LL * A * A) % MOD)
             if (B & 1)
                (res *= A) %= MOD;
        return (int) res;
}

int C (int N, int K) {
        if (K > N || N < 0 || K < 0)
                return 0;
        return (1LL * (1LL * fact[N] * invs[N - K]) % MOD * invs[K]) % MOD;
}

int P(int N, int K) {
        if (K > N)
                return 0;
        return (1LL * fact[N] * invs[N - K]) % MOD;
}

void prepare(int N) {
        fact[0] = 1;
        for (int i = 1 ; i <= N ; i ++)
                fact[i] = (1LL * fact[i - 1] * i) % MOD;
        invs[N] = Power(fact[N], MOD - 2);
        for (int i = N - 1 ; i >= 0 ; i --) {
                invs[i] = (1LL * invs[i + 1] * (i + 1)) % MOD;
        }
}

int n, q;
vector <int> adj[MAX];  
struct edge {
    int u, v, w;
} e[MAX];

int sz[MAX];

void dfs (int u, int p){
    sz[u] = 1;
    for (auto v : adj[u]){
        if (v == p)
            continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

ll calc (int i, int val) {
    int lower = sz[e[i].v];
    int upper = n - lower;
    ll res = 0;
    if (upper >= 2)
        res += 2LL * val * e[i].w * (1LL * upper * (upper - 1) / 2LL) * lower;
    if (lower >= 2)
        res += 2LL * val * e[i].w * (1LL * lower * (lower - 1) / 2LL) * upper;
    return res;
}

void run_case(){
    cin >> n;
    prepare(n);

    for (int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    ll sum = 0;
    ll total = 1LL * n * (n - 1) * (n - 2) / 6LL;

    for (int i = 1; i < n; i++){
        if (sz[e[i].u] < sz[e[i].v])
            swap(e[i].u, e[i].v);
        sum += calc(i, 1);
    }

    debug(total);
    cin >> q;
    while (q--){
        int x, w;
        cin >> x >> w;
        sum += calc(x, -1);
        e[x].w = w;
        sum += calc(x, 1);
        cout << fixed << setprecision(6) << (double) sum / (double) total << "\n";
    }
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

