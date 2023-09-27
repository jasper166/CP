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
const int MAX = 2e5 + 5;

struct SegmentTree {
    struct Node {
        int ans, len, suf, prf;
        Node(int _ans, int _len, int _suf, int _prf) : ans(_ans), len(_len), suf(_suf), prf(_prf) {};
        Node() {
            ans = len = suf = prf = 0;
        }
    };
    vector <Node> f;
    vector <int> a;
    SegmentTree(int _n) : f(_n * 4 + 5), a(_n + 5) {};

    Node merge(Node x, Node y) {
        Node z;
        z.ans = max({x.ans, y.ans, x.suf + y.prf});
        z.prf = (x.prf == x.len)? x.prf + y.prf : x.prf;
        z.suf = (y.suf == y.len)? x.suf + y.suf : y.suf;
        z.len = x.len + y.len;
        return z;
    }

    void build(int x, int l, int r, int t) {
        if (l == r) {
            int y = (t)? (a[l] == 1) : (a[l] == 0);
            f[x] = {y, 1, y, y};
            return;
        }
        int m = (l + r) / 2;
        build(x << 1, l, m, t);
        build(x << 1 | 1, m + 1, r, t);
        f[x] = merge(f[x << 1], f[x << 1 | 1]);
    }

    void upd(int x, int l, int r, int pos, int val, int t) {
        if (pos < l || pos > r)
            return;
        if (l == r && l == pos) {
            int y = (t)? (val == 1) : (val == 0);
            f[x] = {y, 1, y, y};
            return;
        }
        int m = (l + r) / 2;
        upd(x << 1, l, m, pos, val, t);
        upd(x << 1 | 1, m + 1, r, pos, val, t);
        f[x] = merge(f[x << 1], f[x << 1 | 1]);
    }

    Node qry(int x, int l, int r, int u, int v) {
        if (l > v || r < u)
            return {0, 0, 0, 0};
        if (l <= u && v <= r)
            return f[x];
        int m = (l + r) / 2;
        Node ql = qry(x << 1, l, m, u, v);
        Node qr = qry(x << 1 | 1, m + 1, r, u, v);
        return merge(ql, qr);
    }
};

void run_case() {
    string s; cin >> s;
    int n = s.size();
    s = "@" + s;
    SegmentTree st1(n), st0(n);
    for (int i = 1; i <= n; ++i) st1.a[i] = st0.a[i] = s[i] - '0';

//    FOR(i, 1, n) {
//        debug(st0.a[i], st1.a[i]);
//    }
    st0.build(1, 1, n, 0);
    st1.build(1, 1, n, 1);

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        st0.upd(1, 1, n, x, st0.a[x] ^ 1, 0);
        st0.a[x] ^= 1;
        st1.upd(1, 1, n, x, st1.a[x] ^ 1, 1);
        st1.a[x] ^= 1;
        int on = st0.qry(1, 1, n, 1, n).ans;
        int ze = st1.qry(1, 1, n, 1, n).ans;
        cout << max(on, ze) << " ";
    }
    cout << "\n";
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
