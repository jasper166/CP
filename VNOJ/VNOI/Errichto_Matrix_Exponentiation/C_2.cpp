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
	ans.a[0][0] = ans.a[0][1] = ans.a[1][0] = ans.a[1][1] = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; k++){
				ans.a[i][j] += (A.a[i][k] * B.a[k][j]);
				ans.a[i][j] %= MOD;
			}
	return ans;
}


Matrix myPow(Matrix A, ll n){
	Matrix ans;
	ans.a[0][0] = ans.a[0][1] = ans.a[1][0] = ans.a[1][1] = 0;
	for (int i = 0; i < 2; ++i) ans.a[i][i] = 1;
	while (n){
		if (n & 1) ans = myMulti(A, ans);
		A = myMulti(A, A);
		n >>= 1;
	}
	return ans;
}



int main(){

	ll n;
	scanf("%lld", &n);
	Matrix ans, coe;
	coe.a[0][0] = 0;
	coe.a[0][1] = 1;
	coe.a[1][0] = 1;
	coe.a[1][1] = 1;
	if (n == 0) printf("%d\n", 0);
	else {
		ans = myPow(coe, n - 1);
		printf("%lld\n", ans.a[1][1]);
	}
	
}