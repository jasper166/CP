#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define max(a,b) (a > b)? a : b;
#define min(a,b) (a < b)? a : b;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define cin(a) scanf("%d", &a)
#define cout(a) printf("%d ", a)
#define el printf("\n")
typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;
const int MAX = 1e6;

int t;


ll solve(ll low, ll high){

	for (int i = 40; i >= 1; i--){
		ll l = 0 , r = 1LL * pow(high, 1.0 / i) + 10;
		while (l <= r){
			ll m = (l + r) / 2;
			ll ans = 1;
			for (int k = 0; k < i; k++){
				ans *= m;
				if (ans >= low) break;
			}
			if (ans >= low) r = m - 1;
			else l = m + 1;
		}
		ll ans = 1;
		for (int k = 0; k < i; k++){
			ans *= l;
			if (ans > high) break;
		} 
		if (low <= ans && ans <= high) return i;
	}
}


int main(){

	scanf("%d", &t);
	FOR(i, 1, t) {
		ll l, r;
		scanf("%lld%lld", &l, &r);
		printf("Case #%d: %lld\n", i, solve(l, r));
	}
	
}