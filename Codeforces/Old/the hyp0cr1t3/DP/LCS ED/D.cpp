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
constexpr int MAX = 5002;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, m;
string a, b;
// dp(i, j) maximum score at subtring at index i of A, index j of B.

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m >> a >> b;
	a = '$' + a;
	b = '$' + b;
	int ans = 0;
	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (a[i] == b[j])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
			else
				dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]) - 1);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';
}
/* problem link: 
	https://codeforces.com/contest/1447/problem/D
*/
