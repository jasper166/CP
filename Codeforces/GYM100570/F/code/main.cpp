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

int n, q;
vector <pii> adj[MAX];
ll dis[MAX];
int dep[MAX];
int tree[MAX << 1], st[MAX];
int timer;

void dfs(int u, int p, int w) {
    dep[u] = dep[p] + 1;
    dis[u] = dis[p] + w;
    tree[++timer] = u;
    st[u] = timer;
    for (auto &[w, v] : adj[u]) {
        if (v != p) {
            dfs(v, u, w);
            tree[++timer] = u;
        }
    }
}

pii up[22][MAX << 1];
int lg[MAX << 1];
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

ll getDis(int u, int v) {
    int c = getLCA(u, v);
    return dis[u] + dis[v] - 2 * dis[c];
}

// Centroid now
int sz[MAX], pa[MAX];
bool vis[MAX];
int Tsize = 0;

void reSubsize(int u, int p) {
    sz[u] = 1;
    for (auto &[w, v] : adj[u]) {
        if (v != p && !vis[v]) {
            reSubsize(v, u);
            sz[u] += sz[v];
        }
    }
}

int getCentroid(int u, int p) {
    for (auto &[w, v] : adj[u]) {
        if (v != p && !vis[v] && sz[v] > Tsize / 2)
            return getCentroid(v, u);
    }
    return u;
}

void decompose(int u, int p) {
    reSubsize(u, 0);
    Tsize = sz[u];
    int x = getCentroid(u, 0);
    vis[x] = 1;
    pa[x] = (p == 0)? x : p;

//    debug(u, p, x);
    for (auto &[w, v] : adj[x])
        if (!vis[v])
            decompose(v, x);
}

vector <ll> cnt[MAX], cnt_p[MAX];
// cnt(u) : set of distance of (x, u) in u's subtree
// cnt_p(u) : set of distance of (x, p(u)) in u's subtree
void prepare() {

    for (int i = 1; i <= n; ++i) {
        int u = i;
        // To itself
        while (1) {
            cnt[u].push_back(getDis(u, i));
            if (u == pa[u]) break;
            u = pa[u];
        }
    }

    for (int i = 1; i <= n; ++i) {
        int u = i;
        while (u != pa[u]) {
            cnt_p[u].push_back(getDis(pa[u], i));
            u = pa[u];
        }
    }

    for (int i = 1; i <= n; ++i) {
        sort(cnt[i].begin(), cnt[i].end());
        sort(cnt_p[i].begin(), cnt_p[i].end());
    }
}

ll qry(int u, ll l) {
    ll ans = upper_bound(cnt[u].begin(), cnt[u].end(), l) - cnt[u].begin();
    int v = u;
    while (v != pa[v]) {
        ll d = l - getDis(u, pa[v]);
        ll total = upper_bound(cnt[pa[v]].begin(), cnt[pa[v]].end(), d) - cnt[pa[v]].begin();
        ll sub = upper_bound(cnt_p[v].begin(), cnt_p[v].end(), d) - cnt_p[v].begin();
        ans += total - sub;
        v = pa[v];
    }
    return ans;
}

void run_case() {
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

//    vector <int> v = {1, 1, 2, 3, 5, 5, 6};
//    debug(ans);
    dfs(1, 0, 0);
    buildRMQ();
    decompose(1, 0);
    prepare();

    while (q--) {
        int u; ll l;
        cin >> u >> l;
        cout << qry(u, l) << "\n";
    }
//    debug(getLCA(2, 2));
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in2", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
