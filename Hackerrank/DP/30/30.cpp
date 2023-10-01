/**    
* LANG: C++ 
* author: atom 
* created: 19.05.2022 22:03:19
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int dp[502][502];

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;

	
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; ++j){
			if (i == j)
				dp[i][j] = 0;
			else {
				dp[i][j] = 1e9;
				for (int k = 1; k < i; k++)
					dp[i][j] = min(dp[i][j], 1 + dp[i - k][j] + dp[k][j]);
				for (int k = 1; k < j; ++k)
					dp[i][j] = min(dp[i][j], 1 + dp[i][j - k] + dp[i][k]);
			}
		}
	}	
	cout << dp[n][m] << '\n';

		 
}
