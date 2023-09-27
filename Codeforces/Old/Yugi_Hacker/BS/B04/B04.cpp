/**    
* LANG: C++ 
* author: atom 
* created: 25.05.2022 10:56:54
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

int t, n;
ll h, k;
vector <int> a;

bool ok(ll m){
	// cout << m << '\n';
	ll dmg = 0;
	for (int i = 0; i <= n - 2; ++i){
		dmg += min(1LL * (a[i + 1] - a[i]), m);
	}
	dmg += m;
	// cout << dmg << '\n';
	return (dmg >= h); 
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	while (t--){
		cin >> n >> h;
		a.resize(n);
		for (int &i : a) cin >> i;
		ll l = 0, r = 1e18;
		while (l <= r){
			ll m = l + r >> 1;
			if (ok(m)){
				k = m;
				r = m - 1;
			}
			else l = m + 1;
		}
		cout << k << '\n';
	}
		 
}
