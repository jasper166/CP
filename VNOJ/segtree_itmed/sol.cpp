#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 166
#define debugArr(...) 166
#endif


const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int n, k;
int a[MAX];

struct SegTree {
    ll *f;
    void build(int N) {
        f = new ll[2 * N + 1];
        for (int i = 0; i <= 2 * n; i++) f[i] = 0;
    }

    void modify(int x, ll val) {
        for (f[x += n] = val; x > 1; x >>= 1)
            f[x >> 1] = max(f[x], f[x ^ 1]);
    }

    ll query(int l, int r) {
        // debug(l, r);
        ll res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, f[l++]);
            if (r & 1) res = max(f[--r], res);
        }
        return res;
    }


} st;

void run_case() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    st.build(n);
    vector <ll> dp(n + 1);

    ll res = 0LL;
    for (int i = n; i >= 1; i--) {
        // [i + 1, k + 1)
        ll add = st.query(min(i + 1, n), min(i + k + 1, n + 1));
        dp[i] = add + a[i];
        // debug(dp[i], add);
        st.modify(i, dp[i]);
        res = max(res, dp[i]);
    }   
    cout << res << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

