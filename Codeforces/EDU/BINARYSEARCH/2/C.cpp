/*	
 * 	@Author: Hiu 
 *  @Handle: at0miccat
 */
#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 2;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);

	ll n, x, y;
	cin >> n >> x >> y;

	ll time = min(x, y);
	ll l = 0, r = 1ll * max(x, y) * n;
	n--;
	ll ans = r; 
	while (l <= r){
		ll m = (r + l) / 2;
		if (m / x + m / y >= n){
			ans = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	cout << ans + time << '\n';
	return 0;
}