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

struct SegmentTree {
    vector <int> f, a;
    int n;
    SegmentTree(int _N) : f(_N * 2 + 5), a(_N + 5), n(_N) {};

    void build(int N) {
        f.assign(N * 2 + 5, INF);
        for (int i = 1; i <= n; ++i)
            f[i + n] = a[i];
        for (int i = n; i >= 1; --i)
            f[i] = min(f[i << 1], f[i << 1 | 1]);
    }

    void upd(int x, int val) {
        f[x += n] = val;
        for (; x; x >>= 1)
            f[x >> 1] = min(f[x], f[x ^ 1]);
    }

    int qry(int l, int r) {
        int ans = INF;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                ans = min(ans, f[l++]);
            if (r & 1)
                ans = min(ans, f[--r]);
        }
        return ans;
    }
};


int n, q;
int a[MAX];

void run_case() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    SegmentTree st1(n), st2(n);
    for (int i = 1; i <= n; ++i) {
//        st1.a[i] = a[i];
        st1.a[i] = a[i] - i;
        st2.a[i] = a[i] + i;
     }
    st1.build(n);
    st2.build(n);

    while (q--) {
        int cmd, x, y;
        cin >> cmd;
        if (cmd == 2) {
            cin >> x;
            int L = st1.qry(1, x) + x;
            int R = st2.qry(x, n) - x;
//            debug(L, R);
            cout << min(L, R) << "\n";
        }
        else {
            cin >> x >> y;
            st1.upd(x, y - x);
            st2.upd(x, y + x);
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

