/**    
* LANG: C++ 
* author: atom 
* created: 19.05.2022 11:55:46
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

	string s;
	cin >> s;
	int n = (int) s.length();
	ll sum = 0;
	ll dp[n];
	dp[0] = s[0] - '0';
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n - 1; i++){
		dp[i] = s[i] - '0';
		ll k = dp[i];
		ll p = 10;
		for (int j = i - 1; j >= 0; j--, p *= 10){
			k = (s[j] - '0') * p + k;
			dp[i] += k;
		}
		dp[i] += dp[i - 1];
	}
	cout << dp[n - 1] << '\n';
}
