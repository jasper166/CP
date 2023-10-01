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
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
const int LG = 20;

struct Node {
	int ans, sum, prf, suf;
	Node (int val = 0, int t = 0) {
		sum = val;
		if (t) ans = prf = suf = max(0, val);
		else ans = prf = suf = min(0, val);
	}
};

Node merge(Node l, Node r, int t) {
	Node x;
	if (t) {
		x.sum = l.sum + r.sum;
		x.ans = max({l.ans, r.ans, l.suf + r.prf});
		x.prf = max(l.prf, l.sum + r.prf);
		x.suf = max(r.suf, l.suf + r.sum);
	}
	else {
		x.sum = l.sum + r.sum;
		x.ans = min({l.ans, r.ans, l.suf + r.prf});
		x.prf = min(l.prf, l.sum + r.prf);
		x.suf = min(r.suf, l.suf + r.sum);	
	}
	return x;
}

int up[LG][N];
int dep[N];
Node f[2][LG][N];
int n, q;
vector <int> adj[N];
int c[N];

void dfs(int u, int p) {
	for (int v : adj[u]) {
		if (v == p) continue;
		dep[v] = dep[u] + 1;
		up[0][v] = u;
		f[0][0][v] = Node(c[v], 0);
		f[1][0][v] = Node(c[v], 1);
		for (int i = 1; i < LG; ++i) {
			f[0][i][v] = merge(f[0][i - 1][v], f[0][i - 1][up[i - 1][v]], 0);
			f[1][i][v] = merge(f[1][i - 1][v], f[1][i - 1][up[i - 1][v]], 1);
			up[i][v] = up[i - 1][up[i - 1][v]];
		}
		dfs(v, u);
	}
}

int qry(int u, int v, int t) {
	Node lc, rc;
	if (dep[u] != dep[v]) {
		if (dep[u] < dep[v]) swap(u, v);
		int k = dep[u] - dep[v];
		for (int i = 0; (1 << i) <= k; ++i) {
			if (k & (1 << i)) {
				lc = merge(lc, f[t][i][u], t);
				u = up[i][u];
			}
		}
	}

	if (u != v) {
		int k = 0;
		while ((1 << k) <= dep[u]) ++k;
		for (int i = k; i >= 0; --i) {
			if (up[i][u] != up[i][v]) {
				lc = merge(lc, f[t][i][u], t);
				rc = merge(rc, f[t][i][v], t);
				u = up[i][u];
				v = up[i][v];
			}
		}
		lc = merge(lc, f[t][0][u], t);
		rc = merge(rc, f[t][0][v], t);
		u = up[0][u];
	}
	// Notice, why we have to swap info of rc here
	swap(rc.prf, rc.suf);
	lc = merge(lc, f[t][0][u], t);
	return merge(lc, rc, t).ans;
}

void run_case() {
	n = c[1] = 1;
	f[0][0][1] = Node(c[1], 0);
	f[1][0][1] = Node(c[1], 1);

	cin >> q;
	vector <array<int, 3>> queries;
	while (q--) {
		char cmd;
		cin >> cmd;
		if (cmd == '+') {
			int u, w;
			cin >> u >> w;
			c[++n] = w; 
			adj[u].push_back(n);
			adj[n].push_back(u);
			// debug(u, n);
		}
		else {
			int u, v, k;
			cin >> u >> v >> k;
			queries.push_back({u, v, k});
		}
	}
	
	dfs(1, 0);
	for (auto [u, v, k] : queries) {
		int x = qry(u, v, k >= 0);
		// debug(x, u, v, k);
		bool ans = (k < 0 && x <= k) || (k >= 0 && x >= k); 
		cout << (ans? "YES\n" : "NO\n");
	}

	// Reset 
	for (int i = 1; i <= n; ++i) {
		dep[i] = c[i] = 0;
		adj[i].clear();
		for (int j = 0; j < LG; ++j) {
			up[j][i] = 0; 
			f[0][j][i] = f[1][j][i] = Node();
		}
	}
}
/*
	Due to the fact that x = -1 or x = -1, if there exists a segment which 
	have sum >= k (or sum <= k) then a segment with sum equal to k can be found (easily proven)
	-> We only have to check maximum (minimum) subarray sum on the path from u to v.
*/

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in2", "r", stdin);
    #endif

    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}