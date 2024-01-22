/*	
 * 	author: Hiu 
 *  Handle: at0miccat
 */
#include "bits/stdc++.h"
 
using namespace std;
// first pos of ele that < x - a;
int pos(vector<int> a, int l, int r, int x){
	int pos = -1;
	while(l <= r){
		int m = (l + r)/2;
		if(a[m] <= x){
			pos = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	return pos;
}
 
 
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >>  n >> m;
	multiset<int> tickets;
	int prices[m];
	for(int i = 0; i <= n - 1; i++){
		int x; cin >> x;
		tickets.insert(x);
	}
	for(int &i : prices) cin >> i;	
	
	for(int i = 0; i <= m - 1; i++){
		auto j = tickets.upper_bound(prices[i]);
		if(j != tickets.begin()){
			j--;
			cout << *j << "\n";
			tickets.erase(j);
		}
		else cout << -1 << "\n";
	}
	return 0;
}
