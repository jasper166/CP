#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif


const int INF = 1e9 + 5; 
struct Node {
    int id, val;
    Node(int _id, int _val) {
        id = _id;
        val = _val;
    }
    Node() {
        id = 0;
        val = INF;
    }
};

Node merge(Node x, Node y) {
    if (x.val < y.val) return x;
    if (y.val < x.val) return y;
    return Node(min(x.id, y.id), x.val);
}

struct SegmentTree {
    int n;
    vector <int> a;
    vector <Node> f;
    SegmentTree(int _n) : n(_n), a(_n + 5), f(_n * 4 + 5) {};

    void build(int x, int l, int r) {
        if (l == r) {
            f[x] = Node(l, a[l]);
            return;
        }
        int m = (l + r) >> 1;
        build(x << 1, l, m);
        build(x << 1 | 1, m + 1, r);
        f[x] = merge(f[x << 1], f[x << 1 | 1]);
    }

    void upd(int x, int l, int r, int pos, int val) {
        if (l == r) {
            f[x] = Node(l, val);
            return;
        }
        int m = (l + r) >> 1;
        if (pos <= m) upd(x << 1, l, m, pos, val);
        else upd(x << 1 | 1, m + 1, r, pos, val);
        f[x] = merge(f[x << 1], f[x << 1 | 1]);
    }

    Node qry(int x, int l, int r, int u, int v) {
        if (l > v || r < u) return Node();
        if (u <= l && r <= v) return f[x];
        int m = (l + r) >> 1;
        Node ql = qry(x << 1, l, m, u, v);
        Node qr = qry(x << 1 | 1, m + 1, r, u, v);

        // debug(l, r, ql.id, ql.val, qr.id, qr.val);
        return merge(ql, qr);
    }
};



struct Node2 {
    int ans, len, suf, prf;
    int id_ans, id_s, id_p;
    Node2(int _ans, int _len, int _suf, int _prf, int _id) : ans(_ans), len(_len), suf(_suf), prf(_prf), id_ans(_id), id_s(_id), id_p(_id) {};
    Node2() {
        ans = len = suf = prf = 0;
        id_ans = id_s = id_p = -1;
    }
};

Node2 op(Node2 x, Node2 y) {
    Node2 z;

    if (x.id_ans == -1) return y;
    if (y.id_ans == -1) return x;
    z.ans = max({x.ans, y.ans, x.suf + y.prf});
    if (z.ans == x.ans) z.id_ans = x.id_ans;
    if (z.ans == y.ans && z.ans != x.ans) z.id_ans = y.id_ans;
    if (z.ans == x.suf + y.prf) z.id_ans = x.id_s;

    z.prf = (x.prf == x.len)? x.len + y.prf : x.prf;
    z.id_p = (z.prf == x.len + y.prf)? y.id_p : x.id_p;

    z.suf = (y.suf == y.len)? y.len + x.suf : y.suf;
    z.id_s = (z.suf == y.len + x.suf)? x.id_s : y.id_s;

    z.len = x.len + y.len;
    return z;
}
struct SegmentTree2 {
    
    vector <Node2> f;
    vector <int> a;
    SegmentTree2(int _n) : f(_n * 4 + 5), a(_n + 5) {};
 
    void build(int x, int l, int r) {
        if (l == r) {
            int y = (a[l] == 1);
            int id = (a[l] == 1)? l : -1;
            f[x] = Node2(y, 1, y, y, id);
            // debug(x, l, r, f[x].id_ans);
            return;
        }
        int m = (l + r) / 2;
        build(x << 1, l, m);
        build(x << 1 | 1, m + 1, r);
        f[x] = op(f[x << 1], f[x << 1 | 1]);

    }
 
    void upd(int x, int l, int r, int pos, int val) {
        if (l == r) {
            int y = (val == 1);
            int id = (val == 1)? l : -1;
            f[x] = Node2(y, 1, y, y, id);
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m ) upd(x << 1, l, m, pos, val);
        else upd(x << 1 | 1, m + 1, r, pos, val);
        f[x] = op(f[x << 1], f[x << 1 | 1]);
    }
 
    Node2 qry(int x, int l, int r, int u, int v) {
        if (l > v || r < u) {
            return Node2(0, 0, 0, 0, -1);
        }
        if (u <= l && r <= v)
            return f[x];
        int m = (l + r) / 2;
        Node2 ql = qry(x << 1, l, m, u, v);
        Node2 qr = qry(x << 1 | 1, m + 1, r, u, v);

        return op(ql, qr);
    }
};
 

// if any 0s exist -> take whole (l, r)
// take minimum index of min elements
// also with 1111....11 subarray

int n, q;
void run_case() {
    cin >> n >> q;
    SegmentTree st(n);
    SegmentTree2 on(n);
    for (int i = 1; i <= n; ++i) {
        cin >> st.a[i];
        on.a[i] = st.a[i];
    }

    st.build(1, 1, n);
    on.build(1, 1, n);
    // Node2 z = on.qry(1, 1, n, 3, 3);
    // debug(z.ans, z.id_ans, z.id_s, z.id_p);
    for (int i = 1; i <= q; ++i) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        if (cmd == 1) {
            Node ret = st.qry(1, 1, n, x, y);
            // debug(ret.id);
            // check if any 0 exist?
            if (ret.val == 0) {
                cout << 0 << " " << x << " " << y << "\n";
            }// case with 11...111 subarray
            if (ret.val == 1) {
                Node2 z = on.qry(1, 1, n, x, y);
                cout << 1 << " " << z.id_ans << " " << z.id_ans + z.ans - 1 << "\n";
                // debug(z.ans);
            }
            else {
                cout << ret.val << " " << ret.id << " " << ret.id << "\n";
            }
        }
        else {
            st.upd(1, 1, n, x, y);
            on.upd(1, 1, n, x, y);
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

