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
const int N = 2e5 + 5;
const int LG = 20;

int n;
int a[N];
int dp[1 << LG][2];
array <int, 3> ans[N];
void run_case() {
	cin >> n;
	// 1st
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		dp[a[i]][0]++;
		dp[a[i]][1]++;
	}	

	for (int i = 0; i < LG; ++i) {
		for (int mask = 0; mask < (1 << LG); ++mask) {
			if (mask & (1 << i))
				dp[mask][0] += dp[mask ^ (1 << i)][0];
			else 
				dp[mask][1] += dp[mask ^ (1 << i)][1];
		}
	}

	int m = (1 << LG) - 1;
	for (int i = 0; i < n; ++i) {
		ans[i][0] = dp[a[i]][0];
		ans[i][1] = dp[a[i]][1];
		ans[i][2] = n - dp[m ^ a[i]][0];
		// debug(ans[i]);
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " \n";
	}

	// 2nd
}

/*
	1st:
	normal sos dp

	2nd:
	0 & 0 = 0-> Y
	0 & 1 = 0-> Y
	1 & 0 = 0-> N
	1 & 1 = 1-> Y
	-> find superset of x or x is a subset of y
	
	3rd:
	|x & y != 0| -> ans = n - |x & y = 0|;
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
