#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

ll MOD;
using Matrix = vector <vector <ll>>;

// Nhan an do (a * b) % MOD;
// a * b / 2 + a * b / 2
// ll mul(ll a, ll b) {
// 	ll ans = 0;
// 	while (b) {
// 		if (b & 1) ans = (ans + a) % MOD;
// 		a = (a + a) % MOD;
// 		b >>= 1;
// 	}
// 	ans %= MOD;
// 	return ans; 
// }
Matrix mMul(Matrix A, Matrix B) {
	int N = A.size();
	int M = A[0].size();
	int P = B[0].size();

	Matrix C(N, vector <ll> (P, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < P; ++j) {
			ll ans = 0;
			for (int k = 0; k < M; ++k) {
				ans += (1LL * A[i][k] * B[k][j]) % MOD;
				ans %= MOD;
			}
			C[i][j] = ans;
		}
	}
	return C;
}
// DK de luy thua do la A la ma tran vuong (hang = cot)
Matrix bPow(Matrix A, ll b) {
	int N = A.size();
	Matrix ans(N, vector <ll> (N, 0));
	for (int i = 0; i < N; ++i) ans[i][i] = 1;

	while (b) {
		if (b & 1) ans = mMul(ans, A);
		A = mMul(A, A);
		b >>= 1;
	} 
	return ans;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

   	int T; cin >> T;
   	while (T--) {
   		int X, n;
   		cin >> X >> n >> MOD;
   		
   		Matrix base = {
   			{(1 + 1LL * X * X) % MOD, (1LL * X * X) % MOD, X % MOD, 1 % MOD}
   		};

   		// y = -4x;
   		ll Y = (-4LL * X);
   		while (Y < 0) Y += MOD;
   		Matrix B = {
   			{1 % MOD, 0, 0, 0},
   			{(4LL * X * X) % MOD, (4LL * X * X) % MOD, (2LL * X) % MOD, 1 % MOD},
   			{Y, Y, (MOD - 1) % MOD, 0},
   			{1 % MOD, 1 % MOD, 0, 0}
   		};

   		base = mMul(base, bPow(B, n - 2));
   		cout << base[0][0] << "\n";
   	}

}

