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
    int val, lzy, l, r;
    Node() : val(0), lzy(0), l(-1), r(-1) {};
};

struct DynamicSegmentTree {

    vector <Node> f;
    int n;

    DynamicSegmentTree() : f(MAX * 60) , n(1) {};

    void push(int x, int l, int r) {
        if (!f[x].lzy)
            return;
        if (f[x].l == -1)
            f[x].l = ++n;
        if (f[x].r == -1)
            f[x].r = ++n;

        int m = (l + r) >> 1;
        f[f[x].l].lzy = f[x].lzy;
        f[f[x].r].lzy = f[x].lzy;
        f[f[x].l].val = f[x].lzy * (m - l + 1);
        f[f[x].r].val = f[x].lzy * (r - m);
        f[x].lzy = 0;
    }

    void upd(int u, int v, int val, int x = 1, int l = 1, int r = INF) {
        if (l > v || r < u)
            return;
        if (u <= l && r <= v) {
            f[x].val = val * (r - l + 1);
            f[x].lzy = val;
            return;
        }

        if (f[x].l == -1)
            f[x].l = ++n;
        if (f[x].r == -1)
            f[x].r = ++n;
        push(x, l, r);

        int m = (l + r) >> 1;
        upd(u, v, val, f[x].l, l, m);
        upd(u, v, val, f[x].r, m + 1, r);
        f[x].val = f[f[x].l].val + f[f[x].r].val;
    }

    int qry(int u, int v, int x = 1, int l = 1, int r = INF) {
        if (l > v || r < u)
            return 0;
        if (u <= l && r <= v)
            return f[x].val;

        if (f[x].l == -1)
            f[x].l = ++n;
        if (f[x].r == -1)
            f[x].r = ++n;
        push(x, l, r);

        int m = (l + r) >> 1;
        int ql = qry(u, v, f[x].l, l, m);
        int qr = qry(u, v, f[x].r, m + 1, r);
        return (ql + qr);
    }
};




void run_case() {
    int q;
    DynamicSegmentTree st;
    cin >> q;
    int c = 0;
    while (q--) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
//        debug(cmd, x, y);
        if (cmd == 1) {
            c = st.qry(x + c , y + c);
            cout << c << "\n";
        }
        else
            st.upd(x + c, y + c, 1);
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
