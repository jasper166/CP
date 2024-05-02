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


	string s; cin >> s;
	int n = s.size();

	ll ans = 0;
	int r = n;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 1; i + j * 2 < n; ++j) {
			if (s[i] == s[i + j] && s[i] == s[i + 2 * j]) {
				r = min(r, i + 2 * j);
				break;
			}
		}
		if (r < n)
			ans += (n - r);
	}
	
	cout << ans << "\n";
}

