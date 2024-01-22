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
const int K = 18;

int n;
int c[N], f[N];
vector <int> adj[N];
int dep[N], up[K][N];
int tin[N], tout[N], tree[N << 1];
int timer = 0;
//
void dfs(int u, int p) {
	tin[u] = ++timer;
	tree[timer] = u;
	for (int v : adj[u]) {
		if (v ^ p) {
			up[0][v] = u;
			dep[v] = dep[u] + 1;
			for (int i = 1; i < K; ++i)
				up[i][v] = up[i - 1][up[i - 1][v]];
			dfs(v, u);
		} 
	}
	tout[u] = ++timer;
	tree[timer] = u;
}

int lca(int u, int v) {
	if (dep[u] != dep[v]) {
		if (dep[u] < dep[v]) swap(u, v);
		int diff = dep[u] - dep[v];
		for (int i = K - 1; i >= 0; --i)
			if (diff & (1 << i))
				u = up[i][u];
	}
	if (u == v) return u;
	for (int i = K - 1; i >= 0; --i) {
		if (up[i][u] != up[i][v]) {
			u = up[i][u];
			v = up[i][v];
		}
	}
	return up[0][u];
}
//
int cnt[2][N];
ll tot = 0;
ll ans[N];
int pa[N];
bool vis[N];

void upd(int u, int val) {
	int x = c[u];
	tot -= 1LL * cnt[0][x] * cnt[1][x];
	cnt[f[u]][x] += val;
	tot += 1LL * cnt[0][x] * cnt[1][x];
} 
void add(int i) {
	int u = tree[i];
	vis[u] ^= 1;
	if (vis[u]) upd(u, 1);
	else upd(u, -1);
}
void del(int i) {
	int u = tree[i];
	vis[u] ^= 1;
	if (vis[u]) upd(u, 1);
	else upd(u, -1);
}

struct Query {
	int l, r, id;
	bool operator < (const Query& ot) {
		if (l / BLOCK == ot.l / BLOCK)
			return (l / BLOCK & 1)? r < ot.r : r > ot.r;
		return (l / BLOCK < ot.l / BLOCK); 
	} 
};

int q;
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> f[i];
   	for (int i = 1; i <= n; ++i) cin >> c[i];
   	for (int i = 1; i < n; ++i) {
   		int u, v;
   		cin >> u >> v;
   		adj[u].push_back(v);
   		adj[v].push_back(u);
   	}
   	dfs(1, 0);

   	vector <int> vals;
   	for (int i = 1; i <= n; ++i) vals.push_back(c[i]);
   	sort(vals.begin(), vals.end());
   	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
   	for (int i = 1; i <= n; ++i)
   		c[i] = (int) (lower_bound(vals.begin(), vals.end(), c[i]) - vals.begin());

   	cin >> q;
   	vector <Query> queries;
   	for (int i = 1; i <= q; ++i) {
   		int u, v; cin >> u >> v;
   		if (tin[u] > tin[v]) swap(u, v);
   		int p = lca(u, v);
   		int L, R;
   		if (p != u && p != v) {
   			L = tout[u];
   			R = tin[v];
   			pa[i] = p;
   		}
   		else {
   			L = tin[u];
   			R = tin[v];
   		}
   		queries.push_back({L, R, i});
   	}
   	sort(queries.begin(), queries.end());
   	int l = 1, r = 0;
   	for (auto&[L, R, id] : queries) {

   		while (l > L) add(--l);
   		while (r < R) add(++r);
   		while (l < L) del(l++);
   		while (r > R) del(r--);

   		if (pa[id]) {
   			add(tin[pa[id]]);
   			ans[id] = tot;
   			del(tin[pa[id]]);
   		}
   		else
   			ans[id] = tot;
   	}
   	for (int i = 1; i <= q; ++i)
   		cout << ans[i] << "\n"; 

}

