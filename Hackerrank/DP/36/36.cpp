/**    
* LANG: C++ 
* author: atom 
* created: 06.06.2022 06:51:43
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

int a, b;

bool isPrime(int x){
	for (int i = 2; i <= sqrt(x); ++i)
		if (x % i == 0) return false;
	return true;
}

int inRange(int x){
	string y = to_string(x);
	int n = y.size();
	int dp[n + 1][2][102];

	memset(dp, 0, sizeof(dp));
	dp[n][0][0] = 1;
	dp[n][1][0] = 1;


	for (int i = n - 1; i >= 0; i--){
		for (int j = 0; j <= 1; j++){
			for (int k = 0; k <= 100; k++){	
				if (j){
					dp[i][1][k] += dp[i + 1][1][k - y[i] + '0'];
					for (int d = '0'; d < y[i]; d++)
						dp[i][1][k] += dp[i + 1][0][k - d + '0'];
				}
				else {
					for (int d = 0; d <= 9; d++)
						dp[i][0][k] += dp[i + 1][j][k - d]; 
				}
			}
		}
	}


	int ans = 0;
	for (int i = 2; i <= 100; ++i)
		if (isPrime(i)) ans += dp[0][1][i];
	return ans;
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a >> b;
	// cout << inRange(b) << '\n';
	cout << inRange(b) - inRange(a - 1) << '\n';
		 
}
