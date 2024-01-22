#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

struct Fenwick {
	int n;
	vector <vector <ll>> f;
	
	Fenwick(int _n) : n(_n), f(10, vector <ll> (_n + 5, 0)) {};
	void upd(int k, int x, ll val) {
		for (; x <= n; x += x & -x)
			f[k][x] += val;
	} 
	ll qry(int k, int x) {
		ll ret = 0;
		for (; x; x -= x & -x)
			ret += f[k][x];
		return ret;
	}
	ll qry(int k, int l, int r) {
		if (l > r) return 0;
		return (qry(k, r) - qry(k, l - 1));
	}
};

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int n, q;
    cin >> n >> q;
    vector <int> a(n + 5);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector <vector <int>> usable(n + 5, vector <int> (10, 0));
	 for (int k = 0; k < 10; ++k) {
    	for (int i = 1; i <= n; ++i) {
    		if (k && i % k == 0) usable[i][k] = 1;
    		else {
    			int j = i;
    			while (j) {
    				int d = j % 10;
    				if (d == k) {
    					usable[i][k] = 1;
    					break;
    				}
    				j /= 10;
    			}
    		}
    	}
    }

    Fenwick fen(n);
    for (int k = 0; k < 10; ++k) {
    	for (int i = 1; i <= n; ++i) {
    		ll v = (usable[i][k]? 2ll * a[i] : 1ll * a[i]);
    		fen.upd(k, i, v);
    	}
    }

    while (q--) {
    	int cmd, x, y, z;
    	cin >> cmd >> x >> y;

    	if (cmd == 1) {
    		for (int k = 0; k < 10; ++k) {
    			ll v = (usable[x][k]? 2ll * (y - a[x]) : (y - a[x]));
    			fen.upd(k, x, v);
    		}
    		a[x] = y;
    	}
    	else {
    		cin >> z;
    		cout << fen.qry(z, x, y) << "\n";
    	}
    }
}

