/**    
* LANG: C++ 
* author: atom 
* created: 03.06.2022 20:47:33
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, s;


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;
	vector <pii> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i].F >> a[i].S;
	// for (int i = 1; i <= n; i++) cout << a[i].F << ' ' << a[i].S << '\n';

	ll dp[n + 1][s + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= s; ++j){
			if (i == 0 || j == 0) dp[i][j] = 0;
			else {
				if (j >= a[i].F){
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].F] + a[i].S);
				}
				else dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][s] << '\n';
}
