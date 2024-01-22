#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int t = 1; cin >> t;
    while (t--) {
    	int l, r; cin >> l >> r;

    	int p = 1;
    	ll ret = 0;
    	for (int x = 0; x <= 9; ++x) {
    		ret += r / p - l / p;
    		p *= 10;
    	}
    	cout << ret << "\n";
    }
}

