/*	
 * 	@Author: Hiu 
 *  @Handle: at0miccat
 */
#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
#define debug(x) cout << #x << " : " << x << "\n";
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 2;

bool cmp(pair <char, int> a, pair <char, int> b){
	return (!(a.S & 1) && (b.S & 1));
}

void reorder(string s){
	int n = s.length();
		map <char, int> mp;
		int cnt = 0;
		for (int i = 0; i <= n - 1; i++)
			mp[(char)s[i]]++;
		for (auto it : mp)
			if (it.S & 1) cnt++;
		if ((cnt > 1 && n & 1) || cnt && !(n & 1)){
			cout << "NO SOLUTION";
			return;
		}
		vector <pair<char, int > > v(mp.begin(), mp.end());
		sort(v.begin(), v.end(), cmp);
		char ans[n];
		for (int k = 0, i = 0; k <= v.size() - 1; k++){
			while (v[k].S > 0){
				ans[i] = ans[n - 1 - i] = v[k].F;
				v[k].S -= 2;
				i++;
			}
		} 
		for (auto i : ans) cout << i;
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);

	string s; cin >> s;
	reorder(s);

	return 0;
}
