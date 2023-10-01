#include <bits/stdc++.h>
using namespace std;
// #define int long long
using ll = long long;
using ii = pair <int, int>;

const int MOD = 1e9 + 7;
const int LIM = 4444444444;
const int MAX = 1e3 + 2;

// B24
int n, m;
vector <int> adj[MAX];
int tplt;
bool vis[MAX];

void dfs(int u) {
    // cout << u << "\n";
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v])
            dfs(v);
}


void dfs2(int u, int p) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v] && v != p) {
            cout << "0\n";
            return;
        }
        else if (!vis[v])
            dfs2(v, u);
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;
    if (m != n - 1) {
        cout << "0\n";
        return 0;
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    tplt = 0;
    for (int u = 1; u <= n; u++) {
        if (!vis[u]) {
            // cout << u << "\n";
            ++tplt;
            dfs(u);
        }
    }

    // cout << tplt << "\n";
    if (tplt != 1) {
        cout << "0\n";
        return 0;
    }
    
    memset(vis, 0, sizeof vis);
    dfs2(1, 0);
    cout << "1\n";
    
    return 0;
}