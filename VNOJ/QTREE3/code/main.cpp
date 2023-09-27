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

using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int n, q;
vector <int> adj[MAX];
int pos[MAX], hvy[MAX], head[MAX];
int sz[MAX], pa[MAX], dep[MAX];
int cnt = 1;

struct SegTree {
    vector <int> st, a;
    int N;
    void init(int _N) {
        N = _N;
        st.assign(N * 2 + 5, INF);
        a.resize(N + 5);
    }
    void upd(int p) {
        p += N;
        // Change color
        st[p] = (st[p] == INF)? p - N : INF;
        for (; p; p >>= 1)
            st[p >> 1] = min(st[p], st[p ^ 1]);
    }

    int qry(int l, int r) {
        int ans = INF;
        for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = min(ans, st[l++]);
            if (r & 1) ans = min(ans, st[--r]);
        }
        return ans;
    }
} st;

void dfs(int u, int p) {
    pa[u] = p;
    dep[u] = dep[p] + 1;
    sz[u] = 1;
    int big = 0;
    for (int v : adj[u]) {
        if (v ^ p) {
            dfs(v, u);
            sz[u] += sz[v];
            if (sz[big] < sz[v]) {
                big = v;
                hvy[u] = v;
            }
        }
    }
}

void hld(int u, int p) {
    pos[u] = cnt;
    head[u] = p;
    st.a[cnt++] = u;
    // Continue;
    for (int v : adj[u]) {
        if (v != pa[u] && v == hvy[u]) {
            hld(v, p);
            break;
        }
    }
    // New chain
    for (int v : adj[u]) {
        if (v != pa[u] && v != hvy[u])
            hld(v, v);
    }
}

int Qry(int x) {
    int ans = INF;
//    debug(x);
    while (head[1] != head[x]) {
        ans = min(ans, st.qry(pos[head[x]], pos[x]));
        x = pa[head[x]];
    }
    if (pos[1] <= pos[x]) ans = min(ans, st.qry(pos[1], pos[x]));
    return (ans == INF? -1 : st.a[ans]);
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
    debug(cnt);
    while (q--) {
        int cmd, x; cin >> cmd >> x;
        if (cmd)
            cout << Qry(x) << "\n";
        else
            st.upd(pos[x]);
    }

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
//    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
