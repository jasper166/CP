/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 20:07:26
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

char c;
string s = "";
int n;
bool ok(string a){
	bool a_check = true , e_check = true;
	for (int i = 0; i <= n - 1; ++i){
		if (s[i] == 'A') {
			if (i != 0 && i != n - 1) a_check = false;
		}
		if (s[i] == 'E') e_check = !(i != 0 && i != n - 1);	
	}
	bool flag = false;
	if (s.find("AE") != string:: npos) flag = true;
	else if (s.find("EA") != string:: npos) flag = true;
	
	return ((a_check && e_check) || flag);
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> c;
	for (char x = 'A'; x <= c; x++) s += x;
	n = s.size();
	// cout << s << '\n';
	do {
		if (ok(s)) 	cout << s << '\n';
	}
	while (next_permutation(all(s)));
}
