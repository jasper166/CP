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
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int n, q, A, B;
int c[MAX];

struct BIT {
    vector <int> f;
    int N;
    void init(int _N) {
        N = _N;
        f.assign(N + 5, 0);
    }
    void upd(int x, int val) {
        for (; x <= N; x += x & -x) f[x] += val;
    }
    int qry(int x) {
        int ans = 0;
        for (; x > 0; x -= x & -x) ans += f[x];
        return ans;
    }

    int qry(int l, int r) {
        return qry(r) - qry(l - 1);
    }
} bit;

struct SegTree {
    struct Node {
        int val, lzy;
        Node() {
            val = lzy = 0;
        }
    };
    vector <Node> f;
    vector <int> a;
    void init(int N) {
        a.resize(N + 5);
        f.resize(N * 4 + 5);
    }

    void push(int x) {
        int w = f[x].lzy;
        if (w) {
            f[x << 1].lzy += w;
            f[x << 1].val += w;
            f[x << 1 | 1].lzy += w;
            f[x << 1 | 1].val += w;
            f[x].lzy = 0;
        }
    }

    void build(int x, int l, int r) {
        if (l > r) return;
        f[x].lzy = 0;
        if (l == r) {
            f[x].val = A * a[l] + B;
            return;
        }
        int m = (l + r) >> 1;
        build(x << 1, l, m);
        build(x << 1 | 1, m + 1, r);
        f[x].val = max(f[x << 1].val, f[x << 1 | 1].val);
    }

    void upd(int x, int l, int r, int u, int v, int val) {
        if (v < l || u > r)
            return;
        if (u <= l && r <= v) {
            f[x].lzy += val;
            f[x].val += val;
            return;
        }
        push(x);
        int m = (l + r) >> 1;
        upd(x << 1, l, m, u, v, val);
        upd(x << 1 | 1, m + 1, r, u, v, val);
        f[x].val = max(f[x << 1].val, f[x << 1 | 1].val);
    }

} st;

int dep[MAX], sz[MAX], pa[MAX];
int pos[MAX], hvy[MAX], head[MAX];
int cnt;
vector <int> adj[MAX];

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
                hvy[u] = v;
                nxt = v;
            }
        }
    }
}

void hld(int u, int p) {
    head[u] = p;
    pos[u] = ++cnt;
    st.a[cnt] = c[u];
//    debug(cnt, u, c[u]);
    for (int v : adj[u]) {
        if (v != pa[u] && v == hvy[u]) {
            hld(v, p);
            break;
        }
    }
    // new chain
    for (int v : adj[u]) {
        if (v != pa[u] && v != hvy[u])
            hld(v, v);
    }
}

int qry(int x, int l, int r) {
    if (st.f[x].val < 0)
        return -1;
    if (l == r)
        return l;
    st.push(x);
    int m = (l + r) >> 1;
    int ans = qry(x << 1, l, m);
    if (ans != -1)
        return ans;
    return qry(x << 1 | 1, m + 1, r);
}


void hld_upd(int u, int v, int w) {
    while (head[u] != head[v]) {
        if (dep[head[u]] < dep[head[v]]) swap(u, v);
        st.upd(1, 1, n, pos[head[u]], pos[u], w);
        u = pa[head[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    st.upd(1, 1, n, pos[u], pos[v], w);
}

int hld_qry(int u, int v) {
    int ans = 0;
    while (head[u] != head[v]) {
        if (dep[head[u]] < dep[head[v]]) swap(u, v);
        ans += bit.qry(pos[head[u]], pos[u]);
        u = pa[head[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    ans += bit.qry(pos[u], pos[v]);
    return ans;
}

void run_case() {
    cin >> n >> q >> A >> B;
    debug(n, q, A, B);
    cnt = 0;
    bit.init(n);
    st.init(n);
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }

    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1);
    hld(1, 1);
    st.build(1, 1, n);

    while (q--) {
        int cmd, u, v, w;
        cin >> cmd >> u >> v;
        if (cmd == 1) {
            cin >> w;
            hld_upd(u, v, w * A);
        }
        else {
            while (1) {
                int p = qry(1, 1, n);
                if (p == -1) break;
                bit.upd(p, 1);
                st.upd(1, 1, n, p, p, -LINF);
            }
            int ans = hld_qry(u, v);
            cout << ans << "\n";
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
