/**    
* LANG: C++ 
* author: atom 
* created: 24.06.2022 18:53:11
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
constexpr int MAX = 205; 
const int MAXX = 5005;
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, m;
ll a[MAX];
ll dp[MAX][MAXX], tmp[MAX][MAXX];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];

	ll ans = 0;
	FOR(j, 0, MAX - 1)
		FOR(k, 0, MAXX - 1) dp[j][k] = -1;
	dp[0][0] = 0;
	// roundness is determined by minimum (power of 2,  power of 5) of the subset.
	// usually pow5 < pow2
	// dp(i, j ,k) : maximum roundness from index: 1 -> i by take j elements with power of 5 is k;
	// answer will be max of min (i, dp[n][m][i]);
	for (int i = 0; i < n; i++){	
		int pw2 = 0, pw5 = 0;
		ll x = a[i];
		while (x % 2 == 0){
			x /= 2;
			pw2++;
		}
		while (x % 5 == 0){
			x /= 5;
			pw5++;
		}
		FOR(j, 0, MAX - 1) FOR(k, 0, MAXX - 1) tmp[j][k] = -1;
		
		for (int j = 0; j <= m; j++){
			for (int k = 0; k < MAXX; k++){
				if (dp[j][k] < 0) continue;
				tmp[j][k] = max(tmp[j][k], dp[j][k]);
				if (j < m) 
					tmp[j + 1][k + pw5] = max(tmp[j + 1][k + pw5], dp[j][k] + pw2);
			}
		}
		FOR(j, 0, MAX - 1)	FOR(k, 0, MAXX - 1) dp[j][k] = tmp[j][k];
	
	}
	for (int i = 0; i < MAXX; i++) 
		ans = max(ans, min(1LL * i, dp[m][i]));
	cout << ans << '\n';
}
/* problem link: 
	https://codeforces.com/contest/837/problem/D
*/
