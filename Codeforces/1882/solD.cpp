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

#define int long long
using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

vector <int> adj[N];
int n, a[N], sz[N];
int dp[N][32][2];
int ans[N];

void dfs(int u, int p) {
	sz[u] = 1;
	for (int v : adj[u]) {
		if (v ^ p) {
			dfs(v, u);
			sz[u] += sz[v];
			REP(i, 20) {
				int x = (a[u] & (1 << i)? 1 : 0);
				dp[u][i][x] += dp[v][i][x];
				dp[u][i][x ^ 1] += dp[v][i][x];
			}
		}
	}

	REP(i, 20) {
		int x = (a[u] & (1 << i)? 1 : 0);
		dp[u][i][x ^ 1] += sz[u];
	}
}

void reroot(int u, int v) {
    REP(i, 20) {
        int x = (a[u] & (1 << i)? 1 : 0);
        dp[u][i][x] -= dp[v][i][x];
        dp[u][i][x ^ 1] -= dp[v][i][x];
    }

    ll lst = sz[u];
    sz[u] -= sz[v];
    REP(i, 20) {
        int x = (a[u] & (1 << i)? 1 : 0);
        dp[u][i][x ^ 1] -= lst;
        dp[u][i][x ^ 1] += sz[u];
    }

    REP(i, 20) {
        int x = (a[v] & (1 << i)? 1 : 0);
        dp[v][i][x ^ 1] += sz[u];
    }

    sz[v] += sz[u];

    REP(i, 20) {
        int x = (a[v] & (1 << i)? 1 : 0);
        dp[v][i][x] += dp[u][i][x];
        dp[v][i][x ^ 1] += dp[u][i][x];
    }
}

void dfs2(int u, int p) {
    ll cur = 0;
    REP(i, 20)
        cur += min(dp[u][i][0], dp[u][i][1]) * (1 << i);

    ans[u] = cur;
    for (auto v : adj[u]) {
        if (v ^ p) {
        	reroot(u, v);
	        dfs2(v, u);
	        reroot(v, u);
        }
    }
}

void run_case() {
	cin >> n;
	FOR(i, 1, n) {
		adj[i].clear();
		sz[i] = 0;
		memset(dp[i], 0, sizeof dp[i]);	
	}
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n - 1) {
		int u, v; 
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 1);
	dfs2(1, 1);

	FOR(i, 1, n) cout << ans[i] << " \n"[i == n];
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
