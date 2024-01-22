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
const int N = 1e6 + 5;
const int LG = 20;

int n;
int dp[1 << LG], pw[N];
void run_case() {
	cin >> n;	
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		dp[x]++;
	}

	for (int i = 0; i < LG; ++i) {
		for (int mask = 0; mask < (1 << LG); ++mask) {
			if (!(mask & (1 << i)))
				dp[mask] += dp[mask ^ (1 << i)];
		}
	}

	pw[0] = 1;
	for (int i = 1; i <= n; ++i)
		pw[i] = (pw[i - 1] * 2) % MOD;
	for (int i = 0; i < (1 << LG); ++i)
		dp[i] = (pw[dp[i]] - 1 + MOD) % MOD;
	
	// debug(dp[0], dp[1], dp[2], dp[3]);
	for (int i = 0; i < LG; ++i) {
		for (int mask = 0; mask < (1 << LG); ++mask) {
			if (!(mask & (1 << i)))
				dp[mask] -= dp[mask ^ (1 << i)];
			if (dp[mask] < 0) dp[mask] += MOD;
		}
	}
	// debug(dp[0], dp[1], dp[2], dp[3]);
	cout << dp[0] << "\n";
}

/*
	a1 & a2 & .. & am = K -> K is submask of every a(i)
	dp(x) : number of a(i) with x as a submask (a(i) & x = x)
	f(x) = 2^(dp(x)) - 1 : number of ways to choose some sets such their AND is x
	-> ans = f(0);
	but overlapping counting, a(i) can have other numbers as submasks -> subtract them from other dp;
	I.E:
	A[] = {1, 2}
	dp[0] = 2
	f[0]  = 3 ({1}, {2}, {1, 2}) 
	(only {1, 2} is valid -> subtract from dp(1), dp(2));
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
