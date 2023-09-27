/**    
* LANG: C++ 
* author: atom 
* created: 19.05.2022 23:53:48
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

ll a, b;

bool ok(ll x){
	string s = to_string(x);
	for (int i = 1; i <= (int) s.size() - 2; ++i){
		if (s[i - 1] == s[i] || s[i] == s[i + 1]) return false;
	}
	return true;
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a >> b;
	int ans = 0;
	for (ll i = a; i <= b; i++)
		if (ok(i)) ans++;
	cout << ans << '\n';
}
