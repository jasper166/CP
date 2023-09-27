/*	
 * 	@Author: Hiu 
 *  @Handle: at0miccat
 */
// CF1372 - B
#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
#define MP make_pair
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 2;

void solve(){
	int n;
	cin >> n;
	pair <int, int> ans;
	if (!(n & 1))
		ans = MP(n / 2, n / 2);
	else {
		int k = INT_MAX;
		for (int i = 1; i <= sqrt(n); i++){
			if (n % i == 0){
				k = min(n - i, k);
				if (n - n / i) k = min(n - n / i, k);
			}
		}
		ans = MP(n - k, k);
	}
	cout << ans.F << " " << ans.S << "\n";
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		solve();
	}	
	return 0;
}
