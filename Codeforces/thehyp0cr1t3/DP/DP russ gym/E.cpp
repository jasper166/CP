/**    
* LANG: C++ 
* author: atom 
* created: 26.06.2022 18:22:38
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
constexpr int MAX = 202;
constexpr int INF = INT_MAX;
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, a[MAX][MAX];
int dp[MAX][MAX];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n;
	FOR(i, 1, n){
		FOR(j, 1, i)
			cin >> a[i][j];
	}

	FOR(i, 0, n)
		FOR(j, 0, n) dp[i][j] = -INF; 

	FOR(i, 1, n){
		FOR(j, 1, i){
			if (i == 1) dp[i][j] = 0;
			if (i > 1){
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
			dp[i][j] += a[i][j];
		}
	}
	// FOR(i, 2, n){
	// 	FOR(j, 1, i){
	// 		int add = -INF;
	// 		if (j > 1) add = max(add, dp[i - 1][j - 1]);
	// 		if (j < i) add = max(add, dp[i - 1][j]);
	// 		dp[i][j] += add;
	// 	}
	// }
	int ans = -INF;
	FOR(i, 1, n) ans = max(ans, dp[n][i]);
	cout << ans << '\n';
	// FOR(i, 1, n){
	// 	FOR(j, 1, i) cout << dp[i][j] << ' ';
	// 	cout << '\n';
	// }

		 
}
/* problem link: 

*/
