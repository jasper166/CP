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
const int N = 1e6 + 5;


struct SegmentTree {
    struct Node {
        int r[3];
        int val, lzy;
        Node() {
            r[0] = r[1] = r[2] = val = lzy = 0;
        }
    };
    vector <Node> f;
    vector <int> a;
    int n;
    SegmentTree(int _n) {
        f.resize(_n * 4 + 5);
        a.assign(n + 5, 0);
        n = _n;
    }

    void merge(int x) {
        for (int i = 0; i < 3; ++i)
            f[x].r[i] = f[x << 1].r[i] + f[x << 1 | 1].r[i];
    }

    void push(int x, int l, int r) {
        if (!f[x].lzy) return;
        int time = f[x].lzy % 3;
        for (int k = 1; k <= time; ++k) {
            int z = f[x].r[2];
            f[x].r[2] = f[x].r[1];
            f[x].r[1] = f[x].r[0];
            f[x].r[0] = z;
        }
        if (l < r) {
            (f[x << 1].lzy += time);
            (f[x << 1 | 1].lzy += time);
        }
        f[x].lzy = 0;
    }

    void build(int x, int lx, int rx) {
        if (lx == rx) {
            f[x].r[0]++;
            return;
        }
        int m = (lx + rx) / 2;
        build(x << 1, lx, m);
        build(x << 1 | 1, m + 1, rx);
        merge(x);
    }
    void upd(int x, int lx, int rx, int l, int r, int val) {
        push(x, lx, rx);
        if (l > rx || r < lx) 
            return;
        if (l <= lx && rx <= r) {
            f[x].lzy++;
            push(x, lx, rx);
            return;
        }
        int m = (lx + rx) / 2;
        upd(x << 1, lx, m, l, r, val);
        upd(x << 1 | 1, m + 1, rx, l, r, val);
        merge(x);
    }

    int qry(int x, int lx, int rx, int l, int r) {
        push(x, lx, rx);
        if (l > rx || r < lx) 
            return 0;
        if (l <= lx && rx <= r)
            return f[x].r[0];
        int m = (lx + rx) / 2;
        int ql = qry(x << 1, lx, m, l, r);
        int qr = qry(x << 1 | 1, m + 1, rx, l, r);
        return (ql + qr);
    }
    void upd(int l, int r) { upd(1, 1, n, l, r, 1); }
    int qry(int l, int r) { return qry(1, 1, n, l, r); }
};

int n, q;

void run_case() {
    cin >> n >> q;

    SegmentTree st(n);
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
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


