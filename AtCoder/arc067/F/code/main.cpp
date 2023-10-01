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
#define debug(...) 166;
#endif

using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 5e3 + 5;

struct SegmentTree {
    struct Node {
        int m;
        vector <ll> f;
        Node(int _m) {
            m = _m;
            f.assign(m + 5, 0);
        }
        ll sum() { return accumulate(f.begin() + 1, f.begin() + 1 + m, 0ll); }
    };
    int n, m;
    vector <Node> a, f;

    Node merge(Node x, Node y) {
        Node ans(m + 5);
        for (int i = 1; i <= m; ++i)
            ans.f[i] = max(x.f[i], y.f[i]);
        return ans;
    }
    void init(int _n, int _m) {
        n = _n;
        m = _m;
        f.assign(4 * n + 5, Node(m + 5));
        a.assign(n + 5, Node(m + 5));
    }

    void build(int x, int l, int r) {
        if (l > r) return;
        if (l == r) {
            f[x] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(x << 1, l, m);
        build(x << 1 | 1, m + 1, r);
        f[x] = merge(f[x << 1], f[x << 1 | 1]);
    }

    Node get(int x, int lx, int rx, int l, int r) {
//        debug(lx, rx, l, r);
        if (l > rx || r < lx) return Node(m + 5);
        if (l <= lx && rx <= r) return f[x];
        int m = (lx + rx) / 2;
        Node ql = get(x << 1, lx, m, l, r);
        Node qr = get(x << 1 | 1, m + 1, rx, l, r);
        return merge(ql, qr);
    }
    ll qry(int l, int r) {
        Node ans = get(1, 1, n, l, r);
        return ans.sum();
    }
} st;


int n, m;
ll d[MAX];
ll cost(int l, int r) { return d[r] - d[l]; }
ll ans;

void solve(int l, int r, int opt_l, int opt_r) {
    if (l > r) return;
    int m = (l + r) / 2;
    int pos = -1;
    ll best = 0;
    for (int x = opt_l; x <= min(m, opt_r); ++x) {
        ll cur = st.qry(x, m) - cost(x, m);
        if (best < cur) {
            best = cur;
            pos = x;
        }
    }
    ans = max(ans, best);
    solve(l, m - 1, opt_l, pos);
    solve(m + 1, r, pos, opt_r);
}

void run_case() {
    cin >> n >> m;
    for (int i = 2; i <= n; ++i) {
        int x; cin >> x;
        d[i] = d[i - 1] + x;
    }
    st.init(n, m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x; cin >> x;
            st.a[i].f[j] = x;
        }
//        FOR(j, 1, m) { debug(st.a[i].f[j]) }
    }
    st.build(1, 1, n);
    solve(1, n, 1, n);
    cout << ans << "\n";
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
