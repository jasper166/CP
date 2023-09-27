/*	
 * 	author: Hiu 
 *  Handle: at0miccat
 */
#include "bits/stdc++.h"
 
using namespace std;
 
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	int n, x; cin >> n >> x;
	long long prefix[n + 1] = {0};
	map<long long, bool> mp;
	for (int i = 1; i <= n; i++){
		int j; cin >> j;
		prefix[i] += prefix[i - 1] + (long long) j;
		mp[prefix[i]] = true;
	}
	int cnt = 0;
	for (int i = 0; i <= n - 1; i++){
		if(mp[prefix[i] + x]) cnt++;
	}
	cout << cnt; 
	return 0;
}
