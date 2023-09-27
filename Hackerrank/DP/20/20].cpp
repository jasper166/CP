/**    
* LANG: C++ 
* author: atom 
* created: 18.05.2022 22:48:39
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


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int a[n];
	int sum = 0;
	for (int &i : a) cin >> i, sum += i;
	bool dp[n + 1][sum + 1];
	memset(dp, false, sizeof(dp));
	for (int i = 0; i <= n; i++) dp[i][0] = true;
	
	for (int i = 1; i <= n; i++){
		dp[i][a[i - 1]] = true;
		for (int j = 1; j <= sum; ++j){
			if (dp[i - 1][j] = true){
				dp[i][j] = true;
				dp[i][j + a[i - 1]] = true;
			}
		}
	}
	for (int i = 0; i <= sum; ++i)
		if (dp[n][i]) cout << i << ' ';
	puts("");
}
