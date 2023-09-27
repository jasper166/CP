/**    
* LANG: C++ 
* author: atom 
* created: 03.06.2022 20:00:36
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

int dp[1002][1002];

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(dp, 0, sizeof(dp));
	int n, k;
	cin >> n >> k; 
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= min(i, k); ++j){
			if (j == 0 || j == i) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD; 
		}
	}
	cout << dp[n][k] << '\n';
		 
}
