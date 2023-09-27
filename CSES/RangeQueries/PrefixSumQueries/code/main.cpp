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

//#define int long long
using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

struct SegmentTree {
    vector <ll> f, lazy, a;

    SegmentTree (int N) : f(N * 4 + 5, -LINF), lazy(N * 4 + 5, 0), a(N + 5) {};

    void push(int x) {
        if (!lazy[x]) return;
        ll w = lazy[x];

        f[x << 1] += w;
        f[x << 1 | 1] += w;

        lazy[x << 1] += w;
        lazy[x << 1 | 1] += w;

        lazy[x] = 0;
        return;
    }

    void build(int x, int l, int r) {
        if (l == r) {
            f[x] = a[l];
            lazy[x] = 0;
            return;
        }
        int m = (l + r) / 2;
        build(x << 1, l, m);
        build(x << 1 | 1, m + 1, r);
        f[x] = max(f[x << 1], f[x << 1 | 1]);
    }

    void upd(int x, int l, int r, int u, int v, ll val) {
        if (l > v || r < u)
            return;
        if (u <= l && r <= v) {
            f[x] += val;
            lazy[x] += val;
            return;
        }
        push(x);
        int m = (l + r) / 2;
        upd(x << 1, l, m, u, v, val);
        upd(x << 1 | 1, m + 1, r, u, v, val);
        f[x] = max(f[x << 1], f[x << 1 | 1]);
    }

    ll qry(int x, int l, int r, int u, int v) {
        if (l > v || r < u)
            return -LINF;
        if (u <= l && r <= v)
            return f[x];
        push(x);
        int m = (l + r) / 2;
        ll ql = qry(x << 1, l, m, u, v);
        ll qr = qry(x << 1 | 1, m + 1, r, u, v);
        return max(ql, qr);
    }
};


int n, q;
int a[MAX];
ll pr[MAX];

void run_case() {
    cin >> n >> q;
    SegmentTree st(n);
    st.a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pr[i] = pr[i - 1] + a[i];
        st.a[i] = pr[i];
    }
    st.build(1, 0, n);
    while (q--) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        if (cmd == 2) {
            ll ans = st.qry(1, 0, n, x, y);
            ll pref = st.qry(1, 0, n, x - 1, x - 1);
            cout << max(0ll, ans - pref) << "\n";
        }
        else {
            st.upd(1, 0, n, x, n, y - a[x]);
            a[x] = y;
        }
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

