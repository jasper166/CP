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


ll f[93];

ll ans(ll n, ll k){
	if (n == 2) return 1;
	if (n == 1) return 0;
	if (k <= f[n - 2]) return ans(n - 2, k);
	else return ans(n - 1, k - f[n - 2]);
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, k;
	cin >> n >> k;

	f[1] = f[2] = 1;
	for (int i = 3; i <= 92; i++) f[i] = f[i - 1] + f[i - 2];
	cout << ans(n , k) << '\n';
}
