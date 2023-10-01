#include "bits/stdc++.h"
#define ll long long
using namespace std;
 
 
ll knight(ll n){
	ll ans = (ll) (n * n) * (n * n - 1) / 2;
	ll bad = (ll) (n - 1) * (n - 2) * 4;
	return ans - bad;
}
 
int main(){
	ll n;
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++)
		printf("%lld\n", knight(i));
}
