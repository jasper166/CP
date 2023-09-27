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

ll a, b, n, m;

bool ok(){
 return (a + b >= n + m && m <= min(a, b));
}

void solve(){
	
	cin >> a >> b >> n >> m;
	cout << (ok()? "Yes" : "No") << "\n";
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
