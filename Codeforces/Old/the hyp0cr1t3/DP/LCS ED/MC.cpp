/**    
* LANG: C++ 
* author: atom 
* created: 26.06.2022 10:35:09
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define end cout << '\n'
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1002;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

string s, t;
int dp[MAX][MAX];
int n, m;

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);
	while (true){
		cin >> s;
		if (s == "#") break;
		cin >> t;

		n = s.size();
		m = t.size();
		s = '$' + s;
		t = '$' + t;
		memset(dp, 0, sizeof(dp));
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++){
				if (s[i] == t[j])
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				else 
					dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
				ans = max(ans, dp[i][j]);
			}
		cout << 15 * (n - ans) + 30 * (m - ans) << '\n';		
	}

		 
}
/* problem link: 
	https://www.spoj.com/problems/MC/
*/
