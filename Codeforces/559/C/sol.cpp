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
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
int fac[N], inv[N];

ll bPow(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ans;
}

ll C(int n, int k) {
	if (n < k) return 0;
	return ((1LL * fac[n] * inv[k]) % MOD * inv[n - k]) % MOD;
}

void prepare() {
	fac[0] = 1;
	for (int i = 1; i < N; ++i) 
		fac[i] = (1LL * fac[i - 1] * i) % MOD;

	inv[N - 1] = bPow(fac[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; --i)
		inv[i] = (1LL * inv[i + 1] * (i + 1)) % MOD;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    prepare();
	
	int n, m, k;
	cin >> n >> m >> k;

	vector <pair <int, int>> a(k);
	for (auto& [x, y] : a) cin >> x >> y;

	sort(a.begin(), a.end());
	
	vector <ll> dp(k, 0); // number of distinct invalid way to reach cell(i)
	ll ans = C(n + m - 2, n - 1);
	ll invalid = 0;
	for (int i = 0; i < k; ++i) {
		auto [x, y] = a[i];
		ll fp = C(x + y - 2, x - 1);
		for (int j = 0; j < i; ++j) {
			auto [_x, _y] = a[j];
			if (_x <= x && _y <= y) {
				ll excl = 1LL * dp[j] * C(x - _x + y - _y, x - _x) % MOD;
				fp = (fp - excl + MOD) % MOD;
			}
		}
		ll sp = C(n - x + m - y, n - x); // number of distinct invalid way to reach cell(n, m) from current cell(x, y);
		dp[i] = fp;
		invalid = (invalid + 1LL * fp * sp % MOD) % MOD;
	}

	ans = (ans - invalid + MOD) % MOD;
	cout << ans << "\n";
}

