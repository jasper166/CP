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

void solve(){
	int n, l, r;
	cin >> n;
	int a[n];
	for (int &i : a) cin >> i;
	vector <int> ans;
	ans.push_back(a[0]);
	for (int i = 1; i <= n - 2; i++)
		if ((a[i] < a[i + 1] && a[i] < a[i - 1]) || (a[i] > a[i + 1] && a[i] > a[i - 1]))
			ans.push_back(a[i]);
	ans.push_back(a[n - 1]);
	
	int m = ans.size();
	cout << m << "\n";
	for (int i = 0; i <= m - 1; i++) 
		cout << ans[i] << " ";
}	


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	

	int t; cin >> t;
	while (t--){
		solve();
		cout << "\n";
	}
	return 0;
}
