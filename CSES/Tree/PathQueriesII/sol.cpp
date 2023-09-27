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
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;    

int n, q;
vector <int> adj[MAX];
int a[MAX];

int st[MAX << 1];
int merge(int x, int y) {return max(x, y);}

void upd(int x, int val) {
    st[x += n] = val;
    for (x >>= 1; x; x >>= 1)
        st[x] = merge(st[x << 1], st[x << 1 | 1]);
}

int qry(int l, int r) {
    int ql = 0, qr = 0;
    // interval [L, R);
    // r += n = open, r += n + 1 = close;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ql = merge(ql, st[l++]);
        if (r & 1) qr = merge(st[--r], qr);
    }
    return merge(ql, qr);
}

int hvy[MAX], pa[MAX], sz[MAX], dep[MAX], head[MAX];
int pos[MAX];
int cnt = 0;

void dfs(int u, int p) {
    sz[u] = 1;
    dep[u] = dep[p] + 1;
    pa[u] = p;
    int nxt = 0;
    for (int v : adj[u]) {
        if (v ^ p) {
            dfs(v, u);
            sz[u] += sz[v];
            if (sz[nxt] < sz[v]) {
                nxt = v;
                hvy[u] = v;
            }
        }
    }
}

void hld(int u, int p) {
    pos[u] = ++cnt;
    head[u] = p;
    upd(pos[u], a[u]);
    // Continue from heavy son;
    for (int v : adj[u]) {
        if (v == hvy[u] && v != pa[u])
            hld(v, p);
    }
    // Make new chain
    for (int v : adj[u]) {
        if (v != hvy[u] && v != pa[u]) 
            hld(v, v);
    }
}


int Qry(int u, int v) {
    int ans = -INF;
    while (head[u] != head[v]) {
        if (dep[head[u]] > dep[head[v]]) swap(u, v);
        ans = max(ans, qry(pos[head[v]], pos[v]));
        v = pa[head[v]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    if (pos[u] <= pos[v]) ans = max(ans, qry(pos[u], pos[v]));
    return ans;
}

void run_case() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    hld(1, 1);
    // build(cnt);
    while (q--) {
        int cmd, x, y; cin >> cmd >> x >> y;
        if (cmd == 1) {
            a[x] = y;
            upd(pos[x], a[x]);
        }
        else {
            int ans = Qry(x, y);
            cout << ans << " ";
        }
    }

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


