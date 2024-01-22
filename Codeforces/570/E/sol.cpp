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
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 5e2 + 5;

int n, m;
char s[N][N];
int dp[2][N][N];
// dp(len, x1, x2) : number of ways starting at x1, y1 ending at x2, y2
bool isValid(int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= m);
}
void run_case() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) 
    	for (int j = 1; j <= m; ++j)
    		cin >> s[i][j];
    // Base case
    if (s[1][1] != s[n][m]) {
    	cout << "0\n";
    	return;
    }

    int step = (n + m) / 2;
    debug(step);
    dp[0][1][n] = 1; 
    for (int i = 2; i <= step; ++i) {
    	for (int x1 = 1; x1 <= i; ++x1) {
    		for (int x2 = n; x2 >= n - i + 1; --x2) {
    			int y1 = i + 1 - x1;
    			int y2 = n + m + 1 - i - x2;
    			if (isValid(x1, y1) && isValid(x2, y2) && x1 <= x2 && y1 <= y2 && s[x1][y1] == s[x2][y2]) {
    				// debug(x1, y1, x2, y2);
    				// 1. (x1, y1 - 1), (x2, y2 + 1)
    				(dp[1][x1][x2] += dp[0][x1][x2]) %= MOD;
    				// 2. (x1, y1 - 1), (x2 + 1, y2);
    				(dp[1][x1][x2] += dp[0][x1][x2 + 1]) %= MOD;
    				// 3. (x1 - 1, y1), (x2, y2 + 1);
    				(dp[1][x1][x2] += dp[0][x1 - 1][x2]) %= MOD;
    				// 4. (x1 - 1, y1), (x2 + 1, y2);
    				(dp[1][x1][x2] += dp[0][x1 - 1][x2 + 1]) %= MOD;
    			}
    		}
    	}
    	swap(dp[0], dp[1]);
    	memset(dp[1], 0, sizeof dp[1]);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
    	(ans += dp[0][i][i]) %= MOD;	
	    // not on same row
	    if ((n + m - 1) % 2 == 0)
	    	(ans += dp[0][i][i + 1]) %= MOD;
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
