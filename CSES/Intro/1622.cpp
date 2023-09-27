/*	
 * 	@Author: Hiu 
 *  @Handle: at0miccat
 */
#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
#define pii pair<int, int>
 
using namespace std;
using ll = long long;
 
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 2;
 
set <string> st;
int n;
 
void Try(int l, int r, string s){
	for (int j = l; j <= r; j++){
		if (l == r){
			string tmp = "";
			for (int i = 0; i <= n - 1; i++) tmp += (char)(s[i]);
			st.insert(tmp);
		}
		else {
			swap(s[l], s[j]);
			Try(l + 1, r, s);
			swap(s[l], s[j]);
		}
	}
}
 
int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
 
	string s;
	cin >> s;
	n = s.length();	
	Try(0, n - 1, s);
	cout << st.size() << '\n';
	for (auto it : st)
		cout << it << '\n';
	return 0;
}
