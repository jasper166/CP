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

typedef struct Matrix{
	ll a[2][2];
}Matrix;

Matrix myMulti(Matrix A, Matrix B){
	Matrix ans;
	FOR(i, 0, 1) FOR(j, 0 , 1) ans.a[i][j] = 0;
	FOR(i, 0, 1) FOR(j, 0 , 1) FOR(k, 0, 1){
		ans.a[i][j] += A.a[i][k] * B.a[k][j];
		ans.a[i][j] %= MOD;
	}
	return ans;
}



Matrix myPow(Matrix A, ll k){
	Matrix ans;
	ans.a[1][0] = ans.a[0][1] = 0;
	FOR(i, 0, 1) ans.a[i][i] = 1;
	while (k){
		if (k & 1) ans = myMulti(ans, A);
		A = myMulti(A, A);
		k >>= 1;
	}
	return ans;
}

int main(){

	ll n;
	scanf("%lld", &n);
	Matrix ans, coe;
	coe.a[0][0] = 19;
	coe.a[0][1] = 6;
	coe.a[1][0] = 7;
	coe.a[1][1] = 20;

	ans = myPow(coe, n);	
	printf("%lld\n", ans.a[0][0]);
	
}