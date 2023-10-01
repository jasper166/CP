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

int t, n, m;

int main(){

	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		int a[n + 1][m + 1];
		int R[1002][3] = {0};
		int C[1002][3] = {0};
		for (int i = 1; i <= n; i++){
			char s[1002];
			scanf("%s", s);
			for (int j = 1; j <= m; j++){
				a[i][j] = s[j - 1] - '0';
				// printf("%d", a[i][j]);
				R[i][a[i][j]]++;
				C[j][a[i][j]]++;
			}	
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (a[i][j] == 1)
					 ans += 1LL * R[i][2] * C[j][2];
				else if (a[i][j] == 2)
					 ans += 1LL * R[i][1] * C[j][1];
			}
		}
		printf("%lld\n", ans);
	}


	return 0;
}