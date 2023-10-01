/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 16:33:11
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int t, n = 19, ok = 1;
ll res[302];
string s;
vector <string> ans;

void gen(){
	s = string(n, '0');
	s[n - 1] = '8';


	while (ok){
		ans.pb(s);

		int i = n - 1;
		while (i >= 0 && s[i] == '8'){
			s[i] = '0';
			--i;
		}
		if (i == -1) ok = 0;
		else s[i] = '8';
	}
	for (ll i = 1; i <= 300; ++i)
		for (string s : ans)
			if (stoll(s) % i == 0){
				res[i] = stoll(s);
				break;
			}
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	gen();
	cin >> t;
	while (t--){
		int x;
		cin >> x;
		cout << res[x] << '\n';
	}
		 
}
