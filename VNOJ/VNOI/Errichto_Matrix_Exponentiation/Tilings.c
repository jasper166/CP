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

const ll MOD = 111539786;

typedef struct Matrix{
	ll a[2][2] = {0};
}Matrix;


Matrix myMulti(Matrix A, Matrix B){
	Matrix ans;
	memset(ans.a, 0, sizeof(ans.a));
	FOR(i, 0, 1) FOR(j, 0 , 1) FOR(k, 0 , 1){
		ans.a[i][j] += A.a[i][k] * B.a[k][j];
		ans.a[i][j] %= MOD;
	}
	return ans;
}

Matrix myPow(Matrix A, ll k){
	Matrix ans;
	memset(ans.a, 0, sizeof(ans.a));
	FOR(i, 0 , 1) ans.a[i][i] = 1;
	while (k){
		if (k & 1) ans = myMulti(ans, A);
		A = myMulti(A, A);
		k >>= 1;
	}
	return ans;
}

int main(){

	int t;
	scanf("%d", &t);
	while (t--){
		ll n;
		scanf("%lld", &n);

		Matrix base;
		base.a[0][0] = 0;
		base.a[0][1] = 1;
		base.a[1][0] = 1;
		base.a[1][1] = 1;

		Matrix ans = myPow(base, n);
		if (n) printf("%lld\n", ans.a[1][1]);
		else printf("0\n");	
	}
	
}