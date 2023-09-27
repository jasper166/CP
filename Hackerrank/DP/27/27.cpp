/**    
* LANG: C++ 
* author: atom 
* created: 19.05.2022 15:39:12
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
	vector <int> dp(n + 1, 1e9);
	dp[0] = 0;
	int res = 0;
	for (int i = 1; i <= n; i++){
		string s = to_string(i);
		for (int x = 0; x <= (int) s.length() - 1; x++)
			dp[i] = min(dp[i], dp[i - (s[x] - '0')] + 1);
	}
	cout << dp[n] << '\n';
		 
}
