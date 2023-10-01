/*	
 * 	@Author: Hiu 
 *  @Handle: at0miccat
 */
#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 2;

void toBinary(int x, int n){
	int A[n];
	for (int i = n - 1; i >= 0; i--){
		A[i] = x % 2;
		x /= 2;
	}
	for (int i = 0; i <= n - 1; i++)
		printf("%d", A[i]);
	printf("\n");
}


int orz(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < (1 << n); i++){
		int k = (i ^ (i >> 1));
		toBinary(k, n);
		// printf("%d\n", i);
	}
	return 0;
}
