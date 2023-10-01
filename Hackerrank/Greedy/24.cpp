/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 09:56:51
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
	int odd = 0;
	map <char, int> mp;
	for (char c : s)
		mp[c]++;
	for (auto it : mp)
		if (it.S & 1) odd++;
	int ans = (odd == 2 || odd == 0 || odd == 1 || (odd & 1 && odd > 1)) 1 : 2;
	cout << ans << '\n';
}
