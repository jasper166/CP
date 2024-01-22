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
const int BLOCK = 331;

int n, q;
vector <int> adj[N];
int pa[N];

void dfs(int u, int p) {
	pa[u] = p;
	for (int v : adj[u])
		if (v ^ p)
			dfs(v, u);
}

int tin[N], tout[N], tree[N];
int id[N];
bool vis[N];
int timer = 0;
ll c[N];
ll lzy[BLOCK];

void bfs() {
	queue <int> q; q.push(1);
	
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (!vis[u]) {
			tree[++timer] = u;
			id[u] = timer;
		}
		vis[u] = 1;
		vector <int> near;
		int l = timer;
		for (int v : adj[u]) {
			if (!vis[v]) {
				tree[++timer] = v;
				id[v] = timer;
				q.push(v);
				near.push_back(v);
				vis[v] = 1;
			}
		}
		int r = l + near.size();
		// no child
		if (l != r) {
			tin[u] = l + 1;
			tout[u] = r;
		} 
	}
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

  	cin >> n >> q;
  	for (int i = 1; i < n; ++i) {
  		int u, v;
  		cin >> u >> v;
  		adj[u].push_back(v);
  		adj[v].push_back(u);
  	}

  	dfs(1, 0);
  	bfs();

  	for (int i = 1; i <= n; ++i) {
  		debug(tree[i]);
  	}
  	for (int i = 1; i <= q; ++i) {
  		int cmd, u;
  		ll d;
  		cin >> cmd;
  		if (cmd == 1) {
  			cin >> u >> d;
  			// parent u
  			int p = pa[u];
  			c[id[p]] += d;

  			if (!tin[u] || !tout[u]) continue;
  			
  			// child u
  			int l = tin[u], L = l / BLOCK;
  			int r = tout[u], R = r / BLOCK;
  			if (L == R) {
  				for (int i = l; i <= r; ++i) c[i] += d;
  			}
  			else {
  				for (int i = l; i < (L + 1) * BLOCK; ++i)
  					c[i] += d;
				for (int i = R * BLOCK; i <= r; ++i)
					c[i] += d;
				for (int i = L + 1; i < R; ++i)
					lzy[i] += d;
  			}
  			// debug(l, r, p);
  		}
  		else {
  			cin >> u;
  			// debug(c[id[u]]);
  			cout << (c[id[u]] + lzy[id[u] / BLOCK]) << "\n";
  		}
  	}
}

