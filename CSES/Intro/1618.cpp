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
 
int counting(int n){
	int ans = 0;
	int p = 5;
	while ((n / p) > 0){
		ans += (n / p);
		p *= 5;
	}
	return ans;
}
 
int orz(){
	int n;
	scanf("%d", &n);
	printf("%d\n", counting(n));
	return 0;
}
