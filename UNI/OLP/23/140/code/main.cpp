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

struct SegmentTree {
    struct Node {
        ll ans, sum, prf, suf;
        Node() { ans = sum = prf = suf = 0; }
        Node(ll a, ll b, ll c, ll d): ans(a), sum(b), prf(c), suf(d) {};
    };
    vector <Node> f;
    vector <int> a;
    int n;
    SegmentTree (int N) : n(N), f(4 * N + 5, Node()), a(N + 5) {};
    Node merge(Node l, Node r) {
        Node x;
        x.sum = l.sum + r.sum;
        x.prf = max(l.prf, l.sum + r.prf);
        x.suf = max(r.suf, r.sum + l.suf);
        x.ans = max({l.ans, r.ans, l.suf + r.prf});
        return x;
    }

    void build(int x, int l, int r) {
        if (l == r) {
            f[x] = {a[l], a[l], a[l], a[l]};
            return;
        }
        int m = (l + r) >> 1;
        build(x << 1, l, m);
        build(x << 1 | 1, m + 1, r);
        f[x] = merge(f[x << 1], f[x << 1 | 1]);
    }

    void upd(int x, int l, int r, int pos, int val) {
        if (l == r && l == pos) {
            f[x] = {val, val, val, val};
            return;
        }
        int m = (l + r) >> 1;
        if (pos <= m)
            upd(x << 1, l, m, pos, val);
        else
            upd(x << 1 | 1, m + 1, r, pos, val);
        f[x] = merge(f[x << 1], f[x << 1 | 1]);
    }
    Node qry(int x, int l, int r, int L, int R) {
        if (L <= l && r <= R) return f[x];
        int m = (l + r) >> 1;
        if (R <= m) return qry(x << 1, l, m, L, R);
        if (m < L) return qry(x << 1 | 1, m + 1, r, L, R);
        return merge(qry(x << 1, l, m, L, R), qry(x << 1 | 1, m + 1, r, L, R));
    }
    void upd(int pos, int val) { upd(1, 1, n, pos, val); }
    ll qry(int l, int r) { return qry(1, 1, n, l, r).ans; }
};
int n, q;
void run_case() {
    cin >> n >> q;
    SegmentTree st(n);
    for (int i = 1; i <= n; ++i) cin >> st.a[i];
    st.build(1, 1, n);
    while (q--) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        if (cmd)
            cout << st.qry(x, y) << "\n";
        else
            st.upd(x, y);
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
