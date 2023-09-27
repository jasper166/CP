/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 14:56:55
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


string s;
int n;

bool check(){
	if (s[0] != '8' || s[n - 1] != '6') return false;
	if (s.find("88") != string:: npos) return false;
	if (s.find("6666") != string:: npos) return false;
	return true;
}	

void gen(){
	s = string(n, '6');
	bool ok = true;

	while (ok){

		if (check()) cout << s << '\n';
		
		int i = n - 1;
		while (i >= 0 && s[i] == '8'){
			s[i] = '6';
			--i;
		}
		if (i == -1) ok = false;
		else s[i] = '8';
	}

}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	gen();
		 
}
