/*	
 * 	author: Hiu 
 *  Handle: at0miccat
 */
#include "bits/stdc++.h"
 
using namespace std;
 
//kadane
 
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int arr[n];
	for (int &i : arr) cin >> i;
	long long ans = -1e9;
	long long curr = 0;
	for (int i : arr){
		if(curr < 0) curr = 0;
		curr = max((long long) i, (long long) curr + i);
		ans = max(ans, curr);
	}	
	cout << ans;
	return 0;
}
