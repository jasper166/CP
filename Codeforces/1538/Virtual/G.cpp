#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
const int INF = 1e9;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int t = 1; cin >> t;
    while (t--) {
    	int x, y, a, b;
    	cin >> x >> y >> a >> b;

    	if (x > y) swap(x, y);
    	if (a > b) swap(a, b);

    	auto cal = [&] (ll v) -> bool {
    		ll r_remains = x - v * a;
    		ll b_remains = y - v * a;
    		if (a == b) return (r_remains >= 0 && b_remains >= 0);
    		if (r_remains < 0 || b_remains < 0) return 0;
    		r_remains /= (b - a);
    		b_remains /= (b - a);
    		return (r_remains + b_remains >= v);
    		// (x + y >= v * (a + b));
    	};


    	int l = 0, r = INF;
    	int ans = 0;
    	while (l <= r) {
    		int m = (l + r) / 2;
    		if (cal(m)) {
    			ans = m;
    			l = m + 1;
    		}
    		else
    			r = m - 1;
    	}
    	cout << ans << "\n";
    }
}

