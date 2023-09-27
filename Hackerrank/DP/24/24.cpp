/**    
* LANG: C++ 
* author: atom 
* created: 19.05.2022 15:06:15
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


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int dp[n + 1];
	for (int i = 0; i <= 3; i++) dp[i] = i;
	for (int i = 4; i <= n; i++){
		dp[i] = i;
		for (int j = 1; j <= sqrt(i); j++){
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[n] << '\n';
}
