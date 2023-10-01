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
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 3e3 + 5;

ll dp[2][N];
int a[N], n, k;
ll sqr[N], sum[N];

ll cost(int l, int r) {
    return sqr[r] - sqr[l - 1] - 2 * (sum[r] - sum[l - 1]) * sum[l - 1];
}

void dnc(int l, int r, int opt_l, int opt_r) {
    if (l > r) return;
    int m = (l + r) / 2;
    int split = -1;
    ll ans = INF;
    for (int x = opt_l; x <= min(m - 1, opt_r); ++x) {
        ll cur = dp[0][x] + cost(x + 1, m);
        if (cur < ans) {
            split = x;
            ans = cur;
        }
    }
    dp[1][m] = ans;
    dnc(l, m - 1, opt_l, split);
    dnc(m + 1, r, split, opt_r);
}

void run_case() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        sqr[i] = sqr[i - 1] + 2ll * sum[i - 1] * a[i] + 1ll * a[i] * a[i];
    }
    for (int i = 1; i <= n; ++i) {
        dp[0][i] = cost(1, i);
        // debug(dp[0][i]);
    }
    debug(cost(1, 3));
    for (int i = 2; i <= k; ++i) {
        dnc(1, n, 1, n);
        swap(dp[0], dp[1]);
    }
    cout << dp[0][n] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


