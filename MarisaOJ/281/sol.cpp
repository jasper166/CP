#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

// const int BLOCK = 331;
const int B = 331;
const int N = 1e5 + 5;
const int K = 18;

int n, q;
vector <int> adj[N];
int pa[N];
// Euler-tour LCA
int st[N], dep[N], lg[N << 1];
int tree[N << 1];
pair <int, int> up[K][N << 1];
int timer = 0;

void dfs(int u, int p) {
	tree[++timer] = u;
	st[u] = timer;
	pa[u] = p;
	for (int v : adj[u]) {
		if (v ^ p) {
			dep[v] = dep[u] + 1;
			dfs(v, u);
			tree[++timer] = u;
		}
	}
}
void build() {
	lg[1] = 0;
	for (int i = 2; i <= timer; ++i) lg[i] = lg[i / 2] + 1;
	for (int i = 1; i <= timer; ++i)
		up[0][i] = {dep[tree[i]], tree[i]};
	for (int k = 1; k < K; ++k) {
		int step = 1 << (k - 1);
		for (int i = 1; i + step <= timer; ++i)
			up[k][i] = min(up[k - 1][i], up[k - 1][i + step]);
	}
}
int lca(int u, int v) {
	int l = st[u], r = st[v];
	if (l > r) swap(l, r);
	int k = lg[r - l + 1];
	return min(up[k][l], up[k][r - (1 << k) + 1]).second;
}
int dis(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
// 
int BLOCK;
int f[B][N]; // counting color x frequency on path(1, u);
int c[N];
int id = 0;
int cVal[B];
map <int, int> cPos;
// color, compressed color
bool hvy[N];

void cal(int u, int p) {
	int x = cPos[c[u]];
	if (hvy[u]) ++f[x][u];
	for (int v : adj[u]) {
		if (v ^ p) {
			for (int i = 0; i < id; ++i)
				f[i][v] += f[i][u];
			cal(v, u);
		}
	}
}
//Brute for O(sqrt(N))
int brute(int u, int v) {
	int p = lca(u, v);
	int k = dis(u, v);
	vector <int> vex;
	map <int, int> cnt;
	while (u != p) {
		cnt[c[u]]++;
		vex.push_back(c[u]);
		u = pa[u];
	}
	while (v != p) {
		cnt[c[v]]++;
		vex.push_back(c[v]);
		v = pa[v];
	}
	cnt[c[p]]++;
	vex.push_back(c[p]);
	// debug(u, v, p, cnt, (k + 1) / 2 + 1);
	for (int x : vex) {
		if (cnt[x] >= (k + 1) / 2 + 1) {
			return x;
		}
	}
	return -1;
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

   	BLOCK = sqrt(n);

   	map <int, int> cnt;
   	for (int i = 1; i <= n; ++i)
   		cnt[c[i]]++;
   	for (int i = 1; i <= n; ++i)
   		if (cnt[c[i]] >= BLOCK)
   			hvy[i] = 1;
   	for (auto [x, cx] : cnt) {
   		// debug(x, cx);
   		if (cx >= BLOCK) {
   			cPos[x] = id;
   			cVal[id] = x;
   			++id;
   		}
   	}

   	
   	dfs(1, 0);
   	build();
   	cal(1, 0);

   	for (int _q = 1; _q <= q; ++_q) {
   		int u, v; cin >> u >> v;
   		int p = lca(u, v);
   		int k = dis(u, v);
   		int ans = -1;
   		if (k >= BLOCK) {
   			// debug(u, v, k, p);
   			for (int x = 0; x < id; ++x) {
   				int cur = f[x][u] + f[x][v] - 2 * f[x][p] + (c[p] == cVal[x]);
   				if (cur >= (k + 1) / 2 + 1) {
   					ans = cVal[x];
   				}
   			}
   		}
   		else
   			ans = brute(u, v);
   		cout << ans << "\n";
   	}
}

