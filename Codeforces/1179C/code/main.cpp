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
const int MAX = 3e5 + 5;
const int LIM = (int) 1e6;

int c[LIM + 5];

struct SegmentTree {
    vector <int> f, lzy;

    SegmentTree() {
        f.assign((LIM << 2) + 5, 0);
        lzy.assign((LIM << 2) + 5, 0);
    }

    void build(int x, int l, int r) {
        if (l == r) {
            f[x] = c[l];
            return;
        }
        int m = (l + r) >> 1;
        build(x << 1, l, m);
        build(x << 1 | 1, m + 1, r);
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
        f[x] = max(f[x << 1], f[x << 1 | 1]);
    }

    int qry(int x, int l, int r) {
        if (f[x] <= 0)
            return -1;
        if (l == r)
            return l;
        push(x);
        int m = (l + r) >> 1;
        if (f[x << 1 | 1] > 0)
            return qry(x << 1 | 1, m + 1, r);
        if (f[x << 1] > 0)
            return qry(x << 1, l, m);
        return -1;
    }
} st;

int n, m, q;
int a[MAX], b[MAX];
int A[LIM + 5], B[LIM + 5];
void run_case() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        c[1]++;
        c[a[i] + 1]--;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        c[1]--;
        c[b[i] + 1]++;
    }
    for (int i = 1; i <= LIM; ++i) {
        c[i] += c[i - 1];
    }
    st.build(1, 1, LIM);
    cin >> q;
    while (q--) {
        int cmd, x, val;
        cin >> cmd >> x >> val;
        if (cmd == 1) {
            if (val > a[x])
                st.upd(1, 1, LIM, a[x] + 1, val, 1);
            else
                st.upd(1, 1, LIM, val + 1, a[x], -1);
            a[x] = val;
        }
        else {
            if (val > b[x])
                st.upd(1, 1, LIM, b[x] + 1, val, -1);
            else
                st.upd(1, 1, LIM, val + 1, b[x], 1);
            b[x] = val;
        }
        cout << st.qry(1, 1, LIM) << "\n";
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
