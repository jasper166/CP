#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

struct SegmentTree {
	int n;
	vector <int> a;
	vector <pii> f;
	// SegmentTree(int _n) : n(_n), f(_n * 2 + 5, 0), a(_n + 5) {};

	void init(int _n) {
		n = _n;
		f.assign(_n * 2 + 5, {0, 0});
		a.assign(_n + 5, 0);
	}
	void build() {
		for (int i = 1; i <= n; ++i)
			f[i + n] = {a[i], i};
		for (int i = n; i >= 1; --i)
			f[i] = max(f[i << 1], f[i << 1 | 1]);
	}
	void upd(int x, int val) {
		f[x += n].fi = val;
		for (; x >= 1; x >>= 1)
			f[x >> 1] = max(f[x], f[x ^ 1]);
	}
	pii qry(int l, int r) {
		pii ql = {0, 0}, qr = {0, 0};
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1)
				ql = max(ql, f[l++]);
			if (r & 1)
				qr = max(f[--r], qr);
		}
		return max(ql, qr);
	}
} st;

int n, q;
void run_case() {
	cin >> n >> q;
	st.init(n);
	for (int i = 1; i <= n; ++i) cin >> st.a[i];
	st.build();
	for (int i = 1; i <= q; ++i) {
		int x, y;
		char cmd; cin >> cmd >> x >> y;
		// debug(cmd, x, y);
		if (cmd == 'Q') {
			auto [val1, id1] = st.qry(x, y);
			auto [val2, id2] = st.qry(x, id1 - 1);
			auto [val3, id3] = st.qry(id1 + 1, y);
			cout << (val1 + max(val2, val3)) << "\n";
		}
		else {
			st.upd(x, y);
		}
	}
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
