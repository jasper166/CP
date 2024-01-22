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
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 5e2 + 5;

int n, k;
int a[N], b[N];
bool dp[2][N];
// dp(i, x) : till i, having spare x red berries 
void run_case() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];

    ll tot = 0;
	for (int i = 1; i <= n; ++i)
		tot += a[i] + b[i];

	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		// at most k - 1 otherwise, we can fill to some baskets
		for (int x = 0; x < k; ++x) {
			// Choose to take as much as red to some baskets, the remain is r_a
			int r_a = a[i] % k;
			dp[1][x] |= dp[0][(x - r_a + k) % k];
			// Leaving t remaining red berries
			// We take (a(i) - t) to some baskets, remaining r_a -> try filling with blue
			for (int t = 0; t <= a[i] && t < k; ++t) {
				int r_a = (a[i] - t) % k;
				int r_b = (b[i] - (k - r_a) + k) % k;
				if (r_b <= b[i])
					dp[1][x] |= dp[0][(x - t + k) % k];
			}
		}

		for (int x = 0; x < k; ++x) {
			dp[0][x] = dp[1][x];
			dp[1][x] = 0;
		}
	}

	ll ans = 0;
	for (int x = 0; x < k; ++x)
		if (dp[0][x])
			ans = max(ans, (tot - x) / k);
	cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
