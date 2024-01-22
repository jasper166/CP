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
void run() {
	int n; cin >> n;
	vector <int> a(n);
	for (int& x : a) cin >> x;

	int p_min = -1, p_max = -1;
	int x_min = *min_element(a.begin(), a.end());
	int x_max = *max_element(a.begin(), a.end());
	
	for (int i = 0; i < n; ++i) {
		if (a[i] == x_min) p_min = i;
		if (a[i] == x_max) p_max = i;
	}

	// remove from left side
	int r1 = max(p_min, p_max) + 1;

	if (p_min > p_max) swap(p_min, p_max);
	// remove from left and right
	int r2 = p_min + 1 + (n - p_max);
	// remove from right side
	int r3 = n - p_min;
	cout << min({r1, r2, r3}) << "\n";
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

