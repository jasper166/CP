/**    
* LANG: C++ 
* author: atom 
* created: 04.06.2022 08:26:50
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
constexpr ll INF = 1e18L + 2; 

#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, w;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> w;
	vector <pii> a(n);
	for (pii &i : a) cin >> i.F >> i.S;
	int sum = 0;
	for (pii i : a) sum += i.S;

	vector <int> dp(sum + 1, MOD);
	dp[0] = 0;
	for (int i = 0; i <= n - 1; i++){
		for (int j = sum - a[i].S; j >= 0; --j){
			dp[j + a[i].S] = min(dp[j + a[i].S], dp[j] + a[i].F);
		}
	}
	int ans = 0;
	for (int i = 0; i <= sum; i++)
		if (dp[i] <= w) ans = max(ans, i);
	cout << ans << '\n';
}
