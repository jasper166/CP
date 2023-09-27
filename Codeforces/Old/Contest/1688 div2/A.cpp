/**    
* LANG: C++ 
* author: atom 
* created: 03.06.2022 20:00:36
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

int t, x;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--){
		cin >> x;
		int ans = 0, i = 0;
		if (x & 1){
			if (x == 1) ans = x + 2;
			else ans = (x & 1);
		}
		else {
			if (__builtin_popcount(x) == 1) ans = x + 1;
			else ans = x & -x;
		}
		cout << ans << '\n';
	}
					 
}
