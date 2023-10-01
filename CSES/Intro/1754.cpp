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
 
 
bool ok(int x, int y){
 
	int a = max(x, y), b = min(x, y);
	if ((a + b) % 3 != 0) return false;
	if (b >= (a + b) / 3) return true;
	return false;
 
}
 
int orz(){
 
	int n;
	scanf("%d", &n);
	while (n--){
		int x, y;
		scanf("%d%d", &x, &y);
		printf(ok(x, y)? "YES\n" : "NO\n"); 
	}
 
	return 0;
}
