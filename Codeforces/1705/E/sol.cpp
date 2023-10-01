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
    vector <int> f, lzy;
    SegmentTree() : f(4 * N + 5, 0), lzy(4 * N + 5, -1) {};

    void push(int x, int l, int r) {
        if (lzy[x] == -1) return;
        int val = lzy[x];
        int m = (l + r) / 2;
        f[x << 1] = (m - l + 1) * val;
        f[x << 1 | 1] = (r - m) * val;

        lzy[x << 1] = val;
        lzy[x << 1 | 1] = val;
        
        lzy[x] = -1;
        return;
    }
    void upd(int x, int l, int r, int u, int v, int val) {
        if (l > v || r < u)
            return;
        if (u <= l && r <= v) {
            lzy[x] = val;
            f[x] = (r - l + 1) * val;
            return;
        }
        push(x, l, r);
        int m = (l + r) / 2;
        upd(x << 1, l, m, u, v, val);
        upd(x << 1 | 1, m + 1, r, u, v, val);
        f[x] = f[x << 1] + f[x << 1 | 1];
    }

    int get(int x, int l, int r, int u, int v) {
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return f[x];
        push(x, l, r);
        int m = (l + r) / 2;
        return (get(x << 1, l, m, u, v) + get(x << 1 | 1, m + 1, r, u, v));
    }

    void upd(int l, int r, int val) { upd(1, 1, N, l, r, val); }
    int get(int l, int r) { return get(1, 1, N, l, r); }

    int findLast(int l, int r, int val) {
        // Find longest ..1111..
        int ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (get(l, m) == (m - l + 1) * val) {
                ans = m;
                l = m + 1;
            }
            else 
                r = m - 1;
        }
        return ans;
    }

    void modify(int x, int t) {
        // debug(x, get(x, x));
        if (get(x, x) != t) {
            upd(x, x, t);
            return;
        }
        int lst = findLast(x, N, t);
        upd(x, lst, t ^ 1);
        upd(lst + 1, lst + 1, t);
    }

    int qry(int x, int l, int r) {
        if (l == r) 
            return l;
        push(x, l, r);
        int m = (l + r) / 2;
        if (f[x << 1 | 1] != 0)
            return qry(x << 1 | 1, m + 1, r);
        else 
            return qry(x << 1, l, m);
    }
};

int n, q;
int a[N];

void run_case() {
    cin >> n >> q;
    SegmentTree st;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        st.modify(a[i], 1);
    }
    // debug(st.get(1, N));
    // debug(st.qry(1, 1, N));
    for (int i = 1; i <= q; ++i) {
        int k, l;
        cin >> k >> l;
        st.modify(a[k], 0);
        a[k] = l;
        st.modify(a[k], 1);

        int ans = st.qry(1, 1, N);
        cout << ans << "\n";
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


