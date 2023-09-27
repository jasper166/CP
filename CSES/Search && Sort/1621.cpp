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
	set<int> s;
	for(int i = 1; i <= n; i++){
		int j; cin >> j;
		s.insert(j);
	}
	cout << s.size() << "\n";
 
	return 0;
}
