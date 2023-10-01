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
constexpr int MAX = 52;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, m;
int dp[MAX][MAX];
int grid[9][9];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);
	// freopen("knight.in", "r", stdin);
	// freopen("knight.out", "w", stdout);

	cin >> n >> m;
	dp[1][1] = 1;
	FOR(i, 1, n){
		FOR(j, 1, m){
			if (i >= 1 && j >= 2) dp[i][j] += dp[i - 1][j - 2];
			if (i >= 2 && j >= 1) dp[i][j] += dp[i - 2][j - 1];
		}
	}
	cout << dp[n][m] << '\n';
}
/* problem link: 

*/
