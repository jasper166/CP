/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 20:35:43
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

bool ok(string s){
	int c = 0;
	for (int i = 0; i <= n - 1; ++i){
		if (s[i] == '1') c++;
		else{
			c--;
			if (c < 0) return false;
		}
	}
	return c == 0;
}


void parentheses(){
	if (n & 1) cout << "NOT FOUND\n";
	else {
		vector <string> ans;
		bool flag = false;
		for (int i = 0; i <= (1 << n) - 1; ++i){
			string tmp = "";

			for (int  j = 0; j <= n - 1; j++){
				if (i & (1 << j)) tmp = "1" + tmp;
				else tmp = "0" + tmp;
			}
			if (ok(tmp)) ans.pb(tmp), flag = true;
		}
		if (!flag) cout << "NOT FOUND\n";
		else {
			sort(all(ans), greater <string> ());
			for (string s : ans){
				for (int i = 0; i <= n - 1; i++){
					s[i] = (s[i] == '1')? '(' : ')';
					cout << s[i];
				}
				cout << '\n';
			}
		}


	}
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	parentheses();
		 
}
