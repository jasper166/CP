#include "bits/stdc++.h"
 
using ll = long long;
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int x, y;
		scanf("%d%d", &x, &y);
		int k = max(x, y);
		ll ans = -1;
		int last = 2 * (k - 1);
		ll val_kk = 1 + (ll)(2 + last) * last / 4;
		if (x == y) ans = val_kk;
		else {
			if (k & 1){
				ans = (x == k)? val_kk - (k - y) : val_kk + (k - x);
			}
			else{
				ans = (x == k)? val_kk + (k - y) : val_kk - (k - x);
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
