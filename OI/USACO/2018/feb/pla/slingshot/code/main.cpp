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

#define int long long
using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = INT_MAX;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

struct SegmentTree {
    vector <int> f;
    int n;
    void init(int N) {
        n = N;
        f.assign(N << 1, INF);
    }
    void upd(int x, int val) {
        x += n;
        f[x] = min(f[x], val);
        for (; x; x >>= 1)
            f[x >> 1] = min(f[x], f[x ^ 1]);
    }

    int qry(int l, int r) {
        int ans = INF;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = min(ans, f[l++]);
            if (r & 1) ans = min(f[--r], ans);
        }
        return ans;
    }

};

int n, m;
array<int, 3> piles[MAX], slings[MAX];
int ans[MAX];
vector <int> b;
// min i : abs(a - xi) + abs(b - yi) + ti;
int getPos(int x) {
    return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
}

void run_case() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        slings[i] = {x, y, t};
        b.push_back(y);
    }

    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        piles[i] = {x, y, i};
        b.push_back(y);
    }

    sort(slings + 1, slings + 1 + n);
    sort(piles + 1, piles + 1 + m);
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    SegmentTree lhs, rhs;
    fill(ans, ans + m + 1, LINF);

    lhs.init(MAX + 5), rhs.init(MAX + 5);
    int j = 1;
    for (int i = 1; i <= m; ++i) {
        auto [l, r, id] = piles[i];
        // l >= xi;
        while (j <= n && slings[j][0] <= l) {
            auto [x, y, t] = slings[j];
            // r >= yi;
            debug(getPos(y));
            lhs.upd(getPos(y), t - x - y);
            // r <= yi;
            rhs.upd(getPos(y), t - x + y);
            ++j;
        }
        int ql = lhs.qry(1, getPos(r));
        int qr = rhs.qry(getPos(r), MAX);
        if (ql != INF)
            ans[id] = min(ans[id], ql + l + r);
        if (qr != INF)
            ans[id] = min(ans[id], qr + l - r);

    }

    lhs.init(MAX + 5), rhs.init(MAX + 5);
    j = n;
    for (int i = m; i >= 1; --i) {
        auto [l, r, id] = piles[i];
        // l <= xi
        while (j >= 1 && slings[j][0] >= l) {
            auto [x, y, t] = slings[j];
            // r >= yi;
            lhs.upd(getPos(y), t + x - y);
            // r <= yi
            rhs.upd(getPos(y), t + x + y);
            --j;
        }
        int ql = lhs.qry(1, getPos(r));
        int qr = rhs.qry(getPos(r), MAX);
        if (ql != INF)
            ans[id] = min(ans[id], ql - l + r);
        if (qr != INF)
            ans[id] = min(ans[id], qr - l - r);
    }

    // Not use any sling at all
    for (int i = 1; i <= m; ++i) {
        auto [l, r, id] = piles[i];
        ans[id] = min(ans[id], 1ll * abs(r - l));
    }
    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << "\n";
    }
}

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in2", "r", stdin);
    #endif
   setIO("slingshot");
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
