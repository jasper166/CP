/*	
 * 	@Author: Hiu 
 *  @Handle: at0miccat
 */
#include "bits/stdc++.h"
#define orz main
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e9 + 2;

void solve(){
	int n, k, l;
	string s;
	cin >> n >> k >> s;
	int cnt = 0;

	string zero (k, '0');
	s = zero + s;
	s = '1' + s;
	s += zero;
	s += '1';
	// cout << s << "\n";
	for (int i = 0; i <= n - 1;){
		int j = i;
		while (s[j + 1] == '0') j++;
		j++;
		cnt += (j - i + 1 + k) / (k + 1) - 2;
		i = j;
	}

	cout << cnt << "\n";
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--){
		solve();
	}
	return 0;
}
