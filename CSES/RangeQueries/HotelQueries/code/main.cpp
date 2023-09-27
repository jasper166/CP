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

int ans;
struct SegmentTree {
    vector <int> f, a;
    SegmentTree(int N): f(N * 4 + 5), a(N + 5) {};

    void build(int x, int l, int r) {
        if (l == r) {
            f[x] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(x << 1, l, m);
        build(x << 1 | 1, m + 1, r);
        f[x] = max(f[x << 1], f[x << 1 | 1]);
    }

    void qry_hotel(int x, int l, int r, int val) {
        if (l == r) {
            f[x] -= val;
            ans = l;
            return;
        }
        int m = (l + r) >> 1;
        if (f[x << 1] >= val)
            qry_hotel(x << 1, l, m, val);
        else
            qry_hotel(x << 1 | 1, m + 1, r, val);
        f[x] = max(f[x << 1], f[x << 1 | 1]);
    }

};

int n, q;
void run_case() {
    cin >> n >> q;

    SegmentTree st(n);
    for (int i = 1; i <= n; ++i) {
        cin >> st.a[i];
//        debug(st.a[i]);
    }
    st.build(1, 1, n);
    for (int i = 1; i <= q; ++i) {
        int x; cin >> x;
        if (st.f[1] < x)
            cout << "0 ";
        else {
            st.qry_hotel(1, 1, n, x);
            cout << ans << " ";
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
//    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
