#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 1e5 + 5;
const int K = 18;
const int BLOCK = 311;

int n, m;
vector <int> adj[N];
int dep[N];
int up[K][N];

void dfs(int u, int p) {
	for (int v : adj[u]) {
		if (v ^ p) {
			up[0][v] = u;
			dep[v] = dep[u] + 1;
			for (int k = 1; k < K; ++k)
				up[k][v] = up[k - 1][up[k - 1][v]];
			dfs(v, u);
		}
	}
}

int dis(int u, int v) {
	int lca;
	int U = u, V = v;
	if (dep[u] != dep[v]) {
		if (dep[u] < dep[v]) swap(u, v);
		int k = dep[u] - dep[v];
		for (int i = K - 1; i >= 0; --i) {
			if (k & (1 << i)) {
				u = up[i][u];
			}
		}
	}

	if (u == v) lca = u;
	else {
		for (int i = K - 1; i >= 0; --i) {
			if (up[i][u] != up[i][v]) {
				u = up[i][u];
				v = up[i][v];
			}
		}
		lca = up[0][u];
	}
	return dep[U] + dep[V] - 2 * dep[lca];
}

bool paint[N];
struct Bucket {
	vector <int> vertex, f;
	Bucket() {
		init();
	}
	void init() {
		f.assign(n + 5, 1e9);
		queue <int> q;
		for (int i = 1; i <= n; ++i) {
			if (paint[i]) { 
				q.push(i);
				f[i] = 0;
			}
		}

		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int& v : adj[u]) {
				if (f[v] > f[u] + 1) {
					q.push(v);
					f[v] = f[u] + 1;
				}
			}
		}

		vertex.clear();
	}
	void add(int u) {
		vertex.push_back(u);
	}
	int qry(int u) {
		// debug(vertex);
		int ans = f[u];
		for (int& v : vertex) 
			ans = min(ans, dis(u, v));
		return ans;
	}
};

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    dfs(1, 0);
    
    paint[1] = 1;
    Bucket b;
   	for (int i = 1; i <= m; ++i) {
   		int cmd, u;
   		cin >> cmd >> u;
   		// New block -> rebuild
   		if (i % BLOCK == 0) b.init();
   		if (cmd == 1) {
   			paint[u] = 1;
   			b.add(u);
   		}
   		else 
   			cout << b.qry(u) << "\n";
   	} 
}

