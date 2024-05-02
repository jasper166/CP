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

   	int n;
   	ll T; 
   	cin >> n >> T;

   	vector <int> c(n);
   	for (int i = 0; i < n; ++i) cin >> c[i];

   	int mn = *min_element(c.begin(), c.end());

   	ll ans = 0;
   	while (T >= mn) {

   		int cnt = 0;
   		ll cost = 0;
   		for (int i = 0; i < n; ++i) {
   			if (T >= c[i] + cost) {
   				cost += c[i];
   				++cnt;
   			}
   		}
   		if (cost) {
   			ans += (T / cost) * 1LL * cnt;
   			T %= cost;
   		}
   	}
   	cout << ans << "\n";
}

