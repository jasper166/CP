/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 01:21:11
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


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();
	map <char, int> a;
	for (char c : s) a[c]++;
	bool flag = true;
	for (auto it : a)
		if (it.S > (n + 1) / 2) flag = false; 
	cout << ((flag && a.size() > 1)? "YES" : "NO") << '\n'; 
}
