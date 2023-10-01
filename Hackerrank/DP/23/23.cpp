/**    
* LANG: C++ 
* author: atom 
* created: 19.05.2022 13:28:00
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
	s = ' ' + s;
	int n = (int) s.length();
	bool dp[n + 1][n + 1];
	memset(dp, false, sizeof(dp));
	for (int i = 0; i <= n; i++) dp[i][i] = true;
	int ans = 1;
	for (int len = 2; len <= n; len++){
		for (int i = 1; i <= n - len + 1; i++){
			int j = i + len - 1; 
			if (s[i] != s[j]) 
				dp[i][j] = false;
			else if(len == 2 && s[i] == s[j])
				dp[i][j] = true;
			else
				dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
			if (dp[i][j])
			 	ans = max(ans, len);
		}
	}
	
	cout << ans << '\n';
	
}
