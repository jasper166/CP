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
const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 5e3 + 5;

vector <int> adj[N];
int n, b;
int c[N], d[N], sz[N];
ll dp[N][N][2];
// dp(n, cnt, 0/1): minimum money at subtree of i to buy j items, 0\1: can not use\ can use discount
void dfs(int u, int p) {
    for (int x = 0; x <= n; ++x)
        dp[u][x][0] = dp[u][x][1] = INF;

    // base case (leaf)
    dp[u][0][0] = 0;
    dp[u][1][0] = c[u];
    dp[u][1][1] = c[u] - d[u];
    sz[u] = 1;

    for (int v : adj[u]) {
        if (v ^ p) {
            dfs(v, u);
            for (int x = sz[u]; x >= 0; --x) {
                for (int y = sz[v]; y >= 0; --y) {
                    // not take coupon
                    if (x + y <= n) 
                        dp[u][x + y][0] = min(dp[u][x + y][0], dp[u][x][0] + dp[v][y][0]);
                    // if take
                    if (x + y <= n) 
                        dp[u][x + y][1] = min(dp[u][x + y][1], dp[u][x][1] + min(dp[v][y][0], dp[v][y][1]));
                }
            }
            // make sure not to choose an item multiple times
            sz[u] += sz[v];
        }
    }
}

void run_case() {
    cin >> n >> b;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i] >> d[i];
        if (i >= 2) {
            int x; cin >> x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
    }
    dfs(1, 0);
    int ans = 0;
    for (int x = 0; x <= n; ++x)
        if (min(dp[1][x][0], dp[1][x][1]) <= b)
            ans = max(ans, x);
    cout << ans << "\n";
}

/*
    Suppose we're buying this item then we had to buy x(i) before + (xi < i) -> can be solved on a rooted tree

*/

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


