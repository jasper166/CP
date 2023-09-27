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
const int LG = 16;

int dep[N];
int dp[N];
vector <int> adj[N];
int up[LG][N];
int n, q;

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        up[0][v] = u;
        dep[v] = dep[u] + 1;
        for (int i = 1; i < LG; ++i)
            up[i][v] = up[i - 1][up[i - 1][v]];
        dfs(v, u);
    }
}

void re_dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        re_dfs(v, u);
        dp[u] += dp[v];
    }
}

int getLCA(int u, int v) {
    // int ans;
    if (dep[u] != dep[v]) {
        if (dep[u] < dep[v]) swap(u, v);
        int k = dep[u] - dep[v];
        for (int i = 0; (1 << i) <= k; ++i)
            if (k & (1 << i))
                u = up[i][u];
    }
    if (u != v) {
        for (int i = LG - 1; i >= 0; --i) {
            if (up[i][u] != up[i][v]) {
                u = up[i][u];
                v = up[i][v];
            }
        }
        u = up[0][u];
    }
    return u;
}

void run_case() {
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);

    while (q--) {
        int u, v;
        cin >> u >> v;
        int x = getLCA(u, v);
        // debug(x, u, v);
        dp[u]++; dp[v]++;
        dp[x]--; dp[up[0][x]]--;
    }
    re_dfs(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]);
    cout << ans << "\n";
}

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    setIO("maxflow");
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
