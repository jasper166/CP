#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

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
#else
#define debug(...) 166
#define debugArr(...) 166
#endif


const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;


struct DisjointSets {
    int *sz, *p;
    int n;
    void init(int N) {
        n = N;
        sz = new int[n + 1];
        p = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            sz[i] = 1;
            p[i] = i;
        }
    }

    int find(int u) {
        return (u == p[u]? u : p[u] = find(p[u]));
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return 0;
        if (sz[v] > sz[u]) swap(u, v);
        sz[u] += sz[v];
        p[v] = u;
        return 1;
    }

    int getSz(int u) {
        return (sz[find(u)]);
    }
} dsu;

void run_case() {
    int n, m; cin >> n >> m;
    dsu.init(n);
    vector <pii> e(m + 1);
    for (int i = 1; i <= m; i++) cin >> e[i].fi >> e[i].se;
    
    vector <ll> ans(m + 1);
    ans[m] = 1ll * n * (n - 1) / 2;
    for (int i = m - 1; i >= 1; i--) {
        auto [u, v] = e[i + 1];
        debug(u, v);
        
        int A = dsu.getSz(u);
        int B = dsu.getSz(v);
        int dec = (dsu.find(u) == dsu.find(v))? 0 : 1ll * A * B;
        ans[i] = ans[i + 1] - dec;
        dsu.unite(u, v);
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

