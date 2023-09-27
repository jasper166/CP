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

// #define int long lon
using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
const int LG = 18;

struct DisjointSets {
	vector <int> pa, sz;
	int n;
	DisjointSets(int _n) {
		n = _n;
		pa.resize(_n + 5);
		sz.resize(_n + 5);
		for (int i = 1; i <= n; ++i) pa[i] = i, sz[i] = 1;
	} 
int get(int u) { return (u == pa[u]? u : pa[u] = get(pa[u])); }
bool unite(int u, int v) {
	u = get(u);
	v = get(v);
	if (u == v) return 0;
	if (sz[u] < sz[v]) swap(u, v);
	sz[u] += sz[v];
	pa[v] = u;
	return 1;
}
};
struct Edge {
	int u, v, w, id;
	bool operator < (Edge o) const {
		return w < o.w;
	}
};

int n, m;
vector <pii> adj[N];
int up[LG][N];
int mx[LG][N];
int dep[N];

void dfs(int u, int p) {
	// debug(u);
	for (auto [w, v] : adj[u]) {
		if (v ^ p) {
			up[0][v] = u;
			mx[0][v] = w;
			dep[v] = dep[u] + 1;

			for (int k = 1; k < LG; ++k) {
				mx[k][v] = max(mx[k - 1][v], mx[k - 1][up[k - 1][v]]);
				up[k][v] = up[k - 1][up[k - 1][v]];
			}
			dfs(v, u);
		}
	}
}

int qry(int u, int v) {
	int ans = 0;
	if (dep[u] != dep[v]) {
		if (dep[u] < dep[v]) swap(u, v);
		int k = dep[u] - dep[v];
		for (int i = 0; (1 << i) <= k; ++i) {
			if (k & (1 << i)) {
				ans = max(ans, mx[i][u]);
				u = up[i][u];
			}
		}
		// debug(ans);
	}

	if (u == v) return ans;
	int k = 0;
	while ((1 << k) <= dep[u]) ++k;
	for (int i = k; i >= 0; --i) {
		if (up[i][u] != up[i][v]) {
			ans = max({ans, mx[i][u], mx[i][v]});
			u = up[i][u];
			v = up[i][v];
		}
	}
	ans = max({ans, mx[0][u], mx[0][v]});
	return ans;
}

ll ans[N];
void run_case() {
	cin >> n >> m;
	vector <Edge> ed;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;	
		ed.push_back({u, v, w, i});
	}
	sort(ed.begin(), ed.end());
	ll mst = 0;
	DisjointSets dsu(n);
	for (auto [u, v, w, id] : ed) {
		if (dsu.unite(u, v)) {
			mst += w;
			// debug(u, v);
			adj[u].push_back({w, v});
			adj[v].push_back({w, u});
		}
	}

	dfs(1, 0);
	// for (int i = 1; i <= n; ++i) {
	// 	debug(mx[0][i]);
	// }
	// debug(qry(1, 4));
	for (auto [u, v, w, id] : ed) {
		int x = qry(u, v);
		// debug(x);
		ans[id] = mst + w - x;
	}
	for (int i = 1; i <= m; ++i) cout << ans[i] << "\n";

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
