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
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e3 + 5;
const int K = 17;

int n, m, k;
vector <pii> adj[N];
int c[K];
ll d[K][N];

void dijkstra(int u) {
	// debug(u);
	for (int i = 1; i <= n; ++i) d[u][i] = INF;
	d[u][u] = 0;
	priority_queue <pii, vector <pii>, greater <pii>> q;
	q.push({0, c[u]});
	while (!q.empty()) {
		auto [dx, x] = q.top(); q.pop();
		if (dx != d[u][x]) continue;
		for (auto [w, y] : adj[x]) {
			if (d[u][x] + w < d[u][y]) {
				d[u][y] = d[u][x] + w;
				q.push({d[u][y], y});
			}
		}
	}
}

ll dp[(1 << K)][K];
void run_case() {
	cin >> n >> m >> k; ++k;
	
	c[0] = 1;
	for (int i = 1; i < k; ++i) cin >> c[i];
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({w, v});
	}
	for (int i = 0; i < k; ++i)
		dijkstra(i);

	// debug(d[2][5]);
	for (int msk = 0; msk < (1 << k); ++msk) 
		for (int i = 0; i < k; ++i)
				dp[msk][i] = INF;
	dp[1][0] = 0;

	for (int msk = 1; msk < (1 << k); ++msk) {
		for (int u = 0; u < k; ++u) {
			if ((msk & (1 << u)) == 0) continue; 
			for (int v = 0; v < k; ++v) {
				if (u == v) continue;
				if (msk & (1 << v)) continue;
				int nxt_msk = msk | (1 << v);
				dp[nxt_msk][v] = min(dp[nxt_msk][v], dp[msk][u] + d[u][c[v]]);
				// debug(msk, nxt_msk, u, v, dp[nxt_msk][v]);
			}
		}
	}
	ll ans = INF;
	for (int u = 1; u < k; ++u) 
		ans = min(ans, dp[(1 << k) - 1][u] + d[u][1]);
	if (ans == INF) ans = -1;
	cout << ans << "\n";
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
