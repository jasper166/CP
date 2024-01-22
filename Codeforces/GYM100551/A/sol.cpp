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
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 3e5 + 5;

struct DynamicConnectivity {
    struct DSU_rollback {
        vector <int> pa, sz;
        int n, comp;
        stack <int> st;
        void init(int _n) {
            comp = n = _n;
            pa.resize(n + 5);
            sz.assign(n + 5, 1);
            iota(pa.begin(), pa.end(), 0);
            while (!st.empty()) st.pop();
        }
        // No path compression or it would be O(n^2) !!!
        int find(int u) { return (u == pa[u]? u : find(pa[u])); }
        int snap() { return (int) st.size(); }
        bool unite(int u, int v) {
            u = find(u);
            v = find(v);
            if (u == v)
                return 0;
            if (sz[u] < sz[v]) swap(u, v);
            --comp;
            sz[u] += sz[v];
            pa[v] = u;
            st.push(v); // v -> p[v]
            return 1;
        }
        void roblox(int snap) {
            // rollback to snap moment
            while ((int) st.size() > snap) {
                int x = st.top(); st.pop();
                sz[pa[x]] -= sz[x];
                pa[x] = x;
                comp++;
            }
        }
    };
    struct Queries { int typ, u, v; };

    vector <Queries> qs;
    DSU_rollback dsu;
    vector <int> ot, ans;
    map <pair <int, int>, int> mp;
    int n, Q;
    void init(int _n, int _q) {
        n = _n;
        Q = 0;
        dsu.init(_n);
        ot.resize((_q << 1) + 5);
        qs.resize((_q << 1) + 5);
    }
    void add(int u, int v) {
        if (u > v) swap(u, v);
        qs[++Q] = {1, u, v};
        pair <int, int> x = {u, v};
        mp[x] = Q;
    }
    void del(int u, int v) {
        if (u > v) swap(u, v);
        qs[++Q] = {-1, u, v};
        pair <int, int> x = {u, v};
        if (!mp.count(x)) return;
        ot[mp[x]] = Q; ot[Q] = mp[x];
        mp.erase(x);
    }
    void qry() { qs[++Q] = {0, 0, 0}; }
    void dnc(int l, int r) {
        if (l > r) return;
        if (l == r) {
            if (qs[l].typ == 0)
                ans.push_back(dsu.comp);
            return;
        }
        int m = (l + r) >> 1;
        int now = dsu.snap();
        for (int i = m + 1; i <= r; ++i)
            if (ot[i] < l)
                dsu.unite(qs[i].u, qs[i].v);
        dnc(l, m);
        dsu.roblox(now);

        for (int i = m; i >= l; --i)
            if (ot[i] > r)
                dsu.unite(qs[i].u, qs[i].v);
        dnc(m + 1, r);
        dsu.roblox(now);
    }
    void solve() {
        // debug("vcc");
        if (qs.empty()) return;
        for (auto [x, id] : mp) {
            qs[++Q] = {-1, x.first, x.second};
            ot[id] = Q;
            ot[Q] = id;
        }
        dnc(1, Q);
        for (int x : ans) cout << x << "\n";
    }
};  

int n, q;

void run_case() {
    cin >> n >> q;
    DynamicConnectivity dyn;
    dyn.init(n, q);
    for (int i = 1; i <= q; ++i) {
        char cmd; int u, v;
        cin >> cmd;
        if (cmd == '?') {
            dyn.qry();
            continue;
        }
        cin >> u >> v;
        if (cmd == '+') dyn.add(u, v);
        else dyn.del(u, v);
    }
    dyn.solve();
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    // freopen("connect.in", "r", stdin);
    // freopen("connect.out", "w", stdout);

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


