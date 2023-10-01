/*	
 * 	@Author: Hiu 
 *  @Handle: at0miccat
 */
#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
#define PII pair<int, int>
#define debug(x) printf(#x " is %d \n", x);
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
 
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 2;
 
int n;
int a[22];
 
int orz(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
 
	scanf("%d", &n);
	for(int &i: a){
		scanf("%d", &i);
	}
	ll ans = 1e18;
	for (int i = 0; i < (1 << n); i++){
		ll sum_a = 0, sum_b = 0;
		for (int j = 0; j <= n - 1; j++){
			if (i & (1 << j)) sum_a += (ll) a[j];
			else sum_b += (ll) a[j];
		}
		ans = min(ans, abs(sum_a - sum_b));
	}
 
	printf("%lld\n", ans); 
}
