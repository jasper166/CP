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
const int N = 5e3 + 5;


/*
    Knuth optimization: O(n^3) -> O(n^2)
    dp(i, j) = min(k) : dp(i, k) + dp(k + 1, j) + cost(i, j)
    - cost function sastifies quadrangle inequality
    - opt(i, j - 1) <= opt(i, j) <= opt(i + 1, j);
*/
int n;
int a[N], opt[N][N];
ll dp[N][N], prf[N];

ll cost(int l, int r) {  return (prf[r] - prf[l - 1]); }

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        prf[i] = prf[i - 1] + a[i];
        opt[i][i] = i;
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            dp[i][j] = INF;
            for (int k = opt[i][j - 1]; k <= min(j, opt[i + 1][j]); ++k) {
                ll cur = dp[i][k] + dp[k + 1][j] + cost(i, j);
                if (cur < dp[i][j]) {
                    dp[i][j] = cur;
                    opt[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n] << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


