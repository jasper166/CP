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

int p[MAX], rk[MAX];
int n, m;

int get (int u ) {
    return (u == p[u]? u : p[u] = get(p[u]));
}

bool unite (int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v)
        return 0;
    if (rk[v] > rk[u])
        swap(u, v);
    p[v] = u;
    if (rk[u] == rk[v])
        rk[u]++;
    return 1;
}
using T = tuple <int, int, int>;

void run_case(){
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        rk[i] = 0;
        p[i] = i;
    }
    vector <T> e;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e.emplace_back(w, u, v);
    }
    sort(all(e));
    int res = 0;
    for (auto [w, u, v] : e) {
        if (unite(u, v)) {
            res += w;
        }
    }
    cout << res << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
