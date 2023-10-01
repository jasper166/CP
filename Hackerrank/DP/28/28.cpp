/**    
* LANG: C++ 
* author: atom 
* created: 19.05.2022 17:19:29
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
constexpr int MAX = 1e5 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int a[MAX];
int dp[MAX][102];
int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n - 1; i++) cin >> a[i];
	
	memset(dp, 0, sizeof(dp));
	if (a[0] == 0) 
		for (int i = 0; i <= m; ++i) dp[0][i] = 1;
	else dp[0][a[0]] = 1;

	for (int i = 1; i <= n - 1; i++){
		if (a[i] != 0){
			for (int k : {a[i] - 1, a[i], a[i] + 1})
				if (k <= m && k >= 1)
						dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][k]) % MOD;
		}
		else {
			for (int j = 1; j <= m; ++j){ 
				for (int k : {j - 1, j, j + 1})
					if (k <= m && k >= 1)
						dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i)
		ans = (ans + dp[n - 1][i]) % MOD;
	cout << ans << '\n';
}
