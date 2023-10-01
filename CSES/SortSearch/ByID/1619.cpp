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
	vector<pair<int, int>> v;
	for(int i = 0; i <= n - 1; i++){
		int arrive, leave;
		cin >> arrive >> leave;
		v.push_back({arrive, 1});
		v.push_back({leave, - 1});
	}
	int ans = 0, cnt = 0;
	sort(v.begin(), v.end());
	for(auto i : v){
		cnt += i.second;
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
