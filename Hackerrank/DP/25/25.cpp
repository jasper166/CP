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

int dp[102][102];
string s1, s2;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	

	cin >> s1 >> s2;
	int n1 = (int) s1.length();
	int n2 = (int) s2.length();

	for (int i = 0; i <= n1; ++i)
		for (int j = 0; j <= n2; ++j){
			if (i == 0) 
				dp[i][j] = j;
			else if (j == 0) 
				dp[i][j] = i;
			else if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else 
				dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}); 
		}
	cout << dp[n1][n2] << '\n';
}
