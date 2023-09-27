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
    int n;
    const pii NEUTRAL = {-1, -1};
    vector <int> f;
    SegmentTree(int _n) {
        n = _n;
        f.resize(4 * n + 5);
    }
    int merge(int x, int y) { return min(x, y); }
    void upd(int x, int l, int r, int pos, int val) {
        if (l == r) {
            f[x] = val;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) upd(x << 1, l, m, pos, val);
        else upd(x << 1 | 1, m + 1, r, pos, val);
        f[x] = merge(f[x << 1], f[x << 1 | 1]);
    }
    pii get(int x, int lx, int rx, int l, int r, int k) {
        if (l > rx || r < lx || f[x] >= k) return NEUTRAL;
        if (lx == rx) return {f[x], lx};
        int m = (lx + rx) / 2;
        pii ans = get(x << 1, lx, m, l, r, k);
        if (ans == NEUTRAL)
            ans = get(x << 1 | 1, m + 1, rx, l, r, k);
        return ans;
    }
    void upd(int pos, int val) { upd(1, 1, n, pos, val); }
    pii get(int l, int r, int k) {
        if (l > r) return NEUTRAL;
        return get(1, 1, n, l, r, k);
    }
} ;

int n;
int a[MAX], d[MAX];
vector <pii> adj[MAX];

bool ok(int x) {
    SegmentTree st(n);
    for (int i = 1; i <= n; ++i) {
        ll cur = 0;
        for (auto [j, cnt] : adj[i]) {
            while (cnt) {
                auto [val, pos] = st.get(j, i - 1, x);
                if (val == -1 || pos == -1) break;
                int y = min(x - val, cnt);
                st.upd(pos, val + y);
                cnt -= y;
            }
            cur += cnt;
        }
        if (cur > x) return 0;
        st.upd(i, cur);
    }
    return 1;

}

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> d[i];

    for (int i = 1; i <= n; ++i) {
        int u = max(1, i - d[i]);
        int v = min(n, i + d[i]);
        adj[v].push_back({u, a[i]});
    }
    for (int i = 1; i <= n; ++i) sort(adj[i].begin(), adj[i].end());
    int l = 0, r = *max_element(a + 1, a + 1 + n);
//    debug(l, r);
    int ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (ok(m)) {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
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
