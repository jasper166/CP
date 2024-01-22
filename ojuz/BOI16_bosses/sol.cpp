#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#define fi first
#define se second
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 5e3 + 5;

int n;
int dp[N], f[N];
vector <int> adj[N], gr[N];

void dfs(int u, int p) {
    int sum = 0;
    for (int v : adj[u]) {
        if (v ^ p) {
            dfs(v, u);
            sum += dp[v];
            f[u] += f[v];
        }
    }
    dp[u] = sum + 1;
    f[u] += dp[u];
}

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int k; cin >> k;
        for (int j = 1; j <= k; ++j) {
            int x; cin >> x;
            gr[x].push_back(i);
        }
    }


    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        int sz = 0;
        for (int x = 1; x <= n; ++x) {
            dp[x] = f[x] = 0;
            adj[x].clear();
        }

        // BFS for optimal tree 
        queue <int> q;
        vector <bool> vis(n + 5, 0);
        q.push(i);
        vis[i] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ++sz;
            for (int v : gr[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    adj[u].push_back(v);
                    q.push(v);
                }
            }
        }

        debug(sz);
        if (sz == n) {
            dfs(i, 0);
            ans = min(ans, f[i]);
        }
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


