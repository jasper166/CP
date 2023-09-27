
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
const int LG = 17;

int mx[LG][N], mi[LG][N], up[LG][N];
int dep[N];
vector <pii> adj[N];
int n, q;

void dfs(int u, int p) {
	for (auto [w, v] : adj[u]) {
		if (v ^ p) {
			dep[v] = dep[u] + 1;
			up[0][v] = u;
			mi[0][v] = mx[0][v] = w;
			for (int k = 1; k < LG; ++k) {
				mi[k][v] = min(mi[k - 1][v], mi[k - 1][up[k - 1][v]]);
				mx[k][v] = max(mx[k - 1][v], mx[k - 1][up[k - 1][v]]);
				up[k][v] = up[k - 1][up[k - 1][v]];
			}
			dfs(v, u);
		}
	}
}

pii qry(int u, int v) {
	pii ans = {INF, -INF};
	if (dep[u] != dep[v]) {
		if (dep[u] < dep[v]) swap(u, v);
		int k = dep[u] - dep[v];
		for (int i = 0; (1 << i) <= k; ++i) {
			if (k & (1 << i)) {
				ans.fi = min(ans.fi, mi[i][u]);
				ans.se = max(ans.se, mx[i][u]);
				u = up[i][u];
			}
		}
	}

	if (u == v) return ans;

	int k = 0;
	while ((1 << k) <= dep[u]) ++k;
	for (int i = k; i >= 0; --i) {
		if (up[i][u] != up[i][v]) {
			ans.fi = min({ans.fi, mi[i][u], mi[i][v]});
			ans.se = max({ans.se, mx[i][u], mx[i][v]});
			u = up[i][u];
			v = up[i][v];
		}
	}
	ans.fi = min({ans.fi, mi[0][u], mi[0][v]});
	ans.se = max({ans.se, mx[0][u], mx[0][v]});
	debug(up[0][u], k);
	return ans;
}

void run_case() {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({w, v});
		adj[v].push_back({w, u});
	}
	memset(mi, 0x3f, sizeof mi);
	// debug(mi[0][2]);
	dfs(1, 0);
	// debug(mx[0][4]);
	cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		pii ans = qry(u, v);
		cout << ans.fi << " " << ans.se << "\n";
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
