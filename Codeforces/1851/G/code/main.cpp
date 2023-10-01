#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

struct DisjoinSets {
    vector <int> sz, pa;
    int n;
    DisjoinSets (int N) {
        n = N;
        sz.resize(N + 5);
        pa.resize(N + 5);
        for (int i = 1; i <= N; ++i) {
            sz[i] = 1;
            pa[i] = i;
        }
    }
    int find(int u) { return (u == pa[u]? u : pa[u] = find(pa[u])); }
    bool sameSet(int u, int v) { return find(u) == find(v); }
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

int n, m, q;
vector <int> adj[MAX];
// adj(u) : set of v such h(v) <= h(u)
int h[MAX];
pii entries[MAX];
struct Query {
    int u, v, w, id;
    bool operator < (const Query &x) const{
        return (w < x.w);
    }
} queries[MAX];

void run_case() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }

    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        entries[i] = {h[i], i};
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        queries[i] = {a, b, w + h[a], i};
    }

    sort(entries + 1, entries + 1 + n);
    sort(queries + 1, queries + 1 + q);

    vector <string> ans(q + 5);
    DisjoinSets dsu(n);
    int j = 1;
    for (int i = 1; i <= q; ++i) {
        auto [u, v, w, id] = queries[i];
        while (j <= n && entries[j].fi <= w) {
            for (int t : adj[entries[j].se])
                if (h[t] <= h[entries[j].se])
                    dsu.unite(t, entries[j].se);
            ++j;
        }
        ans[id] = (dsu.sameSet(u, v)? "YES" : "NO");
    }
    for (int i = 1; i <= q; ++i)
        cout << ans[i] << "\n";
    cout << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
