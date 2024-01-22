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
const int N = 2e5 + 5;

struct SegmentTree {
    struct Data {
        int v[105];
        bool lzy;
        Data() {
            iota(v, v + 101, 0);
            lzy = 0;
        }
    };
    vector <Data> f;
    vector <int> a;
    int n;
    SegmentTree(int _n) : f(_n * 4 + 5), a(_n + 5), n(_n) {};
    void push(int x, int l, int r) {
        if (!f[x].lzy) return;
        for (int i = 0; i <= 100; ++i) {
            f[x << 1].v[i] = f[x].v[f[x << 1].v[i]];
            f[x << 1 | 1].v[i] = f[x].v[f[x << 1 | 1].v[i]];

        }
        f[x << 1].lzy = f[x << 1 | 1].lzy = 1;
        f[x].lzy = 0;
        for (int i = 1; i <= 100; ++i)
            f[x].v[i] = i;
    }

    void upd(int x, int l, int r, int u, int v, int cur, int nxt) {
        if (l > v || r < u) return;
        if (u <= l && r <= v) {
            f[x].lzy = 1;
            for (int i = 0; i <= 100; ++i)
                if (f[x].v[i] == cur)
                    f[x].v[i] = nxt;
            return;
        }
        push(x, l, r);
        int m = (l + r) >> 1;
        upd(x << 1, l, m, u, v, cur, nxt);
        upd(x << 1 | 1, m + 1, r, u, v, cur, nxt);
    }
    void upd(int l, int r, int x, int y) { upd(1, 1, n, l, r, x, y); }

    int qry(int x, int l, int r, int pos, int val) {
        if (l == r && l == pos) return f[x].v[val];
        int m = (l + r) >> 1;
        push(x, l, r);
        if (pos <= m) return qry(x << 1, l, m, pos, val);
        else return qry(x << 1 | 1, m + 1, r, pos, val);
    }
    int qry(int i) { return qry(1, 1, n, i, a[i]); }
};

int n, q;
void run_case() {
    cin >> n;
    SegmentTree st(n);
    for (int i = 1; i <= n; ++i) cin >> st.a[i];

    cin >> q;
    while (q--) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        st.upd(l, r, x, y);
    }
    for (int i = 1; i <= n; ++i) {
        int x = st.qry(i);
        cout << x << " \n"[i == n];
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


