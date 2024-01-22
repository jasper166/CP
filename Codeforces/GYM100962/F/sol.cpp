#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 2e5 + 5;
const int K = 18;
const int BLOCK = 397;

int n, q;
vector <pair <int, int>> adj[N];
int tin[N], tout[N];
pair <int, int> tr[N << 1];
int timer = 0;
int dep[N];
int st[N], lg[N << 1], tree[N << 1];
int up[K][N << 1];

void dfs(int u, int p) {
    dep[u] = dep[p] + 1;
    st[u] = ++timer;
    tree[timer] = u;
    for (auto [v, x] : adj[u]) {
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
    for (int k = 1; k < K; ++k) {
        int step = 1 << (k - 1);
        for (int i = 1; i + step <= timer; ++i) {
            up[k][i] = (dep[up[k - 1][i]] < dep[up[k - 1][i + step]]?
                            up[k - 1][i] : up[k - 1][i + step]);
        }
    }
}
int lca(int u, int v) {
    int l = st[u], r = st[v];
    if (l > r) swap(l, r);
    int k = lg[r - l + 1];
    return (dep[up[k][l]] < dep[up[k][r - (1 << k) + 1]]? up[k][l] : up[k][r - (1 << k) + 1]);
}

void dfs(int u, int x, int p) {
    tin[u] = ++timer;
    tr[timer] = {u, x};
    for (auto [v, y] : adj[u]) {
        if (v ^ p) {
            dfs(v, y, u);
        }
    }
    tout[u] = ++timer;
    tr[timer] = {u, x};
}

struct Queries {
    int l, r, id;
    bool operator < (const Queries &ot) const {
        if (l / BLOCK == ot.l / BLOCK)
            return (l / BLOCK & 1)? r < ot.r : r > ot.r;
        else 
            return (l / BLOCK < ot.l / BLOCK);
    }
} qs[N];

bool vis[N];
int ans[N], mex = 0;
int has[N], f[N];

void add(int i) {
    auto [u, x] = tr[i];
    if (x > n) return;
    vis[u] ^= 1;
    if (vis[u]) {
        has[x]++;
        if (has[x] == 1) f[x / BLOCK]++;
    }
    else {
        has[x]--;
        if (has[x] == 0) f[x / BLOCK]--;
    }
}
void del(int i) {
    auto [u, x] = tr[i];
    if (x > n) return;
    vis[u] ^= 1;
    if (vis[u]) {
        has[x]++;
        if (has[x] == 1) f[x / BLOCK]++;
    }
    else {
        has[x]--;
        if (has[x] == 0) f[x / BLOCK]--;
    }
}
int get() {
    int mex = 0;
    for (int x = 0; x <= BLOCK; x++) {
        if (f[x] != BLOCK) {
            mex = x * BLOCK;
            while (has[mex]) ++mex;
            break;
        }
    }
    return mex;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        // debug(u, v, x);
        adj[u].emplace_back(v, x);
        adj[v].emplace_back(u, x);
    }

    dfs(1, 1e9, 0);
    timer = 0;
    dfs(1, 0);
    buildRMQ();
    // debug(lca(1, 3))
    for (int i = 1; i <= q; ++i) {
        int u, v; 
        cin >> u >> v;
        if (tin[u] > tin[v]) swap(u, v);
        int p = lca(u, v);
        int L, R;
        if (p == u) {
            L = tin[u] + 1;
            R = tin[v];
        }
        else {
            L = tout[u];
            R = tin[v];
        }
        // debug(L, R, p);
        qs[i] = {L, R, i};
    }
    sort(qs + 1, qs + 1 + q);
    int l = 1, r = 0;
    for (int i = 1; i <= q; ++i) {
        auto [L, R, id] = qs[i];

        while (l > L) add(--l);
        while (r < R) add(++r);
        while (l < L) del(l++);
        while (r > R) del(r--);

        ans[id] = get();
    }
    // MEX only in range [0, n + 1];
    for (int i = 1; i <= q; ++i)
        cout << ans[i] << "\n";
}
