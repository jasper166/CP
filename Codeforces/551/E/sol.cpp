#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif


const int BLOCK = 711;
const int N = 5e5 + 5 + BLOCK;

ll bl[BLOCK][BLOCK];
ll a[N], lzy[BLOCK];
int n, q;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> n >> q;
    // int BLOCK = sqrt(n);
    // debug(BLOCK, n / BLOCK);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    for (int i = 1; i <= n; ++i) {
    	// debug(i / BLOCK, i);
    	bl[i / BLOCK][i % BLOCK] = a[i];
    }

    for (int i = 0; i <= n / BLOCK; ++i)
    	sort(bl[i], bl[i] + BLOCK);

    while (q--) {
    	int cmd; cin >> cmd;
    	if (cmd == 1) {
    		int l, r, x; cin >> l >> r >> x;
    		// same block -> brute;
    		if (l / BLOCK == r / BLOCK) {

    			int B = l / BLOCK;
    			for (int i = l; i <= r; ++i) 
    				a[i] += x;
    			for (int i = B * BLOCK; i < (B + 1) * BLOCK; ++i)
    				bl[B][i % BLOCK] = a[i];
    			sort(bl[B], bl[B] + BLOCK);

    		}
    		else {
    			int L = l / BLOCK;
    			int R = r / BLOCK;

    			// debug(L, R);
    			// update left block (head)
    			for (int i = l; i < (L + 1) * BLOCK; ++i)
    				a[i] += x;
    			for (int i = L * BLOCK; i < (L + 1) * BLOCK; ++i)
    				bl[L][i % BLOCK] = a[i];
    			sort(bl[L], bl[L] + BLOCK);

    			// update right block (tail)
    			for (int i = R * BLOCK; i <= r; ++i) {
    				a[i] += x;
    			}
    			for (int i = R * BLOCK; i < (R + 1) * BLOCK; ++i)
    				bl[R][i % BLOCK] = a[i];
    			sort(bl[R], bl[R] + BLOCK);

    			// for other blocks remain sorted after adding x to all elements (body)
    			for (int i = L + 1; i < R; ++i)
    				lzy[i] += x;
    		}
    	}
    	else {
    		int y; cin >> y;
    		int L = -1, R = -1, l = -1, r = -1;
    		// find which block contains target
    		for (int i = 0; i <= n / BLOCK; ++i) {
    			int p = (int) (lower_bound(bl[i], bl[i] + BLOCK, y - lzy[i]) - bl[i]);
    			if (bl[i][p] == y - lzy[i]) {
    				L = i;
    				break;
    			}
    		}
    		if (L == -1) {
    			cout << "-1\n";
    			continue;
    		}
    		// find original position
    		for (int i = L * BLOCK; i < (L + 1) * BLOCK; ++i) {
    			if (a[i] == y - lzy[L]) {
    				l = i;
    				break;
    			}
    		}

    		for (int i = n / BLOCK; i >= 0; --i) {
    			int p = (int) (lower_bound(bl[i], bl[i] + BLOCK, y - lzy[i]) - bl[i]);
    			if (bl[i][p] == y - lzy[i]) {
    				R = i;
    				break;
    			}
    		}

    		for (int i = (R + 1) * BLOCK - 1; i >= R * BLOCK; --i) {
    			if (i <= n && a[i] == y - lzy[R]) {
    				r = i;
    				break;
    			}
    		}
    		cout << (r - l) << "\n";
    	}
    }
}
