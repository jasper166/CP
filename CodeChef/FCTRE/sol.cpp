#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#define int long long
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int K = 18;
const int BLOCK = 311;
const int M = 1e6 + 5;

int pr[M];
int inv[M];
vector <pair <int, int>> factors[M];

int bPow(int a, int b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = (1LL * ans * a) % MOD;
		a = (1LL * a * a) % MOD;
		b >>= 1;
	}
	return ans;
}
void prepare() {
	for (int i = 0; i < M; ++i) pr[i] = i;
	for (int i = 2; i * i < M; ++i) {
		if (pr[i] == i) 
			for (int j = 2 * i; j < M; j += i)
				pr[j] = min(pr[j], i);
	}
	for (int i = 2; i < M; ++i) {
		int x = i;
		while (x != 1) {
			int j = pr[x];
			int c = 0;
			while (x % j == 0) {
				x /= j;
				++c;
			}
			factors[i].emplace_back(j, c);
		}
	}
	for (int i = 0; i < M; ++i) inv[i] = bPow(i, MOD - 2);
}

int c[N];
vector <int> adj[N];
int dep[N], up[K][N];
int tin[N], tout[N], tree[N << 1];
int timer;

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

struct Query {
	int l, r, id;
	bool operator < (const Query& ot) const {
		if (l / BLOCK == ot.l / BLOCK)
			return (l / BLOCK & 1)? r < ot.r : r > ot.r;
		return (l / BLOCK < ot.l / BLOCK);
	}
};

ll prod = 1;
bool vis[N];
int cnt[M];
// map <int, int> cnt;
int n, q;
int pa[N], ans[N];

void upd(int x, int val) {
	if (x == 1) return;
	for (auto& [j, c] : factors[x]) {
		prod *= 1LL * inv[cnt[j] + 1];
		prod %= MOD;
		cnt[j] += c * val;
		prod *= 1LL * (cnt[j] + 1);
		prod %= MOD;
	}
}
void add(int i) {
	int u = tree[i];
	vis[u] ^= 1; 
	if (vis[u]) upd(c[u], 1);
	else upd(c[u], -1); 
}
void del(int i) { 
	int u = tree[i];
	vis[u] ^= 1; 
	if (vis[u]) upd(c[u], 1);
	else upd(c[u], -1); 
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    prepare();
    int T; cin >> T;
    while (T--) {
    	cin >> n;
    	// RS
    	timer = 0;
    	prod = 1;
    	for (int i = 1; i <= n; ++i) {
    		adj[i].clear();
    		vis[i] = 0;
    	}
    	for (int i = 1; i <= q; ++i) {
    		ans[i] = pa[i] = 0;
    	}
    	for (int i = 1; i < M; ++i)
    		cnt[i] = 0;
    	//
    	for (int i = 1; i < n; ++i) {
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}

    	for (int i = 1; i <= n; ++i) cin >> c[i];
    	dfs(1, 0);

    	// debug(n);
    	cin >> q;
  		vector <Query> queries;
    	for (int i = 1; i <= q; ++i) {
    		int u, v;
    		cin >> u >> v;
    		if (tin[u] > tin[v]) swap(u, v);
    		int p = lca(u, v);
    		int L, R;
    		if (p == u) {
    			L = tin[u];
    			R = tin[v];
    		}
    		else {
    			L = tout[u];
    			R = tin[v];
    			pa[i] = p;
    		}
    		queries.push_back({L, R, i});
    	}
    	// debug(upd(18, 1));
    	sort(queries.begin(), queries.end());
    	int l = 1, r = 0;
    	for (int i = 0; i < (int) queries.size(); ++i) {
    		auto [L, R, id] = queries[i];
    		while (l > L) add(--l);
    		while (r < R) add(++r);
    		while (l < L) del(l++);
    		while (r > R) del(r--);

    		// debug(L, R, id, pa[id]);
    		// debug(cnt);
    		if (pa[id]) {
    			add(tin[pa[id]]);
    			ans[id] = prod;
    			del(tin[pa[id]]);
    		}
    		else 
    			ans[id] = prod;
    	}

    	for (int i = 1; i <= q; ++i)
    		cout << ans[i] << "\n";
    }
}