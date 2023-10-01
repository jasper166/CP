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
const int MAX = 1e6 + 2;


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n >> x;
	int c[n];
	for (int &i : c) cin >> i;
	int dp[x + 1];
	memset(dp, 0, sizeof(dp));
	for (int i : c){
		if (i <= x) dp[i] = 1;
	}
	for (int i = 1; i <= x; i++){
		for (int j = 0; j <= n - 1; j++){
			if (i - c[j] >= 0) 
				dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
		}
	}
	cout << dp[x] << '\n';
	return 0;
}
    
