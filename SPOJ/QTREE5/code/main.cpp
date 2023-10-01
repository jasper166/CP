
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

int n;
vector <int> adj[MAX];
pii up[22][MAX << 1];
int dep[MAX], st[MAX];
int tree[MAX << 1], lg[MAX << 1];
int timer;

void dfs(int u, int p) {
    tree[++timer] = u;
    st[u] = timer;
    dep[u] = dep[p] + 1;
    for (int v : adj[u]) {
        if (v != p) {
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
        up[0][i] = make_pair(dep[tree[i]], tree[i]);
    for (int k = 1; k < 22; ++k) {
        int step = 1 << (k - 1);
        for (int i = 1; i + step <= timer; ++i)
            up[k][i] = min(up[k - 1][i], up[k - 1][i + step]);
    }
}


int getLCA(int u, int v) {
    int l = st[u], r = st[v];
    if (l > r) swap(l, r);
    int k = lg[r - l + 1];
    return min(up[k][l], up[k][r - (1 << k) + 1]).se;
}

int getDis(int u, int v) {
    int x = getLCA(u, v);
//    debug(u, v, x);
    return dep[u] + dep[v] - 2 * dep[x];
}

// Centroid
int sz[MAX];
bool vis[MAX];
int Tsize;
void reSubsize(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !vis[v]) {
            reSubsize(v, u);
            sz[u] += sz[v];
        }
    }
}

int getCentroid(int u, int p) {
    for (int v : adj[u]) {
        if (v != p && !vis[v] && sz[v] > Tsize / 2)
            return getCentroid(v, u);
    }
    return u;
}

int pa[MAX];
void decompose(int u, int p) {
    reSubsize(u, 0);
    Tsize = sz[u];
    int x = getCentroid(u, 0);

    pa[x] = (p == 0)? x : p;
    vis[x] = 1;
    for (int v : adj[x])
        if (!vis[v])
            decompose(v, x);
}

multiset <int> best[MAX];
int color[MAX];
void upd(int u) {
    // White to black -> Remove, black to white -> Add;
    int v = u;
    if (color[u])
        best[u].erase(best[u].lower_bound(0));
    else
        best[u].insert(0);

    while (v != pa[v]) {
        v = pa[v];
        if (color[u])
            best[v].erase(best[v].lower_bound(getDis(u, v)));
        else
            best[v].insert(getDis(u, v));
    }
    color[u] ^= 1;
}

int qry(int u) {
    int ans = best[u].empty()? INF : *best[u].begin();
    int v = u;
    while (v != pa[v]) {
        v = pa[v];
        int best_v = best[v].empty()? INF : *best[v].begin();
        ans = min(ans, best_v + getDis(u, v));
    }
    return ans;
}
int q;
void run_case() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    buildRMQ();
    decompose(1, 0);
    cin >> q;
    while (q--) {
        int cmd, u;
        cin >> cmd >> u;
        if (cmd) {
            int ans = qry(u);
            if (ans == INF) ans = -1;
            cout << ans << "\n";
        }
        else
            upd(u);
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
