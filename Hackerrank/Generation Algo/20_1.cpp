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

int n;
string t;
vector <string> ans;

void panlin_bin(){

	
	for (int i = 1; i <= n / 2; ++i){
		t = string(i, '0');
		bool ok = true;
		while (ok){
			string tmp = string(t.rbegin(), t.rend());
			ans.pb(t + tmp);


			int j = i - 1;
			while (j >= 0 && t[j] == '1') t[j--] = '0';
			if (j == -1) ok = false;
			else t[j] = '1';

		}
	}

	sort (all(ans));
	for (string s : ans) cout << s << '\n';
	
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	panlin_bin();

		 
}
