/**    
* LANG: C 
* author: atom 
* created: 11.06.2022 07:02:33
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


bool flag;
ll d, p;

bool ok(ll m){
	ll x = d / m;
	ll y = d - x * m;
	if (y) flag = true;
	return (m * (x * x) + y * y <= p);
}

int count(char *x, char *y){
	int n = strlen(x);
	int m = strlen(y);
	int i, j, flag = 0, ans = 0;
	for (i = 0; i <= n - m;){
		flag = 1;
		for (j = 0; j < m; j++){
			if (x[i + j] != y[j]){
				flag = 0;
				break;
			}
		}
		if (flag){
			ans++;
			i = i + m;
		}
		else i++;
	}
	return ans;
}

int main(){
	int t;
	char s[1002], x[1002];
	scanf("%d\n", &t);
	while (t--){
		scanf("%s%s", s, x);
		printf("%d\n", count(s, x));
	}
}