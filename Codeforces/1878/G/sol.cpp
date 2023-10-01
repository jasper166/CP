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
const int N = 2e5 + 5;
const int LG = 20;

int n, q;
int a[N];
vector <int> adj[N];
int dep[N];
int up[LG][N];
int dp[LG][N];

void dfs(int u, int p) {
	for (int v : adj[u]) {
		if (v ^ p) {
			up[0][v] = u;
			dp[0][v] = a[u];
			dep[v] = dep[u] + 1;
			for (int k = 1; k < LG; ++k) {
				dp[k][v] = dp[k - 1][v] | dp[k - 1][up[k - 1][v]];
				up[k][v] = up[k - 1][up[k - 1][v]];
			}
			dfs(v, u);
		}
	}
}

int getLCA(int u, int v) {
	if (dep[u] != dep[v]) {
		if (dep[u] < dep[v]) swap(u, v);
		int dis = dep[u] - dep[v];
		for (int k = LG; k >= 0; --k) {
			if (dis & (1 << k))
				u = up[k][u];
		}
	}
	if (u == v) return u;
	for (int k = LG - 1; k >= 0; --k) {
		if (up[k][u] != up[k][v]) {
			u = up[k][u];
			v = up[k][v];
		}
	}
	return up[0][u];
}

int cal(int u, int x) {
	if (dep[u] < dep[x]) swap(u, x);
	int dis = dep[u] - dep[x];
	int ans = a[u];
	for (int k = LG - 1; k >= 0; --k) {
		if (dis & (1 << k)) {
			ans |= dp[k][u];
			u = up[k][u];
		}
	}
	return ans;
}


int qry(int u, int v, int x) {
	int ans = 0;
	int sumR = cal(v, x);
	int sumL = a[u];
	
	debug(sumL, sumR, u, v, x);
	while (true) {
		debug(u, x);
		int cur = __builtin_popcount(sumL) + __builtin_popcount(cal(u, x) | sumR);
		ans = max(ans, cur);
		int dis = dep[u] - dep[x];
		/*
			Little note: because of OR -> sumL will always increase, then this while loop runs at
			most log2(max(ai)) times 
		*/
		// Binary jumping as long as this segment won't change the current OR sum.
		for (int k = LG - 1; k >= 0; --k) {
			if (dis & (1 << k) && ((sumL | dp[k][u]) == sumL))
				u = up[k][u];
		}
		if (u == x) break;
		u = up[0][u];
		sumL |= a[u];
	}
	// debug(ans);
	return ans;
}

void run_case() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	// debug(cal(2, 3));
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		int u, v;
		cin >> u >> v;
		int x = getLCA(u, v);
		int ans = max(qry(u, v, x), qry(v, u, x));
		cout << ans << " \n"[i == q];
	}

	//Reset
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
		dep[i] = 0;
		for (int k = 0; k < LG; ++k)
			up[k][i] = dp[k][i] = 0;
	}
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    // cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
