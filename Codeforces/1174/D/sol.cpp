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

    int n, k;
    cin >> n >> k;

    vector <int> p;
    p.push_back(0);
    int mx = 1 << n;
    if (k >= mx) {
    	for (int i = 1; i < mx; ++i)
    		p.push_back(i);
    }
    else {
    	vector <int> val(mx), used(mx, 0);
    	for (int i = 1; i < mx; ++i) {
    		int j = i ^ k;
    		if (!used[i] && !used[j] && i != j && i && j) {
    			if (!used[i]) {
    				p.push_back(i);
    				used[i] = used[j] = 1;
    			}
    			if (!used[j]) {
    				p.push_back(j);
    				used[i] = used[j] = 1;
    			}
    		} 
    	}
    }
    debug(p);
    int m = p.size();
    cout << m - 1 << "\n";
    for (int i = 1; i < m; ++i) {
    	cout << (p[i] ^ p[i - 1]) << " ";
    }
}

