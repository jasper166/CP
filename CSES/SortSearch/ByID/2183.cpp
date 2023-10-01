/*	
 * 	author: Hiu 
 *  Handle: at0miccat
 */
#include "bits/stdc++.h"
 
using namespace std;
 
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int a[n];
	for (int &i : a) cin >> i;
	sort (a, a + n);
 
	long long ans = 1;
	for (int i = 0; i <= n - 1; i++){
		if(ans < a[i]) break;
		ans += (long long) a[i];
	}
	cout << ans; 
	return 0;
}
