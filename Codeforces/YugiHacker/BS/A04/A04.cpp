/**    
* LANG: C++ 
* author: atom 
* created: 21.05.2022 17:11:44
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

ll n, s;

int dig_sum(ll m){
	int ans = 0;
	while (m){
		ans += (m % 10);
		m /= 10;
	}
	return ans;
}

bool ok(ll m){
	return (m - dig_sum(m) >= s);
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;

	ll l = 0, r = n, ans = 0;
	while (l <= r){
		ll m = (r + l) / 2;
		if(ok(m)){
			ans = n - m + 1;
			r = m - 1;
		}
		else l = m + 1;
	}
	// cout << dig_sum(n) << '\n';
	cout << ans << '\n';
}
