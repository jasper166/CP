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

int a[N], b[N];
int n, k;
ll dp[2][N][5];

void run_case() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];   

    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= k; ++j)
            for (int t = 0; t < 5; ++t)
                dp[i][j][t] = -INF;

    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            // Skip this element
            dp[1][j][0] = max(dp[1][j][0], dp[0][j][0]);
            
            // Take segment of size 1?
            ll cur = dp[0][j][0] + 2ll * abs(a[i] - b[i]);
            dp[1][j + 1][0] = max(dp[1][j + 1][0], cur);

            // start a new segment
            for (int x = 1; x <= 4; ++x) {
                int s_a = (x & 1)? -1 : 1;
                int s_b = (x <= 2)? 1 : -1;
                ll cur_dp = dp[0][j][0] + 1ll * s_a * a[i] + 1ll * s_b * b[i]; 
                dp[1][j + 1][x] = max(dp[1][j + 1][x], cur_dp);
            }
            
            // continue current segment
            for (int x = 1; x <= 4; ++x)
                dp[1][j + 1][x] = max(dp[1][j + 1][x], dp[0][j][x]);    
            
            // end a segment
            for (int x = 1; x <= 4; ++x) {
                int s_a = (x <= 2)? -1 : 1;
                int s_b = (x & 1)? 1 : -1;
                ll cur_dp = dp[0][j][x] + 1ll * s_a * a[i] + 1ll * s_b * b[i]; 
                dp[1][j + 1][0] = max(dp[1][j + 1][0], cur_dp);
            }
        }
        for (int j = 0; j <= k; ++j) {
            for (int x = 0; x <= 4; ++x) {
                dp[0][j][x] = dp[1][j][x];
                dp[1][j][x] = -INF;
            }
        }
    }

    cout << dp[0][k][0] << "\n";
}

/*
    abs(x) = max(x, -x);

    |br - al| + |bl - ar|
    0. not in any segment (we're done with choosing segment)
    1. br - al + bl - ar = -al + bl - ar + br
    2. al - br + bl - ar = al + bl - ar - br
    3. br - al + ar - bl = -al - bl + ar + br
    4. al - br + ar - bl = al - bl + ar - br
    -> ans = dp(n, k, 0);
    choose maximum option from 4 above
    -> dp(i, j, k) : 1...i elements, current segment length is j, k = (0..5) : for each case above
    
    At a(i):
    1. Skip this element
    // we have to finish previous segment
    2. Take segment of 1-sized
    3. Start a new segment
    // Take al, bl as input
    4. Continue current segment
    5. Ending current segment
    // Take ar, br to answer;
    - Use rolling array to optimize memory
*/

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


