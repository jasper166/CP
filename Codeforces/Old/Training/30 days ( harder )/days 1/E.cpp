/*	
 * 	@Author: Hiu 
 *  @Handle: at0miccat
 */
#include "bits/stdc++.h"
#define orz main
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 2;

int a[502], b[502], z, o;

bool isSort(int n){
	for (int i = 0; i <= n - 2; i++)
		if (a[i] > a[i + 1]) return false;
	return true;
}

bool ok(int n){
	if (isSort(n)) return true;
	return (!o || !z);
}

void solve(){
	int n;
	cin >> n;
	o = z = 0;
	for (int i = 0; i <= n - 1; i++){
		cin >> a[i];
	}
	for (int i = 0; i <= n - 1; i++){
		cin >> b[i];
		if (b[i]) o++;
		else z++;
	}
	cout << (ok(n)? "Yes" : "No") << "\n";
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
