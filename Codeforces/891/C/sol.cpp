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
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 5e5 + 5;

struct DSU_rollback {
    vector <int> pa, sz;
    int n, comp;
    stack <int> st;

    void init(int _n) {
        comp = n = _n;
        pa.resize(n + 5);
        sz.assign(n + 5, 1);
        iota(pa.begin(), pa.end(), 0);
        while (!st.empty()) st.pop();
    }
    // No path compression or it would be O(n^2) !!!
    int find(int u) { return (u == pa[u]? u : find(pa[u])); }
    bool same_set(int u, int v) { return (find(u) == find(v)); }
    int snap() { return st.size(); }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return 0;
        if (sz[u] < sz[v]) swap(u, v);
        --comp;
        sz[u] += sz[v];
        pa[v] = u;
        // v -> p[v]
        st.push(v);
        return 1;
    }
    void roblox(int snap) {
        // rollback to snap moment
        while ((int) st.size() > snap) {
            int x = st.top(); st.pop();
            sz[pa[x]] -= sz[x];
            pa[x] = x;
            comp++;
        }
    }
} dsu;

struct Edge {
    int u, v, w;
} ed[N];
int n, m, q;
vector <int> edges[N];
// edges[x] : {index of edges having weight = x}
int ans[N];
map <int, vector <int>> qs[N];
// qs[x] : <index i of queries having some edges weighted = x, 
// index of edges belong to that query>

void run_case() {
    cin >> n >> m;
    dsu.init(n);

    for (int i = 1; i <= m; ++i) {
        int u, v, w; 
        cin >> u >> v >> w;
        ed[i] = {u, v, w};
        edges[w].push_back(i);
    }

    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int k; cin >> k;
        for (int j = 1; j <= k; ++j) {
            int id; cin >> id;
            qs[ed[id].w][i].push_back(id);
        }
    }

    // O(Q * logn + M + Q)
    for (int x = 1; x < N; ++x) {
        // Try uniting all edges weighted x in same query
        for (auto& [id, v] : qs[x]) {
            int now = dsu.snap();
            // Saving current state
            for (int j : v) {
                if (dsu.unite(ed[j].u, ed[j].v) == false)
                    ans[id] = -1;
                /* ans = NO when
                 1. (u, v) already in MST not using any edges weighted x
                 2. (u, v) already in MST using some edges weighted x
                 */
            }
            // rollback for next query
            dsu.roblox(now);
        }    
        // building MST normally
        for (int j : edges[x])
            dsu.unite(ed[j].u, ed[j].v);
    }

    for (int i = 1; i <= q; ++i)
        cout << (ans[i] == -1? "NO\n" : "YES\n");
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


