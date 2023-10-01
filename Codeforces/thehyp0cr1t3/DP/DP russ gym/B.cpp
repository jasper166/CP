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
constexpr int MAX = 1002;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

char a[MAX];
int n, dp[MAX];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);
	// freopen("lepus.in", "r", stdin);
	// freopen("lepus.out", "w", stdout);

	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	memset(dp, -1, sizeof(dp));
	dp[1] = 0;
	FOR(i, 1, n){
		if (a[i] == 'w') continue;
		int add = 0;
		for (int k = 1; k <= 5; k += 2)
			if (i >= k && dp[i - k] != - 1){
				add = max(add, dp[i - k]);
				dp[i] = 0;
			}
		if (dp[i] == 0 && a[i] == '"') dp[i]++;
		dp[i] += add;
	}
	FOR(i, 1, n) cout << dp[i] << ' ';
	cout << dp[n] << '\n';
		 
}
/* problem link: 

*/
