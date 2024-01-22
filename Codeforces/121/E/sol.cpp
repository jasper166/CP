#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int BLOCK = 331;
const int N = 1e5 + 5;
const int M = 1e4 + 5;
int n, q;
int a[N], lzy[N];
int cnt[311][M];
bool isluck[M];

vector <int> lucky;
void prepare() {
	queue <int> q; q.push(0);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i : {4, 7}) {
			int y = x * 10 + i;
			if (y <= 1e4) {
				lucky.push_back(y);
				q.push(y);
			}
		}
	}
	// debug(lucky.size());
	for (int x : lucky) isluck[x] = 1;
}

int qry(int val) { return isluck[val]; }

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    prepare();
    cin >> n >> q;
    // int BLOCK = sqrt(n) + 1;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i)
    	cnt[i / BLOCK][a[i]]++;

    for (int i = 1; i <= q; ++i) {
    	string cmd;
    	int l, r, d;
    	cin >> cmd;
    	if (cmd[0] == 'a') {
    		cin >> l >> r >> d;
    		// head
    		int L = l / BLOCK;
    		int R = r / BLOCK;

    		if (L == R) {
    			for (int i = l; i <= r; ++i) {
    				cnt[i / BLOCK][a[i]]--;
	    			a[i] += d;
	    			cnt[i / BLOCK][a[i]]++;
    			}
    		}
    		else {
    			for (int i = l; i < (L + 1) * BLOCK; ++i) {
	    			cnt[L][a[i]]--;
	    			a[i] += d;
	    			cnt[L][a[i]]++;
	    		}
	    		for (int i = R * BLOCK; i <= r; ++i) {
	    			cnt[R][a[i]]--;
	    			a[i] += d;
	    			cnt[R][a[i]]++;
	    		}
	    		for (int i = L + 1; i < R; ++i)
	    			lzy[i] += d;
    		}
    	}
    	else {
    		cin >> l >> r;
    		int ans = 0;
    		int L = l / BLOCK;
    		int R = r / BLOCK;

    		if (L == R) {
    			for (int i = l; i <= r; ++i)
    				ans += qry(a[i] + lzy[i / BLOCK]);
    		}
    		else {
    			for (int i = l; i < (L + 1) * BLOCK; ++i)
    			ans += qry(a[i] + lzy[L]);
    		
	    		for (int i = R * BLOCK; i <= r; ++i)
	    			ans += qry(a[i] + lzy[R]);
	    		for (int i = L + 1; i < R; ++i) {
	    			for (int x : lucky) {
	    				if (x < lzy[i]) continue;
	    				ans += cnt[i][x - lzy[i]];
	    			}
	    		}
    		}
    		// debug(L, R);
    		cout << ans << "\n";
    	}
    }
}

