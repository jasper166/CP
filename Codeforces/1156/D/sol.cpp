#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

struct DisjointSets {
    vector <int> pa, sz;
    int n;
    DisjointSets(int _n) {
        n = _n;
        pa.resize(_n + 5);
        sz.resize(_n + 5);
        for (int i = 1; i <= n; ++i) pa[i] = i, sz[i] = 1;
    } 
    int get(int u) { return (u == pa[u]? u : pa[u] = get(pa[u])); }
    bool unite(int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v) return 0;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        pa[v] = u;
        return 1;
    }
};

int n;
void run_case() {
    cin >> n;
    DisjointSets dsu_0(n), dsu_1(n);

    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w)
            dsu_1.unite(u, v);
        else 
            dsu_0.unite(u, v);
    }

    ll ans = 0;
    for (int u = 1; u <= n; ++u) {
        // 00
        int x = dsu_0.get(u);
        if (x == u) {
            int sz = dsu_0.sz[x];
            ans += 1ll * sz * (sz - 1);
        }
        // 11
        int y = dsu_1.get(u);
        if (y == u) {
            int sz = dsu_1.sz[y];
            ans += 1ll * sz * (sz - 1);
        }
        // ..00.. -> u -> ..11..
        ans += 1ll * (dsu_0.sz[x] - 1) * (dsu_1.sz[y] - 1);
        // debug(x, y, u);
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
