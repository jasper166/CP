#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int BLOCK = 230;
const int N = 5e4 + 5;
const int K = 18;

int n, q;
int c[N];
vector <int> adj[N];
vector <int> vex[N];
vector <int> dis[N];
// dis(x, u) : nearest distance from u to x-colored node

int dep[N];
int st[N], lg[N << 1], tree[N << 1];
int up[K][N << 1];
int timer = 0;
void dfs(int u, int p) {
	st[u] = ++timer;
	tree[timer] = u; 
	for (int v : adj[u]) {
		if (v ^ p) {
			dep[v] = dep[u] + 1;
			dfs(v, u);
			tree[++timer] = u; 
		}
	}
}

int minD(int u, int v) { return (dep[u] < dep[v]? u : v); }
void build() {
	lg[1] = 0;
	for (int i = 2; i <= timer; ++i)
		lg[i] = lg[i / 2] + 1;
	for (int i = 1; i <= timer; ++i)
		up[0][i] = tree[i];

	for (int k = 1; k < K; ++k) {
		int step = 1 << (k - 1);
		for (int i = 1; i + step <= timer; ++i)
			up[k][i] = minD(up[k - 1][i], up[k - 1][i + step]);
	}
}
int lca(int u, int v) {
	int l = st[u]; int r = st[v];
	if (l > r) swap(l, r);
	int k = lg[r - l + 1];
	return minD(up[k][l], up[k][r - (1 << k) + 1]);
}
int getDis(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }

void bfs(int x) {
	vector <int> f(n + 5, 1e9);
	dis[x].assign(n + 5, 1e9);
	vector <bool> vis(n + 5, 0);
	queue <int> q;
	for (int v : vex[x]) {
		q.push(v);
		f[v] = 0;
		vis[v] = 1;
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (!vis[v]) {
				vis[v] = 1;
				f[v] = f[u] + 1;
				q.push(v);
			}
		}
	}
	for (int u = 1; u <= n; ++u) 
		dis[x][u] = f[u];
}

int qry(int u, int x) {
	int ans = (c[u] == x? 0 : 1e9);
	for (int v : vex[x])
		ans = min(ans, getDis(u, v));
	return ans;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> c[i];
   	for (int i = 1; i < n; ++i) {
   		int u, v;
   		cin >> u >> v;
   		adj[u].push_back(v);
   		adj[v].push_back(u);
   	}

   	dfs(1, 0);
   	build();

    vector <int> hvy;
    for (int i = 1; i <= n; ++i) {
    	vex[c[i]].push_back(i);
    	if (vex[c[i]].size() > BLOCK) 
    		hvy.push_back(c[i]);
    }
    
    sort(hvy.begin(), hvy.end());
    hvy.resize(unique(hvy.begin(), hvy.end()) - hvy.begin());

    for (int x : hvy) 
    	bfs(x);
    for (int _q = 1; _q <= q; ++_q) {
    	int u, x; 
    	cin >> u >> x;
    	int ans;
    	if (vex[x].size() > BLOCK)
    		ans = dis[x][u];
    	else {
    		ans = qry(u, x);
    	}
    	if (ans == (int) 1e9) ans = -1;
		cout << ans << "\n";
    }
}