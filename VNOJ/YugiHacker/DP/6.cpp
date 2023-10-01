/**    
* LANG: C++ 
* author: atom 
* created: 03.06.2022 21:20:08
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

ll n;
ll a[MAX];

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll dp[n + 1][4];
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= 3; j++){
			if (i == 0 || j == 0) dp[i][j] = 0;
			else if (j == 1) dp[i][j] = dp[i - 1][j] + a[i];
			else dp[i][j] = (dp[i - 1][j] % MOD + (dp[i - 1][j - 1] % MOD * a[i] % MOD)) % MOD;
		}
	}	
	// for (int i = 0; i <= n; i++){
	// 	for (int j = 0; j <= 3; j++) cout << dp[i][j] << ' ';
	// 	cout << '\n';
	// }
	cout << dp[n][3] << '\n';
}
