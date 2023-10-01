/**    
* LANG: C++ 
* author: atom 
* created: 25.05.2022 11:17:15
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

int n, m;
ll max_e;
vector <ll> a;
pair <ll, ll> d;
ll sum = 0;


bool ok(ll m){
	auto it = lower_bound(all(a), d.F);
	if (it != a.end()){
		it--;
		ll def = sum - *it;
		return (def + m >= d.S);
	}
	else {
		it--;
		ll cost = d.F - *it;
		m -= cost;
		return (sum - *it + m >= d.S);
	}
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	a.resize(n);
	for (ll &i : a) cin >> i, sum += i;
	sort(all(a));

	cin >> m;
	while (m--){
		
		cin >> d.F >> d.S;

		ll ans = 2e18;
		auto it = lower_bound(all(a), d.F);
		if (it != a.end()){
			ans = min(ans, max(0LL, d.S - sum + *it));
		}
		if (it != a.begin()){
			it--;
			ans = min(ans, d.F - *it + max(0LL, d.S - sum + *it));
		}
		cout << ans << '\n';
	}
}
