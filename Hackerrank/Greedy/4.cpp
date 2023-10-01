/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 01:21:11
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

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	ll a[n];
	ll sum = 0, ans1 = 0, ans2 = 0;
	for (ll &i : a) cin >> i, sum += i;
	sort(a, a + n);
	ans1 = sum - 2 * accumulate(a, a + k, ans1);
	debug(ans1);
	ans2 = sum - 2 * (sum - accumulate(a + n - k, a + n, ans2));
	debug(ans2);
	cout << max(ans1, ans2) << '\n'; 
		 
}
