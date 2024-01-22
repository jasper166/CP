#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int INF = 1e9;

vector <int> a;
int n, l, r; 

ll count(int x) {
	ll ret = 0;
	for (int i = 0; i < n; ++i) {
		auto it = lower_bound(a.begin() + i, a.end(), x - a[i]);
		int st = (int) (it - a.begin());
		if (it != a.end()) {
			ret += (n - st) - (st == i);
		}
	}
	return ret;
}

void run() {
	
	cin >> n >> l >> r;

	a.resize(n);
	for (int& x : a) cin >> x;

	sort(a.begin(), a.end());
	cout << count(l) - count(r + 1) << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int t = 1; 
    cin >> t;
    while (t--) {
    	run();
    }
}

