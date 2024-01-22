#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 1e5 + 5;
const int BLOCK = 331;

int n, q;
int a[N];
ll f[BLOCK][N], g[BLOCK][N];
int cnt[BLOCK][N];

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int T; cin >> T;
    while (T--) {
    	cin >> n >> q;
    	for (int i = 1; i <= n; ++i) cin >> a[i];

    	for (int d = 1; d < BLOCK; ++d) {
    		for (int i = 1; i <= n; ++i) {
    			g[d][i] = (i >= d? g[d][i - d] : 0) + a[i];
    			cnt[d][i] = (i >= d? cnt[d][i - d] : 0) + 1;
    			f[d][i] = (i >= d? f[d][i - d] : 0) + 1LL * cnt[d][i] * a[i];
    		}
    	}
    			
    	for (int _i = 1; _i <= q; ++_i) {
    		int s, k, d; 
    		cin >> s >> d >> k;
    		// d > sqrt(n) -> k <= sqrt(n) -> q * sqrt(n)
    		ll ans = 0;
    		if (d >= BLOCK) {
    			for (int _k = 1, j = 0; _k <= k; ++_k, j += d) 
    				if (s + j <= n)
    					ans += 1LL * a[s + j] * _k;
    		}
    		else {
    			int l = s;
    			int r = s + d * (k - 1);
    			ll F = f[d][r] - (l >= d? f[d][l - d] : 0);
    			ll C = 1LL * (l >= d? cnt[d][l - d] : 0);
    			ll G = g[d][r] - (l >= d? g[d][l - d] : 0);
    			// debug(l, r, F, C, G);
    			ans =  (F - C * G);    			
    		}
    		cout << ans << " \n"[_i == q];
    	}
    }
}

