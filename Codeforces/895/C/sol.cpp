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

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int P = 70;


int n;
int f[P + 5][2];
vector <int> pr;
bool p[P + 5];
int mask[P + 5];

int bPow(int a, int b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = (1ll * ans * a) % MOD;
		a = (1ll * a * a) % MOD;
		b >>= 1;
	}
	return (int) ans;
}

void run_case() {
	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;

	for (int i = 2; i * i <= P; ++i) {
		if (p[i]) {
			for (int j = i * i; j <= P; j += i) 
				p[j] = 0;
		}
	}

	for (int i = 0; i <= P; ++i) {
		if (p[i]) pr.push_back(i);
	}
	// debug(pr);

	int sz = pr.size();
	for (int x = 1; x <= P; x++) {
		for (int i = 0; i < sz; ++i) {
			int c = 0;
			int X = x;
			while (X % pr[i] == 0) {
				c++;
				X /= pr[i];
			}
			if (c & 1) mask[x] |= (1 << i);
		}
	}
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		f[x][0]++;
	}

	for (int x = 1; x <= P; ++x) {
		int cnt = f[x][0];
		f[x][0] = (cnt == 0? 1 : bPow(2, cnt - 1));
		f[x][1] = (cnt == 0? 0 : bPow(2, cnt - 1));
	}

	vector <vector <int>> dp(P + 5, vector <int> (1 << sz, 0));
	dp[0][0] = 1;
	for (int x = 1; x <= P; ++x) {
		for (int msk = 0; msk < (1 << sz); ++msk) {
			// Taking even numbers of x
			(dp[x][msk] += (1ll * dp[x - 1][msk] * f[x][0]) % MOD) %= MOD;
			// Taking odd numbers of x
			(dp[x][msk] += (1ll * dp[x - 1][msk ^ mask[x]] * f[x][1]) % MOD) %= MOD;	
		}
	}
	// Subtract 1 as non_empty set required
	cout << (dp[P][0] - 1 + MOD) % MOD << "\n";
}

/*
	product is a square 
	-> even exponent in prime factorization
	-> each bit represents odd (1) or even (0) occuring in factorization
	-> valid subset should have xor sum = 0
	dp(i, mask) = dp(i - 1, mask) + dp(i - 1, mask ^ (mask(ai)));
*/

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
