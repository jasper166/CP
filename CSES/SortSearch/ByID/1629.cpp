/*	
 * 	author: Hiu 
 *  Handle: at0miccat
 */
#include "bits/stdc++.h"
 
using namespace std;
 
struct films{
	int sta, end;
};
 
bool cmp(films a, films b){
	return a.end < b.end;
}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	vector<films> v(n);
 
	for(auto &i : v){
		cin >> i.sta >> i.end;
	}
 
	sort(v.begin(), v.end(), cmp);
	// for (auto i : v) cerr << i.sta << " " << i.ed << "\n";
	int cnt = 1;
	int cur = v[0].end;
	for(int i = 1; i <= n - 1; i++){
		// cur = min(cur, v[i].ed);
		if(v[i].sta >= cur){
			cnt++;
			cur = v[i].end;
		}
	}
	cout << cnt << "\n";
	return 0;
}
