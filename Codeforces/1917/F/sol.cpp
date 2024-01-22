#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 2e3 + 5;
int n, d;
int l[N];

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int T; cin >> T;
    while (T--) {
    	cin >> n >> d;
    	for (int i = 1; i <= n; ++i) cin >> l[i];

    	sort(l + 1, l + 1 + n);
    	if (l[n] + l[n - 1] > d) {
    		cout << "No\n";
    		continue;
    	}

    	vector <bitset <N>> dp(d + 5);
    	
    	dp[0][0] = 1;
    	for (int i = n - 1; i >= 1; --i) {
    		for (int j = d; j >= 0; --j) {
    			if (j + l[i] <= d) 
    				dp[j + l[i]] |= dp[j]; // dp(x + l[i]) |= dp(x)
    			dp[j] |= (dp[j] << l[i]); // dp(x, y) |= dp(x, y - l[i]);
    		}
    	}
    	// Including the longest edge
    	bool ret = dp[0][d - l[n]];
    	// Excluding the longest edge, (x, y >= l[n])
    	for (int x = l[n]; x <= d - l[n]; ++x) {
    		if (dp[x][d - x]) {
    			ret = 1;
    			break;
    		}
    	}

    	cout << (ret? "Yes\n" : "No\n"); 
    }
}

