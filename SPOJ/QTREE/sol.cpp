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
const int MAX = 1e4 + 5;

struct SegTree {
    vector <int> f, a;
    void init(int N) {
        f.assign(4 * N + 5, -INF);
        a.assign(N + 5, 0);
    }
    void merge(int x) {
        f[x] = max(f[x << 1], f[x << 1 | 1]);
    }
    void build(int x, int l, int r) {
        if (l + 1 == r) {
            f[x] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(x << 1, l, m);
        build(x << 1 | 1, m, r);
        merge(x);
    }
    void upd(int x, int l, int r, int pos, int val) {
        if (l > pos || r <= pos)
            return;
        if (l == pos && l + 1 == r) {
            f[x] = val;
            return;
        }
        int m = (l + r) >> 1;
        if (pos < m)
            upd(x << 1, l, m, pos, val);
        else 
            upd(x << 1 | 1, m, r, pos, val);
        merge(x);
    }

    int qry(int x, int l, int r, int u, int v) {
        if (l >= v || r <= u)
            return -INF;
        if (u <= l && r <= v)
            return f[x];
        int m = (l + r) >> 1;
        int ql = qry(x << 1, l, m, u, v);
        int qr = qry(x << 1 | 1, m, r, u, v);
        return max(ql, qr);
    }


} st;


// HLD
int n;
vector <pii> adj[MAX];
int pa[MAX], dep[MAX], sz[MAX];
// Heavy vertex of u
int hvy[MAX];
// Head vertex of the ith chain
int head[MAX];
// Pos of u in its chain
int pos[MAX];
// Flattening the tree;
int cnt = 1;
void dfs(int u, int p) {
    pa[u] = p;
    dep[u] = dep[p] + 1;
    sz[u] = 1;
    int nxt = 0;
    for (auto &[w, v] : adj[u]) {
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

void hld(int u, int p, int W) {
    head[u] = p;
    pos[u] = cnt;
    st.a[cnt++] = W;
    // Continue the chain from u to its heavy son
    for (auto &[w, v]: adj[u]) {
        if (v == hvy[u] && v != pa[u]) {
            hld(v, p, w);
            break;
        }
    }
    // Create new chains from u's light sons
    for (auto &[w, v] : adj[u]) {
        if (v != hvy[u] && v != pa[u]) {
            hld(v, v, w);
        }
    }
}
// Query
vector <pii> e;
int Qry(int u, int v) {
    // debug(head[u], head[v]);
    int ans = -INF;
    //Neu ko cung chain
    while (head[u] != head[v]) {
        // Coi dinh v la dinh sau nhat giua u, v
        if (dep[head[u]] > dep[head[v]]) swap(u, v);
        ans = max(ans, st.qry(1, 1, n + 1, pos[head[v]], pos[v] + 1));
        // Nhay len cha cua dinh head;
        v = pa[head[v]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    if (pos[u] < pos[v]) ans = max(ans, st.qry(1, 1, n + 1, pos[u] + 1, pos[v] + 1));
    return ans;
}
// Update edge
void Upd(int i, int w) {
    auto [u, v] = e[i]; 
    // debug(u, v);
    int x = dep[u] > dep[v]? u : v;
    st.upd(1, 1, n + 1, pos[x], w);
}

void run_case() {
    cin >> n;
    cnt = 1;
    e.clear();
    st.init(n + 5);
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        dep[i] = pos[i] = head[i] = hvy[i] = pa[i] = sz[i] = 0;
    }
    // debug(n);
    for (int i = 1; i < n; ++i) {
        int u, v, w; cin >> u >> v >> w;
        // debug(u, v, w);
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
        e.push_back({u, v});
    }
    dfs(1, 0);
    hld(1, 0, -INF);
    st.build(1, 1, n + 1);
    string s;
    while (cin >> s) {
        if (s[0] == 'D') break;
        if (s[0] == 'Q') {
            int u, v; cin >> u >> v;
            // debug(s, u, v);
            cout << Qry(u, v) << "\n";
            // cout << st.qry(1, 1, n, u, v) << "\n";
        }
        if (s[0] == 'C') {
            int i, w; cin >> i >> w;
            // debug(s, i, w);
            Upd(i - 1, w);
            // st.upd(1, 1, n, i, w);
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


