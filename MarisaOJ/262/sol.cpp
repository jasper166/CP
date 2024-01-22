#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

template <typename T>
struct Fenwick {
	vector <T> f;
	int n;
	Fenwick(T _n = 0) { init(_n); };
	void init(T _n) { 
		n = _n;
		f.resize(_n + 5);
	}
	void upd(int x, T val) {
		for (; x <= n; x += x & -x)
			f[x] += val;
	}
	T qry(int x) {
		if (!x) return 0;
		T ans = 0;
		for (; x > 0; x -= x & -x)
			ans += f[x];
		return ans;
	}
	T qry(int l, int r) {
		// debug(l, r);
		if (l > r) return 0;
		return qry(r) - qry(l - 1);
		
	}
};

const int BLOCK = 331;
const int N = 1e5 + 5;
int n, q;
int a[N];
struct Query {
	int l, r, id;
	bool operator < (const Query ot) const {
		if (l / BLOCK == ot.l / BLOCK)
			return (l / BLOCK & 1)? r < ot.r : r > ot.r;
		return (l / BLOCK < ot.l / BLOCK);
	}
};

ll ret = 0, ans[N];
Fenwick <int> fen;

void add(int i) {

}
void del(int i) {

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i)
    	cin >> a[i];
    
    vector <int> vals;
    for (int i = 1; i <= n; ++i)
    	vals.push_back(a[i]);
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    for (int i = 1; i <= n; ++i)
    	a[i] = (int) (lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin()) + 1;

    // debug(vals);

    vector <Query> queries;
    for (int i = 1; i <= q; ++i) {
    	int l, r;
    	cin >> l >> r;
    	queries.push_back({l, r, i});
    }
    sort(queries.begin(), queries.end());
    
	int sz = vals.size();
    int l = 1, r = 0;
	fen.init(1e5);

    for (auto& [L, R, id] : queries) {
    	
    	// debug(L, R, id);

    	while (l > L) {
    		--l;
    		int x = a[l];
    		ret += fen.qry(1, x - 1);
    		fen.upd(x, 1);
    	}

    	while (r < R) {
    		++r;
    		int x = a[r];
    		ret += fen.qry(x + 1, sz);
    		fen.upd(x, 1);

    	}

    	while (l < L) {
    		int x = a[l];
    		ret -= fen.qry(1, x - 1);
    		fen.upd(x, -1);
    		++l;
    	}

    	while (r > R) {
    		int x = a[r];
    		ret -= fen.qry(x + 1, sz);
    		fen.upd(x, -1);
    		--r;
    	}
    	
    	ans[id] = ret;
    }
    for (int i = 1; i <= q; ++i) 
    	cout << ans[i] << "\n";
}

