/**    
* LANG: C 
* author: atom 
* created: 10.06.2022 23:52:30
**/
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

int t, n, k;

int main(){

	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &k);
		ll L = 0, R = 1e18, ans = 1e18;
		while (L <= R){
			ll mid = (L + R) >> 1;
			if (mid - mid / n >= k){
				ans = mid;
				R = mid - 1;
			}
			else L = mid + 1;
		}
		printf("%lld\n", ans);
	}

}