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
	double a[2][2];
}Matrix;

Matrix myMulti(Matrix A, Matrix B){
	Matrix ans;
	FOR(i, 0, 1) FOR(j, 0 , 1) FOR(k, 0 , 1)
		ans.a[i][j] += A.a[i][k] * B.a[k][j];
	return ans;
}

Matrix myPow(Matrix A, int k){
	Matrix ans;
	FOR(i, 0 , 1) ans.a[i][i] = 1;
	while (k){
		if (k & 1) ans = myMulti(ans, A);
		A = myMulti(A, A);
		k >>= 1;
	}
	return ans;
}

int main(){

	int n;
	double p;
	scanf("%d%lf", &n, &p);

	Matrix base;
	base.a[0][0] = 1 - p;
	base.a[0][1] = p;
	base.a[1][0] = p;
	base.a[1][1] = 1 -p;

	Matrix ans = myPow(base, n);
	printf("%.10lf\n", ans.a[0][0]);
	
}