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
const int K = 12;
// Easiest to implementing and understanding
const ll inf = (ll) 1e18;
struct LiChaoTree {
    // Query for min;
    struct Line {
        ll a, b;
        Line() : a(0), b(inf) {}
        Line(ll _a, ll _b) : a(_a), b(_b) {}
        ll cal(ll x) { return a * x + b; }
    };
    int n;
    vector <Line> f;
    LiChaoTree(int N) : n(N), f(n * 4 + 5) {};
    void reset(int N) {
    	n = N;
    	f.resize(n * 4 + 5);
    }
    void add(int x, int lx, int rx, Line line) {
        if (lx == rx) {
            if (line.cal(lx) < f[x].cal(lx))
                f[x] = line;
            return;
        }
        int m = (lx + rx) >> 1;
        if (line.a > f[x].a) swap(line, f[x]);
        if (line.cal(m) < f[x].cal(m)) {
            swap(line, f[x]);
            add(x << 1, lx, m, line);
        }
        else add(x << 1 | 1, m + 1, rx, line);
    }

    ll qry(int x, int lx, int rx, int p) {
        ll ans = f[x].cal(p);
        if (lx == rx) return ans;
        int m = (lx + rx) >> 1;
        if (p <= m) return min(ans, qry(x << 1, lx, m, p));
        else return min(ans, qry(x << 1 | 1, m + 1, rx, p));
    }
    void add(ll a, ll b) { add(1, 1, n, Line(a, b)); }
    ll qry(ll x) { return qry(1, 1, n, x); }

};

int n, k;
int w[N];
ll dp[K][N], dsum[N], sum[N];

ll func(ll j, ll i) {
	return (-i * sum[j - 1] + i * sum[i] - dsum[i] + j * (sum[j - 1] - sum[j]) + dsum[j]);
}

void run_case() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> w[n - i + 1];
	}

	for (int i = 1; i <= n; ++i) {
		// debug(w[i]);
		sum[i] = sum[i - 1] + w[i];
		dsum[i] = dsum[i - 1] + i * w[i];
	}

	for (int i = 1; i <= n; ++i) {
		dp[1][i] = func(1, i);
	}

	LiChaoTree lc(n);
	for (int x = 2; x <= k; ++x) {
		lc.reset(n);
		lc.add(0, 0);
		for (int i = 1; i <= n; ++i) {
			dp[x][i] = 1ll * i * sum[i] - dsum[i] + lc.qry(i);
			// debug(dp[x][i], x, i);
			lc.add(-sum[i - 1], 1ll * i * (sum[i - 1] - sum[i]) + dsum[i] + dp[x - 1][i - 1]);
		}
	}
	cout << dp[k][n] << "\n";
	// debug(dp[1][3]);
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
