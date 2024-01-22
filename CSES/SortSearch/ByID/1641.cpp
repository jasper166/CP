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
	vector <pair<int, int>> v(n);
	int j = 1;
	for (auto &i : v){
		cin >> i.first;
		i.second = j++;
	}
	sort(v.begin(), v.end());
	bool flag = false;
	for (int i = 0; i <= n - 3; i++){
		int l = i + 1, r = n - 1;
		while(l < r){
			if (v[i].first + v[l].first + v[r].first == x){				
				cout << v[i].second << " " << v[l].second << " " << v[r].second;
				flag = true;
				break;
			}
			else if (v[i].first + v[l].first + v[r].first > x) r--;
			 	 else l++;			
		}
		if (flag) break;	
	}
	if (!flag) cout << "IMPOSSIBLE";
	return 0;
}
