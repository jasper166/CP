#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using T = pair <int, int>;
const int N = 1e4 + 5;
int n, m, t;
vector <T> adj[N];
int c[N], d[N], pa[N];
ll tot[N];

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    // freopen("shortcut.in", "r", stdin);
    // freopen("shortcut.out", "w", stdout);

    cin >> n >> m >> t;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= m; ++i) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	adj[u].push_back({w, v});
    	adj[v].push_back({w, u});
    }
   	


    for (int i = 1; i <= n; ++i) d[i] = 1e9;
	priority_queue <T, vector <T>, greater <T>> q;
	d[1] = 0;
	q.push({d[1], 1});
	while (!q.empty()) {
		auto [du, u] = q.top(); q.pop();
		if (du > d[u]) continue;
		for (auto [w, v] : adj[u]) {
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pa[v] = u;
				q.push({d[v], v});
			}
			else if (d[v] == d[u] + w && u < pa[v]) { // keep lexicographically order
				pa[v] = u;
				q.push({d[v], v});
			} 
		}
	}


	for (int i = 1; i <= n; ++i) {
		int j = i;
		while (j) {
			tot[j] += c[i];
			j = pa[j];
		}
	}

	ll ans = 0; // greatest reduction travel time after using min path to 1: 
	for (int i = 1; i <= n; ++i) {
		int reduced_cost = d[i] - t;
		ans = max(ans, 1LL * tot[i] * reduced_cost);
	}
	cout << ans << "\n";
    
    return 0;
}
