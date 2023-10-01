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
const int MAX = 1e5 + 5;
const int LOG = 22;

int n, q;
int dep[MAX], st[MAX];
int timer = 0;
int tree[MAX << 1];
int lg[MAX << 1];
int up[LOG][MAX << 1];
vector <int> adj[MAX];

void dfs(int u, int p) {
    dep[u] = dep[p] + 1;
    tree[++timer] = u;
    st[u] = timer;
    for (int v : adj[u]) {
        if (v ^ p) {
            dfs(v, u);
            tree[++timer] = u;
        }
    }
}

void buildRMQ() {
    lg[1] = 0;
    for (int i = 2; i <= timer; ++i)
        lg[i] = lg[i / 2] + 1;

    for (int i = 1; i <= timer; ++i)
        up[0][i] = tree[i];
    for (int k = 1; k < LOG; ++k) {
        int step = 1 << (k - 1);
        for (int i = 1; i + step <= timer; ++i) {
            up[k][i] = (dep[up[k - 1][i]] < dep[up[k - 1][i + step]]?
                            up[k - 1][i] : up[k - 1][i + step]);
        }
    }
}

int getLCA(int u, int v) {
    int l = st[u], r = st[v];
    if (l > r) swap(l, r);
    int k = lg[r - l + 1];
    return (dep[up[k][l]] < dep[up[k][r - (1 << k) + 1]]? up[k][l] : up[k][r - (1 << k) + 1]);
}


int getDis(int u, int v) {
    int x = getLCA(u, v);
    return dep[u] + dep[v] - 2 * dep[x];
}

// Centroid Decomposition
// nTree: number of current subtree
// sz : size of subtree
// pa : parent of current node in Centroid tree
int nTree;
int sz[MAX], pa[MAX];
bool vis[MAX];

void reSubsize(int u, int p) {
    if (vis[u])
        return;
    ++nTree;
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v ^ p) {
            reSubsize(v, u);
            sz[u] += sz[v];
        }
    }
}

int getCentroid(int u, int p) {
    for (int v : adj[u])
        if (v != p && !vis[v] && sz[v] > nTree / 2)
            return getCentroid(v, u);
    return u;
}

void decompose(int u, int p) {
    nTree = 0;
    reSubsize(u, 0);
    int x = getCentroid(u, 0);
    debug(u, nTree, x);
    // DK pa(u) de loai bo u khoi tap dinh dang xet
    pa[x] = (p == 0)? x : p;
    vis[x] = 1;
    for (int v : adj[x])
        if (!vis[v])
            decompose(v, x);
}

// nearest red vertex in u's subtree
int best[MAX];

void upd(int u) {
    best[u] = 0;
    int v = u;
    // Leo len goc cua cay Centroid
    while (v != pa[v]) {
        v = pa[v];
        best[v] = min(best[v], getDis(v, u));
    }
}

int qry(int u) {
    int v = u;
    // truy van va dong thoi cap nhat ket qua
    while (v != pa[v]) {
        v = pa[v];
        best[u] = min(best[u], best[v] + getDis(u, v));
    }
    return best[u];
}

void run_case() {
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Prepare();
    dfs(1, 0);
    buildRMQ();
    decompose(1, 0);
    for (int i = 1; i <= n; ++i) best[i] = INF;

//    debug(n, q);
    // Update node 1;
    upd(1);
    while (q--) {
        int cmd, u;
        cin >> cmd >> u;
//        debug(cmd, u);
        if (cmd == 1) {
            upd(u);
        }
        else {
            int ans = qry(u);
            cout << ans << "\n";
        }
    }
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
