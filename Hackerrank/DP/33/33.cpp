/**    
* LANG: C++ 
* author: atom 
* created: 19.06.2022 20:24:33
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
constexpr int MAX = 1e7 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int dp[1001][1 << 12];


void nextMask(int cur_mask, int i, int next_mask, int n, vector <int> & nMask){

	if (i == n + 1){
		nMask.pb(next_mask);
		return;
	}
	if ((cur_mask & (1 << i)))
		nextMask(cur_mask, i + 1, next_mask, n, nMask);
	else 
		nextMask(cur_mask, i + 1, next_mask + (1 << i), n, nMask);

	if (i != n && ((cur_mask & (1 << i)) == 0) && ((cur_mask & (1 << (i + 1))) == 0)){
		nextMask(cur_mask, i + 2, next_mask, n, nMask);
	}	
}

int solve(int c, int mask, int n, int m){
	if (c == m + 1){
		return (mask == 0);
	}
	if (dp[c][mask] != -1) return dp[c][mask];
	int ans = 0;
	vector <int> nMask;
	nextMask(mask, 1, 0, n, nMask);

	for (int i : nMask) ans = (ans + solve(c + 1, i, n, m)) % MOD;
	
	dp[c][mask] = ans;
	return ans; 
}


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	int n, m; 
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	cout << solve(1, 0, n, m) << '\n';
		 
}
