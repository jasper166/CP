/**    
* LANG: C++ 
* author: atom 
* created: 24.06.2022 15:15:34
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
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
constexpr int MAXN = 105;
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n;
vector <pii> ar(MAXN + 1);
int k, t, sum = 0;
int dp[MAXN][MAXN * MAXN];
// dp(i, j) with i maximum possible amount of water

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);


	cin >> n;
	FOR(i, 0, n - 1){
		cin >> ar[i].F;
		sum += ar[i].F;
	}

	FOR(i, 0, n - 1) cin >> ar[i].S;
	
	sort(all(ar), [&] (const pii &a, const pii &b){
		return a.S > b.S;
	});

	int l = 0, sum2 = sum;
	while (l < n && sum > 0){
		sum -= ar[l].S;
		k++;
		l++;
	}
	// greedy the bottles

	FOR(i, 0, MAXN - 1)
		FOR(j, 0, MAXN * MAXN - 1) dp[i][j] = -MOD;
	
	dp[0][0] = 0;

	for (int i = 0; i < n; ++i){
		for (int j = n - 1; j >= 0; j--){
			for (int r = 0; r + ar[i].S < MAXN * MAXN; r++)
				dp[j + 1][r + ar[i].S] = max(dp[j + 1][r + ar[i].S], dp[j][r] + ar[i].F);
		}
	}

	
	int res = 0;
	FOR(i, sum2, MAXN * MAXN - 1) res = max(res, dp[k][i]);
	t = sum2 - res;
	// cout << sum2 << '\n';
	cout << k << ' ' << t << '\n' ;
	 
}
/* problem link: 
	https://codeforces.com/problemset/problem/730/J
*/
