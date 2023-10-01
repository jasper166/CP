#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
using pii = pair < int, int >;
const int INF = 1e9;
// const int MOD = 1e9 + 7;
const int N = 20 + 5;

int n, k, MOD;
int a[N];
using Matrix = vector <vector <int>>;

Matrix mMul(Matrix a, Matrix b) {
    int N = a.size();
    int M = a[0].size();
    int P = b[0].size();
    Matrix ans(N, vector <int> (P, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P; ++j) {
            for (int k = 0; k < M; ++k) {
                ans[i][j] += (a[i][k] * b[k][j]) % MOD;
                ans[i][j] %= MOD;
            }
        }
    }
    return ans;
}

Matrix mPow(Matrix a, ll b) {
    int N = a.size();
    Matrix ans(N, vector <int> (N, 0));
    for (int i = 0; i < N; ++i) ans[i][i] = 1;
    while (b) {
        if (b & 1) ans = mMul(ans, a);
        a = mMul(a, a);
        b >>= 1;
    }
    return ans;
}


bool isPrime(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) return 0;
	}
	return (x >= 2);
}
void run_case() {
	cin >> n >> k >> MOD;
	vector <vector <int>> b(n + 1, vector <int> (n + 1, 0));
	vector <vector <int>> dp(1, vector <int> (n + 1, 0));
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j && isPrime(6 * a[i] + a[j])) {
				b[i][j] = 1;
				if (i == 0)
					dp[0][j]++;
			}
		}
	}
	for (int i = 0; i < n; ++i)
		b[i][n] = b[i][n - 1];
	b[n][n] = 1;
	dp[0][n] = dp[0][n - 1];

	dp = mMul(dp, mPow(b, k - 1));
	cout << dp[0][n] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
