#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#define fi first
#define se second
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
using pii = pair < int, int >;
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int val[N];
int getReal(int x) { return val[x]; }
const ll inf = 1e18;

struct LiChaoTree {
 // Min
	struct Line {
		ll a, b;
		Line(ll _a = 0, ll _b = inf) : a(_a), b(_b) {};
		ll cal(ll x) { return a * getReal(x) + b; }      
	};
	int n;
	vector <Line> f;
	LiChaoTree(int _n) {
		n = _n;
		f.resize(_n * 4 + 5);
	}

	void addLine(int x, int lx, int rx, Line line) {
		if (lx == rx) {
			if (f[x].cal(lx) > line.cal(lx))
				f[x] = line;
			return;
		}
		int m = (lx + rx) >> 1;
		if (f[x].a < line.a) swap(f[x], line);
		if (line.cal(m) < f[x].cal(m)) {
			swap(f[x], line);
			addLine(x << 1, lx, m, line);
		}
		else addLine(x << 1 | 1, m + 1, rx, line);
	}

	void addRange(int x, int l, int r, int u, int v, Line line) {
		if (l > v || r < u) return;
		if (u <= l && r <= v) {
			addLine(x, l, r, line);
			return;
		}
		int m = (l + r) >> 1;
		addRange(x << 1, l, m, u, v, line);
		addRange(x << 1 | 1, m + 1, r, u, v, line);
	}

	ll qry(int x, int lx, int rx, int p) {
		ll ans = f[x].cal(p);
		if (lx == rx) return ans;
		int m = (lx + rx) >> 1;
		if (p <= m) return min(ans, qry(x << 1, lx, m, p));
		else return min(ans, qry(x << 1 | 1, m + 1, rx, p));
	}

	ll qry(int x) { return qry(1, 1, n, x); }
	void addRange(int l, int r, ll a, ll b) { addRange(1, 1, n, l, r, Line(a, b)); }
	void addLine(ll a, ll b) { addLine(1, 1, n, Line(a, b)); }
};


int n;
int x[N], qx[N], w[N];
ll e[N], dp[N];
void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> w[i] >> e[i];
    
    vector <int> b;
    for (int i = 1; i <= n; ++i) {
        b.push_back(x[i]);
    }

    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for (int i = 1; i <= n; ++i) {
        qx[i] = lower_bound(b.begin(), b.end(), x[i]) - b.begin() + 1; 
        val[qx[i]] = x[i];
    }

    int m = b.size();
    ll ans = 0;

    LiChaoTree lc(m);
    lc.addLine(0, 0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = -lc.qry(qx[i]) + e[i];
        ans = max(ans, dp[i]); 
        lc.addRange(qx[i], m, w[i], -w[i] * x[i] - dp[i]);
        lc.addRange(1, qx[i] - 1, -w[i], w[i] * x[i] - dp[i]);
    }
    
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
