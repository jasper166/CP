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

int m;
int a[MAX];

struct SegmentTree {
    vector <int> f, lzy;
    SegmentTree (int _m) {
        f.assign(MAX << 2, 0);
        lzy.assign(MAX << 2, 0);
    }

    void merge(int x) {
        f[x] = max(f[x << 1], f[x << 1 | 1]);
    }

    void push(int x) {
        int w = lzy[x];
        if (w) {
            f[x << 1] += w;
            f[x << 1 | 1] += w;

            lzy[x << 1] += w;
            lzy[x << 1 | 1] += w;

            lzy[x] = 0;
        }
    }

    void upd(int x, int l, int r, int u, int v, int val) {
        if (l > v || r < u)
            return;
        if (u <= l && r <= v) {
            f[x] += val;
            lzy[x] += val;
            return;
        }
        push(x);
        int m = (l + r) >> 1;
        upd(x << 1, l, m, u, v, val);
        upd(x << 1 | 1, m + 1, r, u, v, val);
        merge(x);
    }

    int qry(int x, int l, int r) {
        if (f[x] <= 0)
            return -1;
        if (l == r)
            return a[l];
        push(x);
        int m = (l + r) >> 1;
        if (f[x << 1 | 1] > 0)
            return qry(x << 1 | 1, m + 1, r);
        else
            return qry(x << 1, l, m);
    }
};


void run_case() {
    cin >> m;
    SegmentTree st(m);
    for (int i = 1; i <= m; ++i) {
        int x, cmd, val;
        cin >> x >> cmd;
        if (cmd == 1) {
            cin >> val;
            st.upd(1, 1, m, 1, x, 1);
            a[x] = val;
        }
        else
            st.upd(1, 1, m, 1, x, -1);
        cout << st.qry(1, 1, m) << "\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in3", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
