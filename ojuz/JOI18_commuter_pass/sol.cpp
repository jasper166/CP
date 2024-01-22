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
const int N = 1e5 + 5;

int n, m;
int s[4];
vector <pair <int, int>> adj[N];
ll dis[N][4];

void dijkstra(int x) {
    for (int i = 1; i <= n; ++i) dis[i][x] = INF;
    using T = pair<ll, int>;
    priority_queue <T, vector <T>, greater <T>> q;
    dis[s[x]][x] = 0;
    q.push({0, s[x]});
    // debug(s[x]);
    while (!q.empty()) {
        auto [du, u] = q.top(); q.pop();
        if (du != dis[u][x]) continue;
        // debug(du, u);
        for (auto [w, v] : adj[u]) {
            if (dis[v][x] > dis[u][x] + w) {
                dis[v][x] = dis[u][x] + w;
                q.push({dis[v][x], v});
            }
        }
    }
}	

vector <int> dag[N];
ll dpU[N], dpV[N];
ll ans;
bool vis[N];
// dpU represents min dis(u, i) on path (s, i)
// dpV represents min dis(v, i) on path (s, i)
// ans = min(dpU() + dis(v, y), dpV() + dis(u, y))
void dfs(int x, int p) {
    debug(x);
    if (vis[x]) return;
    vis[x] = 1;
    for (int y : dag[x]) {
        if (y != p) {
            dfs(y, x);
            dpU[x] = min({dpU[x], dpU[y], dis[y][2]});
            dpV[x] = min({dpV[x], dpV[y], dis[y][3]});
        }
    }
    ans = min(ans, dpU[x] + dis[x][3]);
    ans = min(ans, dpV[x] + dis[x][2]);
}

void run_case() {
    cin >> n >> m;
    for (int i = 0; i <= 3; ++i) cin >> s[i];
    for (int i = 1; i <= m; ++i) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	adj[u].push_back({w, v});
    	adj[v].push_back({w, u});
    }

   	for (int i = 0; i <= 3; ++i)
        dijkstra(i);
    
    // 
    for (int x = 1; x <= n; ++x) {
        for (auto [w, y] : adj[x]) {
            if (dis[x][0] + w + dis[y][1] == dis[s[1]][0]) {
                dag[x].push_back(y);
            }
        }
    }
    // // taking route directly from u->v
    ans = dis[s[2]][3];
    debug(ans);
    fill(dpU, dpU + n + 5, INF);
    fill(dpV, dpV + n + 5, INF); 
    dfs(s[0], 0);
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
