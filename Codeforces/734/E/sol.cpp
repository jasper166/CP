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
    int n;
    vector <int> pa, sz;
    DisjointSets(int _n) {
        n = _n; 
        pa.resize(_n + 5); 
        sz.resize(_n + 5);
        for (int i = 1; i <= n; ++i) pa[i] = i, sz[i] = 1;
    }
    int get(int u) { return (u == pa[u]? u : pa[u] = get(pa[u])); }
    
    int size(int x) { return sz[get(x)]; }   
    
    bool same_set(int u, int v) { return (get(u) == get(v)); }

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
int c[N];
vector <int> adj[N], gra[N];
int d[2][N];
bool vis[N];

void dfs(int u) {
    vector <int> sub_tree;
    vis[u] = 1;
    // debug(u);
    for (int v : gra[u]) {
        if (!vis[v]) {
            dfs(v);
            sub_tree.push_back(d[0][v]);
        }
    }
    if (sub_tree.empty()) {
        d[0][u] = 0;
        return;
    }
    int d1 = -1, d2 = -1;
    for (int x : sub_tree) {
        if (d1 < x) {
            d2 = d1;
            d1 = x;
        }
        else if (d2 < x)
            d2 = x;
    }
    if (d1 != -1) 
        d[0][u] = max(d[0][u], 1 + d1);
    if (d1 != -1 && d2 != -1)
        d[1][u] = max(d[1][u], 2 + d1 + d2);
}


void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // compress tree
    DisjointSets dsu(n);
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            if (c[v] == c[u])
                dsu.unite(u, v);
        }
    }

    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            if (!dsu.same_set(u, v)) {
                int U = dsu.get(u); int V = dsu.get(v);
                // debug(U, V);
                gra[U].push_back(V);
                gra[V].push_back(U);
            }
        }
    }
    /*
        Diameter d of compressed tree cannot be decreased more than 2
        after one operation
        -> ans >= (d + 1) / 2;
        Choose vertex x with shortest path to any nodes wont exceed (d + 1) / 2.
        Painting x (d + 1) / 2 times would make tree in one color 
        (As reaching the furthest node from x would take distance of (d + 1) / 2).
        -> ans always can be minimized to (d + 1) / 2.
    */
    dfs(dsu.get(1));
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        // debug(d[0][i], d[1][i]);
        int x = dsu.get(i);
        ans = max(ans, max(d[0][x], d[1][x]));
    }
    cout << (ans + 1) / 2 << "\n";
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
