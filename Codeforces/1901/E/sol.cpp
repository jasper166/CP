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
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 5e5 + 5;

ll dp[4][N];
// dp(k, u) : max sum of subtree u with deg(u) = k
int n;
int a[N];
vector <int> adj[N];
ll ans;

void dfs(int u, int p) {
    for (int i = 0; i <= 3; ++i)
        dp[i][u] = -INF;

    vector <ll> dps;
    for (int v : adj[u]) {
        if (v ^ p) {
            dfs(v, u);
            ll x = max({dp[0][v], dp[1][v] - a[v], dp[2][v] + a[v], dp[3][v]});
            dps.push_back(x);
        }
    }

    sort(dps.begin(), dps.end(), greater <ll> ());
    int sz = dps.size();
    // k = 0: leaf node -> dp(u) = a(u);
    dp[0][u] = a[u];    
    if (sz >= 1) {
        // k = 1? (v is the only child of u)
        dp[1][u] = dps[0] + a[u]; 
        if (sz >= 2) {
            // k = 2? remove u -> dp(u) = dp(v1) + dp(v2);
            dp[2][u] = dps[0] + dps[1];
            if (sz >= 3) {
                dp[3][u] = dps[0] + dps[1] + dps[2] + a[2];
                for (int j = 3; j < sz; ++j)
                    dp[3][u] += max(0ll, dps[j]);
            }
        }
    }

    for (int i = 0; i <= 3; ++i)
        ans = max(ans, dp[i][u]);

}

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) adj[i].clear();
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans = -INF;
    dfs(1, 0);
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


