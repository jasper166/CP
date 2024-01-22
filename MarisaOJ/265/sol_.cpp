#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 1e3 + 5;
double X;
int n, m;
int x[N], y[N];

vector <pair <double, int>> adj[N];
double dis(int i, int j) {
	double dX = double (x[i] - x[j]);
	double dY = double (y[i] - y[j]);
	return sqrt(dX * dX + dY * dY);
}

double d[N];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> n >> m >> X;
    for (int i = 1; i <= n; ++i)
    	cin >> x[i] >> y[i];
    for (int i = 1; i <= m; ++i) {
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back({0.0, v});
    	adj[v].push_back({0.0, u});
    }

    // Dung them canh tu du lieu da cho
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		if (i == j) continue;
    		double w = dis(i, j);
    		if (w <= X) {
    			adj[i].push_back({w, j});
    			adj[j].push_back({w, i});
    		}
    	}
    }

    // Dijkstra so thuc
    using T = pair <double, int>;
    for (int i = 1; i <= n; ++i) d[i] = 1e15;
    priority_queue <T, vector <T>, greater <T>> q;
	d[1] = 0.0;
	q.push({d[1], 1});
	while (!q.empty()) {
		auto [du, u] = q.top(); q.pop();
		if (du > d[u]) continue;
		for (auto [w, v] : adj[u]) {
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push({d[v], v});
			}
		}
	}

	ll ans;
	if (d[n] == 1e15) ans = -1;
	else ans = (d[n] * 1000LL);
	cout << ans << "\n";
}
