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

ll myPow(ll a, ll b){
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
	ll n;
	cin >> n;
	cout << myPow(2, n - 1) << '\n';
}
