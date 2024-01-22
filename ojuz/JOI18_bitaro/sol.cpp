#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int BLOCK = 250;

vector <int> adj[N];
vector <pii> opt[N];
int n, m, q;
int dis[N], src[N];

void run_case() {
    cin >> n >> m >> q;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[v].push_back(u);
    }

    vector <int> best;
    for (int i = 1; i <= n; ++i) {
        vector <int> current;
        for (int u : adj[i]) {
            for (auto v : opt[u]) {
                if (src[v.second] == i) {
                    dis[v.second] = max(dis[v.second], v.first + 1);
                }
                else {
                    src[v.second] = i;
                    dis[v.second] = v.first + 1;
                    current.push_back(v.second);
                }
            }
        }

        opt[i].push_back({0, i});
        for (int j : current)
            opt[i].push_back({dis[j], j});

        sort(opt[i].begin(), opt[i].end(), greater <pii> ());
        while ((int) opt[i].size() > BLOCK) opt[i].pop_back();
    }

    vector <bool> busy(n + 2, 0);
    while (q--) {
        int x, c;
        cin >> x >> c;
        
        vector <int> b;
        for (int i = 1; i <= c; ++i) {
            int y; cin >> y;    
            b.push_back(y);
            busy[y] = 1;
        }

        int ans = -1;
        // Apply brute O(n) for x <= sqrt(n) times of total complexity nsqrt(n)
        if (c >= BLOCK) {
            vector <int> dp(n + 2, -INF);
            for (int i = 1; i <= x; ++i) {
                if (!busy[i]) dp[i] = 0;
                for (int j : adj[i])
                    dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
        else {    
            for (pii v : opt[x])
                if (!busy[v.second])
                    ans = max(ans, v.first);
        }
        cout << ans << "\n";    
        for (int i : b) busy[i] = 0;
    }   
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


