/**    
* LANG: C++ 
* author: atom 
* created: 23.06.2022 21:05:08
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
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int t, n;
ll a[MAX], dp[MAX][3];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i <= n - 1; ++i) cin >> a[i];

		ll ans = 0;
		FOR(i, 0, n)
			FOR(j, 0, 2) dp[i][j] = 0;

		for (int i = 0; i <= n; i++){
			dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + 1LL * ((i & 1)? 0 : a[i]));
			
			dp[i + 1][2] = max(dp[i + 1][2], max({dp[i][0], dp[i][1], dp[i][2]}) + 1LL * ((i & 1)? 0 : a[i]));
			
			if (i + 2 <= n) 
				dp[i + 2][1] = max(dp[i + 2][1], max(dp[i][0], dp[i][1]) + 1LL * ((i & 1)? a[i] : a[i + 1]));

			FOR(j, 0, 2) ans = max(ans, dp[i][j]);
		}
		cout << ans << '\n';
	}
		 
}
/* problem link: 
	https://codeforces.com/contest/1373/problem/D
*/
// quick observation: 1 .if length of subarray is odd it changed nothing.
		// 2. if reverse 2X length subarray its like X subarray of length 2.
		// if we havent reverse any subarray
		// if we started to reverse but havent ending yet
		// end the reversing