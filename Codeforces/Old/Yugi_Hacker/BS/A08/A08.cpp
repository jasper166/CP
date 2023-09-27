/**    
* LANG: C++ 
* author: atom 
* created: 21.05.2022 21:33:29
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

int n, k;
string s;

bool ok(int m){
	map <string, int> mp;
	int res = 1;
	for (int i = 0; i <= n - m; i++){
		string tmp = s.substr(i, m);
		mp[tmp]++;
		res = max(res, mp[tmp]);
		if (res >= k) return true;
	}
	return (res >= k);
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k >> s;

	int l = 0, r = n, ans = 0;
	while (l <= r){
		int m = (l + r) / 2;
		if (ok(m)){
			ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}	
	cout << ans << '\n';
}
