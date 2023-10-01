#include "bits/stdc++.h"
using namespace std;

const int MAX = 102;
const int INF = 1e9;
int d[MAX][MAX];
vector <int> adj[MAX];
bool vis[MAX][MAX];

int n, m, r;
vector <pair <int, int>> res;
int sx, sy, dx, dy;


void dfs (int x, int y) {
    // cout << x << " " << y << "\n";
    // cout << a << " " << b << "\n";
    // found
    if (x == dx && y == dy) {
        cout << "YES\n";
        for (auto pos : res) {
            cout << pos.first << " " << pos.second << "\n";
        }
        exit(0);
    }
    if (d[x][y] <= r)
        return;
    vis[x][y] = 1;

    for (int v : adj[x]) {
        if (!vis[v][y] && d[v][y] > r){
            res.emplace_back(v, y);
            dfs(v, y);
            res.pop_back();
        }
    }
    for (int v : adj[y]) {
        if (!vis[x][v] && d[x][v] > r) {
            res.emplace_back(x, v);
            dfs(x, v);
            res.pop_back();
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;
    // floyd
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
        adj[i].clear();
        for (int j = i + 1; j < n; j++) {
            d[i][j] = d[j][i] = INF;
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u][v] = d[v][u] = min({d[u][v], d[v][u], w});
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (d[i][k] < INF && d[k][j] < INF) 
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
    // cout << d[0][5] << "\n";
    cin >> sx >> sy >> dx >> dy >> r;
    res.emplace_back(sx, sy);
    dfs(sx, sy); 

    cout << "IMPOSSIBLE\n";
}
