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
const int N = 5e4 + 5;
const int K = 5e2 + 5;

vector <int> adj[N];
int dp[N][K];
int n, k;
ll ans = 0;
void dfs(int u, int p) {
	dp[u][0] = 1;
	for (int v : adj[u]) {
		if (v ^ p) {
			dfs(v, u);
			for (int i = 0; i + 1 <= k; ++i)
				ans += 1ll * dp[v][i] * dp[u][k - i - 1];
			for (int i = 1; i <= k; ++i)
				dp[u][i] += dp[v][i - 1];
		}
	}
}

void run_case() {
	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
