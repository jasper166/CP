#include "bits/stdc++.h"
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
 
 
ll myPow(ll a, ll b){
	ll ans = 1;
	while (b){
		if (b & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}	
	return ans;
}
 
int main(){
	ll n;
	scanf("%lld", &n);
	printf("%lld\n", myPow(2, n));
}
