/**    
* LANG: C++ 
* author: atom 
* created: 25.05.2022 11:46:14
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

int t;
ll n, max_e;
vector <ll> a;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--)	{
		cin >> n;
		a.resize(n);
		for (ll &i : a) cin >> i;
		max_e = *max_element(all(a));
		ll ans = 1e18;
		for (ll need : {max_e, max_e + 1}){

			ll l = 0, r = 1e18, res = 1e18;
			while (l <= r){
				ll m = l + r >> 1;

				ll water_1 = (m / 2) + (m & 1);
				ll water_2 = (m / 2);
				ll need1 = 0;

				for (ll &i : a){
					ll cur_2 = (need - i) / 2;
					if ((need - i) % 2 == 1) need1++;
					if (water_2 >= cur_2) water_2 -= cur_2;
					else {
						cur_2 -= water_2;
						water_2 = 0;
						need1 += 2 * cur_2;
					}

				}
				if (need1 <= water_1){
					res = m;
					r = m - 1;
				}
				else l = m + 1;
			}
			ans = min(ans, res);
		}
		cout << ans << '\n';
	}
}
