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
const int N = 5e3 + 5;

int mex[N][N];
int f[N];
int a[N];
int n;
bool dp[N][N];
// dp(i, x) : can we make XOR = x by using 1...i
void run_case() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	// Calculate MEX for each subarray
	for (int l = 1; l <= n; ++l) {
		fill(f, f + n + 1, 0);
		int x = 0;
		for (int r = l; r <= n; ++r) {
			f[a[r]] = 1;
			while (f[x]) ++x;
			mex[l][r] = x;
		}
	}
	// answer wont exceed n? (1) and inner loop complexity <= O(2 * n) (2)
	for (int i = 0; i <= n; ++i) {
		for (int x = 0; x <= n; ++x) {
			dp[i][x] = 0;
		}
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		// If we not using a(i)
		for (int x = 0; x <= n; ++x)
			dp[i][x] = dp[i - 1][x];

		for (int j = 1; j <= i; ++j) {
			// Skipping replaceable segments (3)
			if (mex[j][i] == mex[j + 1][i] || mex[j][i] == mex[j][i - 1])
				continue;
			// why j - 1 (non-intersecting subarray -> (1..j - 1) (j..i));
			for (int x = 0; x <= n; ++x) {
				if (dp[j - 1][x]) {
					dp[i][x ^ mex[j][i]] = 1;
				}
			}
		}
	}

	for (int x = n; x >= 0; --x) {
		if (dp[n][x]) {
			cout << x << "\n";
			return;
		}
	}
}

/*
	Proof:
	(1):???
	(2):
		+ (l, r) : irreplaceable segment
		1. al >= ar.
		Suppose there exists 2 segment where (l, r1) and (l, r2) are irreplaceable segments, al > ar.
		Mex(l, r1) >= a(l) (true or we can remove al)
		Since al >= ar2 -> mex(l, r1) >= a(r2) 
		-> mex(l, r2 - 1) = mex(l, r2) -> (l, r2) can be replaced -> Contradiction 
		2. al <= ar
		The above applies

		-> each a(i), there're at most 2 irreplaceable segments of a(i) (ai >= aj and ai <= aj) 
			-> Totally, at most O(2 * n)

	(3): mex(l, r) = mex(l1, r1) (l <= l1 <= r1 <= r) 
		-> mex(l2, r2) = mex(l, r) for (l <= l2 <= l1) and (r1 <= r2 <= r)
*/

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
