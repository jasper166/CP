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
 
void solve(){
	ll n, t;
	scanf("%lld%lld", &n, &t);
	ll a[n];
	for (ll &i : a) scanf("%lld", &i);
	ll l = 0, r = 1e18, ans = -1;
	while (l <= r){
		ll m = (r + l)/ 2;
		ll sum = 0;
		for (ll i : a){
			sum += (m / i);
			if (sum >= t) break;
		} 
		if (sum >= t){
			ans = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	printf("%lld\n", ans);
}	
 
 
int orz(){
 
	solve();
	return 0;
}
