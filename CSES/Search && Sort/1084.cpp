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
 
int orz(){
 
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int a[n], b[m];
	for (int &i : a) scanf("%d", &i);
	for (int &i : b) scanf("%d", &i);
 
	int ans = 0;
	int i = 0, j = 0;
	sort(a, a + n);
	sort(b, b + m);
 
	while (i <= n - 1 && j <= m - 1){
		if (a[i] >= b[j] - k && a[i] <= b[j] + k){
			ans++;
			i++;
			j++;
		}
		else if (a[i] > b[j] + k) j++;
			 else if (a[i] < b[j] - k) i++;
	}
 
	printf("%d\n", ans);
	return 0;
}
