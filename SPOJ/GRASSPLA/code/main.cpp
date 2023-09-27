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

#define int long long
using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int n, q;
vector <int> adj[MAX];
int dep[MAX], sz[MAX], pa[MAX];
int head[MAX], pos[MAX], big[MAX];
int cnt;

struct SegTree {
    struct Node {
        int val, lzy;
        Node() {
            val = lzy = 0;
        }
    };
    vector <Node> f;
    vector <pii> a;
    int N;
    void init(int _N) {
        N = _N;
        f.resize(N * 4 + 5);
        a.resize(N + 5);
    }
    void push(int x) {
        int w = f[x].lzy;
        if (w) {
            f[x << 1].val += w;
            f[x << 1 | 1].val += w;

            f[x << 1].lzy += w;
            f[x << 1 | 1].lzy += w;

            f[x].lzy = 0;
        }
    }
    void upd(int x, int l, int r, int u, int v, int val) {
        if (l > v || r < u)
            return;
        if (u <= l && r <= v) {
            f[x].val += val;
            f[x].lzy += val;
            return;
        }
        push(x);
        int m = (l + r) / 2;
        upd(x << 1, l, m, u, v, val);
        upd(x << 1 | 1, m + 1, r, u, v, val);
        f[x].val = f[x << 1].val + f[x << 1 | 1].val;
    }

    int qry(int x, int l, int r, int u, int v) {
        if (l > v || r < u)
            return 0;
        if (u <= l && r <= v)
            return f[x].val;
        push(x);
        int m = (l + r) / 2;
        int res = 0;
        res += qry(x << 1, l, m, u, v);
        res += qry(x << 1 | 1, m + 1, r, u, v);
        return res;
    }
} st;


void dfs(int u, int p) {
    sz[u] = 1;
    pa[u] = p;
    dep[u] = dep[p] + 1;
    int nxt = 0;
    for (int v : adj[u]) {
        if (v ^ p) {
            dfs(v, u);
            sz[u] += sz[v];
            if (sz[nxt] < sz[v]) {
                nxt = v;
                big[u] = v;
            }
        }
    }
}

void hld(int u, int p) {
    pos[u] = ++cnt;
    head[u] = p;
    st.a[cnt] = {u, p};
    // Current chain
    for (int v : adj[u]) {
        if (v != pa[u] && v == big[u]) {
            hld(v, p);
            break;
        }
    }
    // New chain
    for (int v : adj[u]) {
        if (v != pa[u] && v != big[u])
            hld(v, v);
    }
}

void hld_upd(int u, int v) {
//    debug(u, v, head[u], head[v]);
    while (head[u] != head[v]) {
        if (dep[head[u]] < dep[head[v]]) swap(u, v);
        st.upd(1, 1, n, pos[head[u]], pos[u], 1);
        u = pa[head[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    st.upd(1, 1, n, pos[u] + 1, pos[v], 1);
}

int hld_qry(int u, int v) {
    int ans = 0;
    while (head[u] != head[v]) {
        if (dep[head[u]] < dep[head[v]]) swap(u, v);
        ans += st.qry(1, 1, n, pos[head[u]], pos[u]);
        u = pa[head[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    ans += st.qry(1, 1, n, pos[u] + 1, pos[v]);
    return ans;
}

void run_case() {
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    st.init(n);
    dfs(1, 0);
    hld(1, 0);
    while (q--) {
        char cmd;
        int u, v;
        cin >> cmd >> u >> v;
        if (cmd == 'P') {
            hld_upd(u, v);
        }
        else {
//            debug(u, v);
            int ans = hld_qry(u, v);
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
//    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
