/*	
 * 	@Author: Hiu 
 *  @Handle: at0miccat
 */
#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
#define pii pair<int, int>
 
using namespace std;
using ll = long long;
 
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 2;
 
 
int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
 
	int n;
	cin >> n;
	ll dp[n];
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++){
		dp[i] = 0;
		for (int j = 1; j <= 6; j++)
			if (i - j >= 0) dp[i] = (dp[i] + dp[i - j]) % MOD;
	}
	cout << dp[n] << '\n';
	return 0;
}
