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
const int BLOCK = 2155;
const int K = 18;

vector <int> primes[N];
int pr[N];
void prepare() {
	for (int i = 0; i < N; ++i) pr[i] = i;
	for (int i = 2; i * i < N; ++i) {
		if (pr[i] == i) {
			for (int j = 2 * i; j < N; j += i)
				pr[j] = min(pr[j], i);
		}
	}
	for (int i = 2; i < N; ++i) {
		int x = i;
		while (x != 1) {
			int j = pr[x];
			primes[i].push_back(j);
			while (x % j == 0) x /= j;
		}
	}
}

int c[N];
vector <int> adj[N];
int up[K][N], dep[N];
int tin[N], tout[N], tree[N << 1];
int timer = 0;
//
void dfs(int u, int p) {
	tin[u] = ++timer;
	tree[timer] = u;
	for (int v : adj[u]) {
		if (v ^ p) {
			up[0][v] = u;
			for (int k = 1; k < K; ++k)
				up[k][v] = up[k - 1][up[k - 1][v]];
			dep[v] = dep[u] + 1;
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
int cnt[N];
bool vis[N];
void upd(int x, int val) {
	int sz = primes[x].size();
	for (int msk = 1; msk < (1 << sz); ++msk) {
		int y = 1;
		for (int j = 0; j < sz; ++j)
			if (msk & (1 << j))
				y *= primes[x][j];
		cnt[y] += val;
	}
}
void add(int i) { 
	int u = tree[i];
	vis[u] ^= 1;
	if (vis[u])
		upd(c[u], 1);
	else 
		upd(c[u], -1); 
}
void del(int i) {
	int u = tree[i];
	vis[u] ^= 1;
	if (vis[u])
		upd(c[u], 1);
	else 
		upd(c[u], -1); 
}
int cal(int x) {
	int sz = primes[x].size();
	int res = 0;
	for (int msk = 1; msk < (1 << sz); ++msk) {
		int y = 1;
		int c = 0;
		for (int j = 0; j < sz; ++j) {
			if (msk & (1 << j)) {
				y *= primes[x][j];
				++c;
			}
		}
		(c & 1)? res += cnt[y] : res -= cnt[y];
	}
	return res;
}
struct Query {
	int l, r, id, x;
	bool operator < (const Query& ot) const {
		if (l / BLOCK != ot.l / BLOCK)
			return (l < ot.l);
		if (r / BLOCK != ot.r / BLOCK)
			return r < ot.r;
		return id < ot.id;
	}
};

vector <Query> queries;
int pa[N];
int n, q;
int qx[N], qy[N];
int ans[N];
int prv[N];
// Query to find numbers of value y on the path(u, v) such gcd(x, y) = 1 with given x;
// Inclusion - Exclusion -> total - |gcd(x, y) > 1|
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    prepare();

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs(1, 0);

    // for (int i = 1; i <= n; ++i) {
    // 	debug(tin[i], tout[i]);
    // }
    vector <int> upds;
    for (int i = 1; i <= q; ++i) {
    	int cmd; cin >> cmd;
    	if (cmd) {
    		int u, v, x;
    		cin >> u >> v >> x;
    		int L, R;
    		if (tin[u] > tin[v]) swap(u, v);
    		int p = lca(u, v);
    		if (p == u) {
    			L = tin[u];
    			R = tin[v];
    		}
    		else {
    			L = tout[u];
    			R = tin[v];
    		}
    		queries.push_back({L, R, i, x});
    		pa[i] = p;
    		// total node on (u, v)
    		ans[i] = dep[u] + dep[v] - 2 * dep[p] + 1;
    	}
    	else {
    		cin >> qx[i] >> qy[i];
    		upds.push_back(i);
    	}
    }

    sort(queries.begin(), queries.end());

    int l = 1, r = 0, t = -1;
    for (int i = 0; i < (int) queries.size(); ++i) {
    	auto [L, R, id, x] = queries[i];
    	// debug(L, R, id, x);

    	while (l > L) add(--l);
    	while (r < R) add(++r);
    	while (l < L) del(l++);
    	while (r > R) del(r--);

    	while (t + 1 < (int) upds.size() && upds[t + 1] < id) {
    		++t;
    		int u = qx[upds[t]];
    		int val = qy[upds[t]];
    		// debug(u, val);	
    		if (vis[u]) {
    			upd(c[u], -1);
    			upd(val, 1);
    		}
    		prv[t] = c[u];
    		c[u] = val;
    	}
    	// debug(cnt, t);
    	while (t >= 0 && upds[t] > id) {
    		int u = qx[upds[t]];
    		int val = prv[t];
    		if (vis[u]) {
    			upd(c[u], -1);
    			upd(val, 1);
    		}
    		c[u] = val;
    		--t;
    	}
    	// debug(cnt, t);
    	ans[id] -= cal(x);
    	int u = tree[L];
    	int v = tree[R];
    	if (pa[id] != u && pa[id] != v) ans[id] -= (__gcd(c[pa[id]], x) != 1);
    }

    for (int i = 1; i <= q; ++i)
    	if (pa[i])
    		cout << ans[i] << "\n";
}

