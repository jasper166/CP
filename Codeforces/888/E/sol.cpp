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

    int n, m;
    cin >> n >> m;

    int sz = n / 2;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
    	cin >> a[i];

    vector <int> pack;
    for (int msk = 0; msk < (1 << sz); ++msk) {
    	int sum = 0;
    	for (int i = 0; i < sz; ++i)
    		if (msk & (1 << i))
    			sum = (sum + a[i]) % m;
    	pack.push_back(sum);
    }

    sort(pack.begin(), pack.end());
    // find largest in first part such (x + y) % m max -> maximum y < m - x;
    
    int ans = 0;
    sz = n - sz;
    for (int msk = 0; msk < (1 << sz); ++msk) {
    	int sum = 0;
    	for (int i = 0; i < sz; ++i)
    		if (msk & (1 << i))
    			sum = (sum + a[i + n / 2]) % m;

    	auto x = prev(lower_bound(pack.begin(), pack.end(), m - sum));
    	ans = max(ans, (*x + sum) % m);
    } 
    cout << ans << "\n";
}

