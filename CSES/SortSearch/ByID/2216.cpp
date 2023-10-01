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
	vector<pair<int, int >> v(n);
	int j = 1;
	for (auto &i : v){
		cin >> i.first;
		i.second = j++;
	}
	sort(v.begin(), v.end());
	int cnt = 0, ans = n;
	for (int i = 0; i <= n - 2; i++){
		if(v[i].first < v[i + 1].first && v[i].second < v[i + 1].second) cnt++;
	}
	if(cnt > 0) ans -= cnt;
	cout << ans; 
	return 0;
}
