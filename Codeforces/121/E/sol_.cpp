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

int n, q;
vector <pair <int, int>> qs[N];
int ans[N];
set <int> idx;
int lst;
// Storing indexes
bool vis[N];
void impossible() {
	for (int i = 1; i <= n; ++i) cout << "-1 ";
	exit(0);
}
void brute(int cur, int id) {
	while (lst >= 0 && vis[lst]) --lst;
	if (lst <= cur) impossible();
	ans[id] = lst;
	vis[lst] = 1;
}	

void solve(int x, int l, int r, int L, int R) {
	if (l > r) impossible();
	auto p = idx.lower_bound(L);
	auto i = p;
	// debug(*p);
	bool done = 0;
	while (p != idx.end() && *p <= R) {
		// find minimum range where x is the minimum for all range of [L, R]
		if (l <= *p && *p <= r && !done) {
			ans[*p] = x;
			vis[x] = 1;
			done = 1;
			// debug(l, r, *p);
		}
		else {
			// other ranges must have minimum > x
			brute(x, *p);
		}
		++p;
	}
	// for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
	// remove processed range
	if (!done) impossible();
	debug(*i, *p);
	idx.erase(i, p);
}	


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> n >> q;
    for (int i = 1; i <= q; ++i) {
    	int l, r, x;
    	cin >> l >> r >> x;
    	++l; ++r;
    	qs[x].push_back({l, r});
    }

    lst = n - 1;
    for (int i = 1; i <= n; ++i) idx.insert(i);
    
    for (int x = n - 1; x >= 0; --x) {
    	if (!qs[x].empty()) {
    		int l = -1, L = 1e9;
    		int r = 1e9, R = -1;
    		for (auto& [lb, rb] : qs[x]) {
    			l = max(l, lb); L = min(L, lb);
    			r = min(r, rb); R = max(R, rb);
    		}
    		solve(x, l, r, L, R);
    	}
    }
    for (int i : idx) {
    	brute(-1, i);
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}

s