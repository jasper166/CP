/**    
* LANG: C++ 
* author: atom 
* created: 19.05.2022 20:49:44
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
constexpr int MAX = 125002;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n;
int dp[502][MAX];

ll twoset(){
	int sum = n * (n + 1) / 2;
	if (sum & 1) return 0;
	else {
		int m = sum / 2;

		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;

		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= m; j++){
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
				if (j >= i)
					dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
			}
		ll inverse2 = 500000004;
		return (dp[n][m] % MOD * inverse2) % MOD;
	}
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	cout << twoset() << '\n';
		 
}
