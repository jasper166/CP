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
constexpr int MAX = 102;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, dp[MAX], a[MAX];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	freopen("ladder.in", "r", stdin);
	freopen("ladder.out", "w", stdout);
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	dp[0] = 0;
	dp[1] = a[1];
	FOR(i, 2, n)
		dp[i] = max(dp[i - 1], dp[i - 2]) + a[i];
	cout << dp[n] << '\n';
		 
}
/* problem link: 

*/
