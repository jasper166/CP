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
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, t;
int k, a[N];
vector <pii> adj[N];
int dp[N];
// minimum travel times to reach i
set <int> rc[N];
// rc[x]: storing time moments a(i) leading to record x
// for each (u, v) of record x, find min i such dp(u) < i and a(i) = x -> update dp(v) = min(dp(v), i)
void run_case() {
    cin >> n >> t;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        dp[i] = INF;
        rc[i].clear();
    }

    for (int i = 1; i <= t; ++i) {
        int m; cin >> m;
        for (int j = 1; j <= m; ++j) {
            int u, v; cin >> u >> v;
            // debug(u, v);
            adj[u].push_back({i, v});
            adj[v].push_back({i, u});
        }
    }
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
        rc[a[i]].insert(i);  
    }

    priority_queue <pii, vector <pii>, greater <pii>> q;
    dp[1] = 0; 
    q.push({dp[1], 1});

    while (!q.empty()) {
        auto [du, u] = q.top(); q.pop();
        // debug(du, u);
        if (du > dp[u]) continue;

        for (auto [x, v] : adj[u]) {
            auto it = rc[x].upper_bound(dp[u]);
            if (it != rc[x].end()) {
                // debug(*it);
                int val = *it;
                if (dp[v] > val) {
                    dp[v] = val;
                    q.push({dp[v], v});
                }
            }
        }
    }

    // for (int i = 1; i <= n; ++i) {
    //     debug(dp[i]);
    // }
    int ans = (dp[n] <= k? dp[n] : -1);
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


