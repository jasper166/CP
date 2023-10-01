/**    
* LANG: C++ 
* author: atom 
* created: 05.06.2022 23:39:56
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
	vector <pair<pii, int>> v(n);
	for (auto &i : v)
		cin >> i.F.F >> i.F.S >> i.S;
	sort(all(v), [&] (const pair<pii, int> &a, const pair<pii, int> & b){ return a.F.S < b.F.S; });

	ll best = 0;
	map <int, ll> dp;
	dp[0] = 0;
	for (auto i : v){
		auto it = dp.lower_bound(i.F.F);
		it--;

		ll cur = it->S + i.S;
		best = max(cur, best);
		dp[i.F.S] = best;
	}
	cout << best << '\n';
}
