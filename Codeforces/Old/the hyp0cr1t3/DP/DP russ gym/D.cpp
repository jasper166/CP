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

ll dp[MAX][MAX];
int grid[12][12];
pii xy[] = {{0, -1}, {1, -1}, {1, 0}};

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);
	// freopen("king2.in", "r", stdin);
	// freopen("king2.out", "w", stdout);

	FOR(i, 1, 8)
		FOR(j, 1, 8) cin >> grid[i][j];
	// cout << grid[8][1] << '\n';
	FORD(i, 8, 1){
		FOR(j, 1, 8){
			ll cost = 1e9;
			if (i == 8 && j == 1) continue;
			for (pii x : xy){
				if (1 <= i + x.F && i + x.F <= 8 && 1 <= j + x.S && j + x.S <= 8){
					cost = min(cost, dp[i + x.F][j + x.S]);
				}
			}
			dp[i][j] = cost + grid[i][j];
		}
	}
	cout << dp[1][8] << '\n';
}
/* problem link: 

*/
