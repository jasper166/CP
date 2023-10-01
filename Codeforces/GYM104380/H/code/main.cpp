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

/*
    ans : numbers of "01" pairs;
    x : numbers of 0s that not in any "01" pair
    y : numbers of 1s that not in any "01" pair
*/
struct SegmentTree {
    struct Node {
        int ans, x, y;
        Node (int _a, int _x, int _y) : ans(_a), x(_x), y(_y) {};
        Node() {
            ans = x = y = 0;
        }
    };

    vector <int> a;
    vector <Node> f;
    SegmentTree (int _n) : f(_n * 4 + 5), a(_n + 5) {};

    Node merge(Node l, Node r) {
        Node p;
        p.ans = l.ans + r.ans + min(l.x, r.y);
        p.x = l.x + r.x - min(l.x, r.y);
        p.y = l.y + r.y - min(l.x, r.y);
        return p;
    }
    void build(int x, int l, int r) {
        if (l == r) {
            f[x] = {0, a[l] == 0, a[l] == 1};
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
        if (l == r && l == pos) {
            f[x] = {0, val == 0, val == 1};
            return;
        }
        int m = (l + r) >> 1;
        upd(x << 1, l, m, pos, val);
        upd(x << 1 | 1, m + 1, r, pos, val);
        f[x] = merge(f[x << 1], f[x << 1 | 1]);
    }

    Node qry(int x, int l, int r, int u, int v) {
        if (l > v || r < u)
            return {0, 0, 0};
        if (u <= l && r <= v)
            return f[x];
        int m = (l + r) >> 1;
        Node ql = qry(x << 1, l, m, u, v);
        Node qr = qry(x << 1 | 1, m + 1, r, u, v);
        return merge(ql, qr);
    }
};

void run_case() {
    string s; cin >> s;
    int n = s.size();
    s = "@" + s;
    SegmentTree st(n);

    for (int i = 1; i <= n; ++i) {
        st.a[i] = s[i] - '0';
//        debug(s[i]);
    }
    st.build(1, 1, n);

    int q; cin >> q;
    while (q--) {
        int cmd, l, r, x;
        cin >> cmd;
        if (cmd == 1) {
            cin >> x;
            st.upd(1, 1, n, x, st.a[x] ^ 1);
            st.a[x] ^= 1;
        }
        else {
            cin >> l >> r;
            int len = r - l + 1;
            int cnt = st.qry(1, 1, n, l, r).ans;
            cout << len - cnt * 2 << "\n";
        }

    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in2", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
