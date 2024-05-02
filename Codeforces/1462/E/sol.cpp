#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
int fac[N + 5], inv[N + 5];

ll bPow(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ans;
}

void prepare() {
	fac[0] = 1;
	for (int i = 1; i < N; ++i)
		fac[i] = (1LL * fac[i - 1] * i) % MOD;
	inv[N - 1] = bPow(fac[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; --i) 
		inv[i] = (1LL * inv[i + 1] * (i + 1)) % MOD;
}

int C(int n, int k) {
	if (n < k) return 0;
	return (1LL * (1LL * fac[n] * inv[n - k]) % MOD * inv[k]) % MOD;
}

int n, m, k;
int a[N];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

	
	prepare();
	int T; cin >> T;

	vector <int> cnt(N, 0), prf(N, 0);
	while (T--) {
		cin >> n >> m >> k;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		
		for (int i = 1; i <= n; ++i) cnt[a[i]]++;

		for (int x = 1; x <= n; ++x) prf[x] = (prf[x - 1] + cnt[x]);

		ll ans = 0;
		// Fix minimum of the tuples : x	
		for (int x = 1; x <= n; ++x) {
			int mx = min(n, x + k); // maximum of the tuples, can choose between(x, mx);
			int take = prf[mx] - prf[x - 1];
			// subtract overlapping tuples that not take x as minimum
			int not_take = prf[mx] - prf[x];
			ans = (ans + C(take, m) - C(not_take, m) + MOD) % MOD;
		}
		// debug(MOD);
		cout << ans << "\n";

		for (int x = 1; x <= n; ++x) cnt[x] = 0;
	}    
}

