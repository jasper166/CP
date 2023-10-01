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

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

vector <int> adj[MAX];
int n, m;
int res[MAX];
bool used[MAX];

struct Vertices {
    int u, w;
    bool operator < (const Vertices &a) const{
        return (w > a.w);
    }
} a[MAX];

struct DisjointSets {
    int *sz, *p;
    int n;
    DisjointSets (int N) {
        this->n = N;
        sz = new int[n + 1];
        p = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            sz[i] = 1;
            p[i] = i;
        }
    }
    
    int get (int u) {
        return (u == p[u]? u : p[u] = get(p[u]));
    }

    void join (int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v)
            return;
        if (sz[v] > sz[u])
            swap(u, v);
        sz[u] += sz[v];
        p[v] = u;
    }
};



void run_case(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[i] = {i, x};
        adj[i].clear();
        res[i] = -1;
        used[i] = 0;
    }
    
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sort(a + 1, a + 1 + n);
    DisjointSets dsu(n);
    // debugArr(a, 1, 1 + n);
    // FOR(i, 1, n) {
    //     debug(a[i].u, a[i].w);
    // }
    for (int i = 1; i <= n; i++) {
        auto [u, w] = a[i];
        used[u] = 1;
        for (int v: adj[u]) {
            if (used[v])
                dsu.join(u, v);
        }
        int pz = dsu.sz[dsu.get(u)];
        if (res[pz] == -1)
            res[pz] = w;
    }
    FOR(i, 1, n) {
        debug(res[i]);
    }
    for (int i = n - 1; i >= 1; i--)
        res[i] = max(res[i], res[i + 1]);

    for (int i = 1; i <= n; i++) 
        cout << res[i] << " \n"[i == n];
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

