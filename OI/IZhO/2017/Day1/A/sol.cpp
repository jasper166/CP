#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 501 * 501;
const int MOD = 1e9 + 7;
int n;
int a[N];

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int sz = accumulate(a + 1, a + 1 + n, 0);
	
	// dp(x) : number of ways constructing sum equal to x;
	vector <ll> dp1(N, 0), dp2(N, 0);
	vector <int> able(N, 1);
	dp1[0] = 1;

	// solving first case: a[0] is the observer
	// -> used to solve others
	for (int i = 1; i <= n; ++i) 
		for (int j = sz; j >= a[i]; --j)
			(dp1[j] += dp1[j - a[i]]) %= MOD;

	if ((sz & 1) || !dp1[sz / 2]) {
		cout << "0\n";
		return 0;
	}


	auto solve = [&] (int id) -> void {
		for (int i = 0; i < N; ++i) dp2[i] = dp1[i];
		// remove a(id) from current set
		for (int j = a[id]; j < N; ++j)
			(dp2[j] += MOD - dp2[j - a[id]]) %= MOD;
		// choose value
		for (int x = 1; x < N; ++x) {
			int new_sz = sz - a[id] + x;
			if ((new_sz & 1) || (new_sz / 2 - x < 0) || !dp2[(new_sz / 2) - x])
				able[x] = 0;
		}
	};
	

	for (int i = 1; i <= n; ++i) {
		// debug(able[3]);
		solve(i);
	}

	vector <int> ans;
	for (int x = 1; x < N; ++x) {
		if (able[x]) {
			ans.push_back(x);
		}
	}

	cout << (int) (ans.size()) << "\n";
	for (int x : ans) cout << x << " ";
}

