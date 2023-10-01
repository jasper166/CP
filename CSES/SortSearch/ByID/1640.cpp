/*	
 * 	author: Hiu 
 *  Handle: at0miccat
 */
#include "bits/stdc++.h"
 
using namespace std;
// give a x value, a value in an array. check if x - a exist?
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	
	int n, x;
	cin >> n >> x;
	vector <pair<int, int>> que;
	for(int i = 0; i <= n - 1; i++){
		int j; 
		cin >> j;
		que.push_back({j, i + 1});
	} 
	sort(que.begin(), que.end()); // sort by .first
	// for(int i = 0; i <= n - 1; i++){
	// 	cout << que[i].first << " " << que[i].second << "\n";
	// }
	int l = 0, r = n - 1;
	while(l < r){
		if(que[l].first + que[r].first < x) l++;
		else if(que[l].first + que[r].first > x) r--;
			  else {
			  	cout << que[l].second << " " << que[r].second << "\n";
			  	return 0;
			  }
	}
	cout << "IMPOSSIBLE" << "\n";
 
	return 0;
}
