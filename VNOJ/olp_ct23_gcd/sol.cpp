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
using Matrix = vector <vector <int>>;
using i128 = __int128_t;
int MOD;


Matrix mMul(Matrix A, Matrix B) {
	int n = A.size();
	int m = A[0].size();
	int p = B[0].size();
	Matrix C(n, vector <int> (p, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < p; ++j) {
			ll ans = 0;
			for (int k = 0; k < m; ++k) {
				i128 x = A[i][k];
				i128 y = B[k][j];
				ans += (ll) ((x * y) % MOD);
				ans %= MOD; 
			}
			C[i][j] = ans % MOD;
		}
	}
	return C;
}

Matrix mPow(Matrix A, ll b) {
	int n = A.size();
	Matrix ans(n, vector <int> (n, 0));
	for (int i = 0; i < n; ++i) ans[i][i] = 1;
	while (b) {
		if (b & 1ll) ans = mMul(ans, A);
		A = mMul(A, A);
		b >>= 1ll;
	}
	return ans;
}


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    ll a, b;
    cin >> a >> b >> MOD;

	ll n = __gcd(a, b);
	if (n <= 1) {
		cout << n << "\n";
		return 0;
	}
	Matrix base = {{1, 1}, {1, 0}};
	Matrix f = {{1, 0}};
	f = mMul(f, mPow(base, n - 1));
	cout << f[0][0] % MOD << "\n";
}
