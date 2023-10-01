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

#define int long long
using pii = pair < int, int >;
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

struct SegmentTree {
	struct Node {
		ll mi, sum, lzy;
		Node(ll x = 0, ll y = 0, ll z = 0) {
			mi = x;
			sum = y;
			lzy = z;
		}
	};
	int n;
	vector <Node> f;
	vector <int> a;
	SegmentTree(int _n) : n(_n), f(_n * 4 + 5), a(_n + 5) {};

	Node merge(Node l, Node r) {
		Node x;
		x.sum = l.sum + r.sum;
		x.mi = min(l.mi, r.mi);
		return x;
	}
	void push(int x, int l, int r) {
		if (f[x].lzy) {
			int val = f[x].lzy;
			f[x].sum += val * (r - l + 1);
			f[x].mi += val;
			if (l != r) {
				f[x << 1].lzy += val;
				f[x << 1 | 1].lzy += val;
			}
			f[x].lzy = 0;
		}
	}
	void build(int x, int lx, int rx) {
		if (lx == rx) {
			f[x].sum = f[x].mi = a[lx];
			return;
		}
		int m = (lx + rx) / 2;
		build(x << 1, lx, m);
		build(x << 1 | 1, m + 1, rx);
		f[x] = merge(f[x << 1], f[x << 1 | 1]);
		return;
	}
	void upd(int x, int lx, int rx, int l, int r, int val) {
		push(x, lx, rx);
		if (lx > r || rx < l)
			return;
		if (l <= lx && rx <= r) {
			f[x].lzy += val;
			push(x, lx, rx);
			return;
		}
		int m = (lx + rx) / 2;
		upd(x << 1, lx, m, l, r, val);
		upd(x << 1 | 1, m + 1, rx, l, r, val);
		f[x] = merge(f[x << 1], f[x << 1 | 1]);
	}
	
	Node qry(int x, int lx, int rx, int l, int r) {
		push(x, lx, rx);
		if (lx > r || rx < l)
			return Node(INF, 0, 0);
		if (l <= lx && rx <= r) 
			return f[x];
		int m = (lx + rx) / 2;
		Node ql = qry(x << 1, lx, m, l, r);
		Node qr = qry(x << 1 | 1, m + 1, rx, l, r);
		return merge(ql, qr);
	}

	void upd(int l, int r, int val) { upd(1, 1, n, l, r, val); }
	ll qry(int l, int r, int t) {
		Node ans = qry(1, 1, n, l, r);
		if (t == 2) return ans.sum;
		else return ans.mi;
	}
};

int n, q;
void run_case() {
	cin >> n >> q;
	SegmentTree st(n);
	for (int i = 1; i <= n; ++i) {
		cin >> st.a[i];
		// debug(st.a[i]);
	}

	st.build(1, 1, n);
	while(q--) {
		char cmd;
		int l, r, x;
		cin >> cmd >> l >> r;
		if (cmd == 'P') {
			cin >> x;
			st.upd(l, r, x);
		}
		else if (cmd == 'M') {
			cout << st.qry(l, r, 1) << "\n";
		}
		else {
			cout << st.qry(l, r, 2) << "\n";
		}
	} 
}

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    // setIO("haybales");
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
