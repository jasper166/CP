#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 998244353;
const int MAX = 1e6 + 5;

int n, s;

struct DisjoinSets {
    vector <int> sz, pa;
    int n;
    DisjoinSets(int N) {
        n = N;
        sz.assign(N + 5, 0);
        pa.assign(N + 5, 0);
        for (int i = 1; i <= n; ++i) {
            sz[i] = 1;
            pa[i] = i;
        }
    }
    int find(int u) {
        return (u == pa[u]? u : pa[u] = find(pa[u]));
    }
    int getSz(int u) {
        return sz[find(u)];
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return 0;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        pa[v] = u;
        return 1;
    }
};

int bPow(int a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (1ll * ans * a) % MOD;
        a = (1ll * a * a) % MOD;
        b >>= 1;
    }
    return (int) ans % MOD;
}

void run_case() {
    cin >> n >> s;
    vector <tuple <ll, int, int>> edges;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    DisjoinSets dsu(n);
    sort(edges.begin(), edges.end());
    // for (auto &[w, u, v] : edges) {
    //     debug(u, v, w);
    // }
    ll ans = 1;
    for (auto &[w, u, v] : edges) {
        if (dsu.find(u) != dsu.find(v)) {
            int x = dsu.getSz(u);
            int y = dsu.getSz(v);
            ll cnt = 1ll * x * y - 1;
            ans *= 1ll * bPow(s - w + 1, cnt);
            ans %= MOD;
            dsu.unite(u, v);
        }
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


