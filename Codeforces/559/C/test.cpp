#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
const int MOD = 1e9 + 7;

ll bPow(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	} 
	return ans;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int n;
    cin >> n;

    vector <int> p(n), m(n);
    for (int i = 0; i < n; ++i) cin >> p[i] >> m[i];

    ll ans_cnt = 1, ans_sum = 1, ans_prod = 1, c = 1;
	for (int i = 0; i < n; ++i) {
		ans_cnt = (ans_cnt * 1LL * (m[i] + 1)) % MOD;

		ll x = (bPow(p[i], m[i] + 1) - 1);
		ll y = (bPow(p[i] - 1, MOD - 2));
		ans_sum = ((ans_sum * x) % MOD * y) % MOD;
	
		ans_prod = bPow(ans_prod, m[i] + 1);
		x = bPow(bPow(p[i], 1LL * m[i] * (m[i] + 1) / 2), c) % MOD;
		ans_prod = (ans_prod * x) % MOD;
		c = (c * 1LL * (m[i] + 1)) % (MOD - 1);
	}

	cout << ans_cnt << " " << ans_sum << " " << ans_prod << "\n";
}

