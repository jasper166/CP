/**    
* LANG: C++ 
* author: atom 
* created: 24.05.2022 22:33:19
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

ll n, k;
vector <ll> prime;

ll myPow(ll a, ll b, ll m){
	a %= m;
	ll ans = 1;
	while (b){
		if (b & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1; 
	}
	return ans;
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	ll m;
	cin >> n >> k >> m;

	// seg_sieve(n - k + 1, n + 1);
	bool flag = true;
	ll ans = 1;
	for (ll i = n - k + 1; i <= n + 1; ++i){
		ll j = i;
		if (j % (k + 1) == 0) j /= (k + 1);
		j %= m;
		ans *= j;
		ans %= m;
	}
	cout << ans << '\n';
}
