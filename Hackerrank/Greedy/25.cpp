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

int n;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	vector <ll> a(n);
	for (ll &i : a) cin >> i;
	sort(all(a));

	ll sum = a[0];
	auto it = lower_bound(a.begin() + 1, a.end(), sum);
	sum += *it;
	int j = it - a.begin();
	int ans = 1;
	debug(sum);
	while (it != a.end()){
		it = lower_bound(a.begin() + j, a.end(), sum);
		sum += *it;
		j = it - a.begin();
		ans++;
	}
	cout << ans << '\n';
}
