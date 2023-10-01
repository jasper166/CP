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

struct Node {
    ll sum, ans, prf, suf;
    Node(ll _sum, ll _ans, ll _prf, ll _suf) : sum(_sum), ans(_ans), prf(_prf), suf(_suf) {};
    Node() {
        sum = ans = prf = suf = 0;
    }
};

struct SegmentTree {
    vector <Node> f;
    vector <int> a;
    SegmentTree (int N) : f(N * 4 + 5), a(N + 5) {};

    Node merge(Node x, Node y) {
        Node res;
        res.sum = x.sum + y.sum;
        res.ans = max({0ll, x.ans, y.ans, x.suf + y.prf});
        res.prf = max({0ll, x.prf, x.sum + y.prf});
        res.suf = max({0ll, y.suf, y.sum + x.suf});
        return res;
    }

    void build(int x, int l, int r) {
        if (l == r) {
            int val = a[l];
            f[x] = {val, max(0, val), val, val};
            return;
        }
        int m = (l + r) >> 1;
        build(x << 1, l, m);
        build(x << 1 | 1, m + 1, r);
        f[x] = merge(f[x << 1], f[x << 1 | 1]);
    }

    void upd(int x, int l, int r, int pos, int val) {
        if (pos < l || pos > r)
            return;
        if (l == r && pos == l) {
            f[x] = {val, max(0, val), val, val};
            return;
        }
        int m = (l + r) >> 1;
        upd(x << 1, l, m, pos, val);
        upd(x << 1 | 1, m + 1, r, pos, val);
        f[x] = merge(f[x << 1], f[x << 1 | 1]);
    }

    Node qry(int x, int l, int r, int u, int v) {
        if (l > v || r < u)
            return {0, 0, 0, 0};
        if (u <= l && r <= v)
            return f[x];
        int m = (l + r) >> 1;
        Node ql = qry(x << 1, l, m, u, v);
        Node qr = qry(x << 1 | 1, m + 1, r, u, v);
        return merge(ql, qr);
    }

};

int n, q;
int a[MAX];
void run_case() {
    cin >> n >> q;
    SegmentTree st(n);

    for (int i = 1; i <= n; ++i) cin >> a[i], st.a[i] = a[i];
    st.build(1, 1, n);
    while (q--) {
        int k, val;
        cin >> k >> val;
        st.upd(1, 1, n, k, val);
        a[k] = val;
        Node res = st.qry(1, 1, n, 1, n);
        cout << res.ans << "\n";
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

