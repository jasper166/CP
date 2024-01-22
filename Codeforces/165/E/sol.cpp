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
const int LG = 22;

int dp[1 << LG];
// dp(mask) = x such x is a subset of mask
bool b[1 << LG];
int n;
int a[N];
void run_case() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];

	for (int i = 0; i < n; ++i)
		b[a[i]] = 1;

	for (int x = 0; x < (1 << LG); ++x)
		dp[x] = (b[x]? x : -1);

	for (int i = 0; i < LG; ++i) {
		for (int mask = 0; mask < (1 << LG); ++mask) {
			if (mask & (1 << i)) 
				dp[mask] = max(dp[mask], dp[mask ^ (1 << i)]);
		}
	}

	int full = (1 << LG) - 1;
	for (int i = 0; i < n; ++i)
		cout << dp[full ^ a[i]] << " \n"[i == n - 1];
}


	/*	
		N : numbers of bit required to represent all array elements
		for(int i = 0; i<(1<<N); ++i)
			F[i] = A[i];
		for(int i = 0;i < N; ++i) 
			for(int mask = 0; mask < (1<<N); ++mask)
				if(mask & (1<<i))
					F[mask] += F[mask^(1<<i)];

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
