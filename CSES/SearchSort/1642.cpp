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
 
	for (int i = 0; i <= n - 4; i++){
		for (int j = i + 1; j <= n - 3; j++){
		int l = j + 1, r = n - 1;
		
		while (l < r){
			if (v[i].first + v[j].first + v[l].first + v[r].first == x){				
				cout << v[i].second << " " << v[j].second << " " << v[l].second << " " << v[r].second;
				return 0;
				}
			else if (v[i].first + v[j].first + v[l].first + v[r].first > x) r--;
			 	 else l++;			
			}	
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}
