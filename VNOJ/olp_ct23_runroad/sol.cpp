#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
const int MOD = 1e9 + 7;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif


	int n, t;
	cin >> n >> t;
	vector <int> h(n + 5);
	vector <pair <int, int>> edges;

	for (int i = 1; i <= n; ++i) cin >> h[i];
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		edges.emplace_back(u, v);
	}

	// counting all triplets having max h[u] <= t
	auto solve = [&] (int d) -> int {
		vector <vector <int>> adj(n + 5, vector <int> ());
		vector <int> sz(n + 5, 0);
		vector <int> root(n + 5, 0);

		function <void(int, int)> dfs = [&] (int u, int p) -> void {
			sz[u] = 1;
			root[u] = p;
			for (int v : adj[u]) {
				if (root[v]) continue;
				dfs(v, p);
				sz[u] += sz[v];
			}
		};

		for (int i = 1; i < n; ++i) {
			auto [u, v] = edges[i - 1];
			if (h[u] <= d && h[v] <= d) {	
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}

		for (int i = 1; i <= n; ++i)
			if (!root[i])
				dfs(i, i);

		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			int in = sz[i];
			int out = sz[root[i]] - sz[i];

			// debug(sz[i]);
			// choose 1 of in and 2 of out
			ans += (in * (1ll * out * (out - 1) / 2 % MOD)) % MOD;
			ans %= MOD;

			// choose 2 of in and 1 of out
			ans += (out * (1ll * in * (in - 1) / 2 % MOD)) % MOD;
			ans %= MOD;
		}
		return ans;
	};

	ll ret = (solve(t) - solve(t - 1) + MOD) * 2 % MOD;
	cout << ret << "\n";
}

