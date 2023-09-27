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
	bool flag = false;
	cin >> n >> x;
	int c[n];

	for (int &i : c) cin >> i;
	int dp[x + 1]; 
	dp[0] = 0;
	for (int i = 1; i <= x; i++){
		dp[i] = MAX;
		for (int j = 0; j <= n - 1; j++){
			if (c[j] <= i){
				dp[i] = min(dp[i - c[j]] + 1, dp[i]);
			}
		}
	}
	int ans = (dp[x] != MAX)? dp[x] : -1;
	cout << ans << '\n';
	return 0;
}
    
