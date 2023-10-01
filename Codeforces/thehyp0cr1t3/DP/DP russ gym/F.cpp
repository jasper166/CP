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
constexpr int MAX = 3e5 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int t, n;
int dp[MAX];
int a[152];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> t;
	dp[0] = 0;
	FOR(i, 1, 150){
		a[i] = a[i - 1] + (i * (i + 1) / 2); 
	}
	FOR(i, 1, MAX - 1){
		dp[i] = MAX;
		for (int x : a){
			if (i < x) break;
			dp[i] = min(dp[i - x] + 1, dp[i]);
		}
	}
	// FOR(i, 1, 10) cout << a[i] << ' ' << dp[i] << '\n';
	while (t--){
		cin >> n;
		cout << dp[n] << '\n';
	}

		 
}
/* problem link: 

*/
