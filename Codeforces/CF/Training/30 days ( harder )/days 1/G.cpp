/*	
 * 	@Author: Hiu 
 *  @Handle: at0miccat
 */
#include "bits/stdc++.h"
#define orz main
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 2;

void solve(){
	int n, k;
	cin >> n >> k;
	int ans = 1;
	for (int i = 1; i <= sqrt(n); i++){
		if (n % i == 0 && i <= k){
			ans = max(i, ans);
			if (n / i <= k ) ans = max(n / i, ans);
		}
	}
	cout << n / ans << "\n";
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	

	int t; cin >> t;
	while (t--){
		solve();
	}

	return 0;
}
