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

int al, ar, l, r;

void solve(){
	int n, x, m;	
	cin >> n >> x >> m;
	al = ar = x;
	while (m--){
		cin >> l >> r;
		if (l <= al && al <= r)
			al = min(l, al);
		if (l <= ar && ar <= r)
			ar = max(ar, r);
	}
	cout << ar - al + 1 << "\n";
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
