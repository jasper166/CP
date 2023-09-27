/**    
* LANG: C++ 
* author: atom 
* created: 12.06.2022 08:28:35
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
#define end cout << '\n';
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	bool grid[1002][1002];
	ll dp[n + 1][m + 1];

	FOR(i, 1, n){
		string s;
		cin >> s;
		FOR(j, 1, m){
			grid[i][j] = (s[j - 1] == '.');
			dp[i][j] = 0;
		}
	}
	dp[1][1] = (grid[1][1]);

	FOR(i, 1, n)
		FOR(j, 1, m){
			if (i == 1 && j == 1) continue;
			if (grid[i][j]){
				if (i >= 2) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
				if (j >= 2) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
			}
			else dp[i][j] = 0;	
		}


	cout << dp[n][m] << '\n';
}
