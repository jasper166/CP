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
const int BLOCK = 2155;

struct Query {
	int t, l, r, id;
	bool operator < (const Query ot) const {
		if (l / BLOCK == ot.l / BLOCK) {
			if (r / BLOCK == ot.r / BLOCK) {
				return t < ot.t;
			}
			return r < ot.r;
		}
		return l < ot.l;
	}	
};

struct Update {
	int id, prv, nxt;
};

int n, q;
int a[N], nxt_a[N];
int qx[N], qy[N], qt[N];
int ans[N];

vector <Query> queries;
vector <Update> updates;

int cnt[N * 10], c[N * 10];
void add(int i) {
	c[cnt[a[i]]]--;
	cnt[a[i]]++;
	c[cnt[a[i]]]++;
}
void del(int i) {
	c[cnt[a[i]]]--;
	cnt[a[i]]--;
	c[cnt[a[i]]]++;

}
void upd(int i, int val, int l, int r) {
	if (l <= i && i <= r) {
		del(i);
		a[i] = val;
		add(i);
	}
	else 
		a[i] = val;
}

int get() {
	int x = 0;
	while (c[x] != 0) ++x;
	return x;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> n >> q;

    vector <int> vals;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	vals.push_back(a[i]);
    }

    for (int i = 1; i <= q; ++i) {
    	cin >> qt[i] >> qx[i] >> qy[i];
    	if (qt[i] == 2) {
    		vals.push_back(qy[i]);
    	}
    }

    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());

    for (int i = 1; i <= n; ++i) {
    	a[i] = (int) (lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin()); 
    	nxt_a[i] = a[i];
    }
    for (int i = 1; i <= q; ++i) {
    	if (qt[i] == 1)
    		queries.push_back({(int) updates.size(), qx[i], qy[i], i}); 
    	else {
    		qy[i] = (int) (lower_bound(vals.begin(), vals.end(), qy[i]) - vals.begin()); 
    		updates.push_back({qx[i], nxt_a[qx[i]], qy[i]});
    		nxt_a[qx[i]] = qy[i];
    	}
    }

    // Mo's with update. O(Q * N ^ (2 / 3));
    c[0] = 1e9;
    sort(queries.begin(), queries.end());
    int l = 1, r = 0, t = 0;
    for (int i = 0; i < (int) queries.size(); ++i) {
    	auto [T, L, R, id] = queries[i];
    	// debug(T, L, R, id);

    	while (l > L) add(--l);
    	while (r < R) add(++r);
    	while (l < L) del(l++);
    	while (r > R) del(r--);
    	while (t < T) {
    		upd(updates[t].id, updates[t].nxt, l, r);
    		++t;
    	}
    	while (t > T) {
    		--t;
    		upd(updates[t].id, updates[t].prv, l, r);
    	}

    	ans[id] = get();
    }

    for (int i = 1; i <= q; ++i) {
    	if (qt[i] == 1) 
    		cout << ans[i] << "\n";
    }
}