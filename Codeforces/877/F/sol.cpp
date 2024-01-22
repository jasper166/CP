#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int BLOCK = 311;
const int N = 1e5 + 5;

struct Queries {
	int l, r, id;
	bool operator < (const Queries ot) const {
		if (l / BLOCK == ot.l / BLOCK)
			return (l / BLOCK & 1)? r < ot.r : r > ot.r;
		else 
			return (l / BLOCK < ot.l / BLOCK);
	}
};
Queries qs[N];

ll ans[N];
ll ret;
ll ub[N], lb[N], prf[N], f[3];
int cnt[N * 10];

int n, k, q;
int a[N], t[N];

void add(int i, int t) {
	ret += (t? cnt[ub[i]] : cnt[lb[i]]);
	++cnt[prf[i]];
}
void del(int i, int t) {
	--cnt[prf[i]];
	ret -= (t? cnt[ub[i]] : cnt[lb[i]]);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> t[i];
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
    	f[t[i]] += 1LL * a[i];
    	ll x = f[1] - f[2];
    	prf[i] = x;
    	// debug(x);
    }

    vector <ll> vals;
    for (int i = 0; i <= n; ++i) {
    	for (int x : {-1, 0, 1})
    		vals.push_back(prf[i] + 1LL * x * k);
    }


    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    debug(vals);

    for (int i = 0; i <= n; ++i) {
    	ub[i] = (int) (lower_bound(vals.begin(), vals.end(), prf[i] + k) - vals.begin());
    	lb[i] = (int) (lower_bound(vals.begin(), vals.end(), prf[i] - k) - vals.begin());
    	prf[i] = (int) (lower_bound(vals.begin(), vals.end(), prf[i]) - vals.begin()); 
    }

    cin >> q;
    for (int i = 1; i <= q; ++i) {
    	cin >> qs[i].l >> qs[i].r;
    	qs[i].id = i;
    	qs[i].l--;
    }
    sort(qs + 1, qs + 1 + q);

   	int l = 1, r = 0;
   	for (int i = 1; i <= q; ++i) {
   		auto [L, R, id] = qs[i];
   		while (l > L) add(--l, 1);
   		while (r < R) add(++r, 0);
   		while (l < L) del(l++, 1);
   		while (r > R) del(r--, 0);
   		ans[id] = ret;
   	}

   	for (int i = 1; i <= q; ++i) 
   		cout << ans[i] << "\n";
}

