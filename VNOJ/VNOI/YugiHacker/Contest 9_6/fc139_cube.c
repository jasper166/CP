/**    
* LANG: C 
* author: atom 
* created: 12.06.2022 09:31:59
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


int cube(int x){
	int dp[1002];
	int prefix[1002];
	prefix[0] = 0;
	dp[0] = 0;
	for (int i = 1; i <= 1001; i++){
		dp[i] = dp[i - 1] + i;
		prefix[i] = prefix[i - 1] + dp[i - 1];
	}
	int ans = 1;
	FOR(i, 1, 1002) {
		if (prefix[i] <= x) ans = i - 1;
		else break;
	}
	return ans;
}


int main(){

	int n;
	scanf("%d", &n);
	printf("%d\n", cube(n));

}