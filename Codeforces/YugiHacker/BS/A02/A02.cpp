/**    
* LANG: C++ 
* author: atom 
* created: 18.05.2022 13:56:33
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
	
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int &i : a) cin >> i;
	
	ll l = 0, r = 1e18, res = 1e18;
	while (l <= r){
		ll m = (r + l) / 2;
		ll cnt = 0;
		for (int i : a){
			cnt += 1ll * (i / m);
			if (cnt >= k) break;
		}
		if (cnt >= k){
			res = m;	
			l = m + 1;
		}
		else r = m - 1;
	}	 
	cout << res << '\n';
}
