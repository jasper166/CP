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

struct SegmentTree {
    vector <int> f, lzy;
    SegmentTree (){
        f.assign(MAX << 2 + 5, 0);
        lzy.assign(MAX << 2 + 5, 0);
    }
    void push(int x, int lx, int rx) {
        if (!lzy[x])
            return;
        int w = lzy[x];
        f[x << 1] += w;
        f[x << 1 | 1] += w;
        lzy[x << 1] += w;
        lzy[x << 1 | 1] += w;

        lzy[x] = 0;
    }
    void upd(int l, int r, int val, int x = 1, int lx = 1, int rx = MAX) {
        if (lx > r || rx < l)
            return;
        if (l <= lx && rx <= r) {
            f[x] += val;
            lzy[x] += val;
            return;
        }
        push(x, lx, rx);
        int m = (lx + rx) >> 1;
        upd(l, r, val, x << 1, lx, m);
        upd(l, r, val, x << 1 | 1, m + 1, rx);
        f[x] = max(f[x << 1], f[x << 1 | 1]);
    }

    int qryLhs(int val, int x = 1, int lx = 1, int rx = MAX) {
        if (f[1] <= val)
            return 1;
        if (lx == rx)
            return lx + 1;
        push(x, lx, rx);
        int m = (lx + rx) >> 1;
        if (f[x << 1 | 1] > val)
            return qryLhs(val, x << 1 | 1, m + 1, rx);
        else
            return qryLhs(val, x << 1, lx, m);
    }

    int qryRhs(int val, int x = 1, int lx = 1, int rx = MAX) {
        if (lx == rx)
            return lx;
        push(x, lx, rx);
        int m = (lx + rx) >> 1;
        if (f[x << 1 | 1] >= val)
            return qryRhs(val, x << 1 | 1, m + 1, rx);
        else
            return qryRhs(val, x << 1, lx, m);
    }

    ll cal(int x = 1, int lx = 1, int rx = MAX) {
        if (lx == rx)
            return (1ll * f[x] * (f[x] - 1) / 2);
        push(x, lx, rx);
        int m = (lx + rx) >> 1;
        return cal(x << 1, lx, m) + cal(x << 1 | 1, m + 1, rx);
    }

    int get(int pos, int x = 1, int lx = 1, int rx = MAX) {
//        debug(x, lx, rx);
        if (lx == rx)
            return f[x];
        push(x, lx, rx);
        int m = (lx + rx) >> 1;
        if (pos <= m)
            return get(pos, x << 1, lx , m);
        else
            return get(pos, x << 1 | 1, m + 1, rx);
    }
};

int n;
void run_case() {
    cin >> n;
    vector <pii> masts;
    int M = 1;
    for (int i = 1; i <= n; ++i) {
        int h, k;
        cin >> h >> k;
        masts.push_back({h, k});
        M = max(M, h);
    }
    SegmentTree st;
    sort(masts.begin(), masts.end());
    for (auto [h, k] : masts) {
        int x = st.get(h - k + 1);
        // get first pos
        int l = st.qryLhs(x);
        // get last pos
        int r = st.qryRhs(x);
        if (r > M)
            st.upd(l, l + k - 1, 1);
        else {
            st.upd(l, l + k - h + r - 1, 1);
            st.upd(r + 1, h, 1);
        }
        debug(x, l, r);
    }
    ll ans = st.cal();
    cout << ans << "\n";
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
