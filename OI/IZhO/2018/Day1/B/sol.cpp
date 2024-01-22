#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 1e5 + 5;
const int INF = 1e9 + 5;

int n, m, k, q;
int g[N], d[N], a[N];
vector <pair <int, int>> adj[N];
// d(x) : shortest distance from x to a critical vertex
void dijkstra() {
    for (int i = 1; i <= n; ++i) d[i] = INF;

    using T = pair <int, int>;
    priority_queue <T, vector <T>, greater <>> pq;
    for (int i = 1; i <= k; ++i) {
        d[g[i]] = 0;
        pq.push({d[g[i]], g[i]});
    }

    while (!pq.empty()) {
        auto [du, u] =  pq.top(); pq.pop();
        if (du > d[u]) continue;
        for (auto [w, v] : adj[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i) a[i] = i;
    sort(a + 1, a + 1 + n, [&] (int x, int y) {
        return d[x] > d[y];
    });
}

struct Query {
    int s, t, l, r, mi, id;
} qs[N];

struct DisjointSet {
    vector <int> pa, sz;
    int n;
    DisjointSet(int _n = 0) { init(_n); }
    void init(int _n) {
        n = _n;
        sz.resize(n + 5, 1);
        pa.resize(n + 5, 0);
        iota(pa.begin(), pa.end(), 0);
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

int ans[N];
void solve() {
    DisjointSet dsu(n);
    // DSU storing all vertices having d[x] >= current best answer
    for (int i = 1; i <= q; ++i) {
        qs[i].mi = (qs[i].l + qs[i].r) / 2;
    }
    // sort queries according to mid
    sort(qs + 1, qs + 1 + q, [&] (Query x, Query y){
        return (x.mi > y.mi);
    });
    int j = 1;
    vector <bool> vis(n + 5, 0);
    for (int i = 1; i <= q; ++i) {
        auto [s, t, l, r, mi, id] = qs[i];
        if (l > r) continue;
        while (j <= n && d[a[j]] >= mi) {
            vis[a[j]] = 1;
            for (auto [w, v] : adj[a[j]])
                if (vis[v])
                    dsu.unite(v, a[j]);
            ++j;
        }
        if (vis[s] && vis[t] && dsu.get(s) == dsu.get(t)) {
            ans[id] = mi;
            qs[i].l = mi + 1;
        }
        else 
            qs[i].r = mi - 1;
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    cin >> k;
    for (int i = 1; i <= k; ++i) cin >> g[i];
    dijkstra();

    // for (int i = 1; i <= n; ++i) cout << d[i] << " \n"[i == n];
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> qs[i].s >> qs[i].t;
        qs[i].l = 1; qs[i].r = INF;
        qs[i].id = i;
    }
    for (int i = 1; i <= 30; ++i) {
        solve();
    }
    for (int i = 1; i <= q; ++i)
        cout << ans[i] << "\n";
}


