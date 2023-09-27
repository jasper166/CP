#include <bits/stdc++.h>
using namespace std;
// #define int long long
using ll = long long;
using ii = pair <int, int>;

const int MOD = 1e9 + 7;
const int LIM = 4444444444;
const int MAX = 1e3 + 2;

// B26
int n, m;
vector <int> adj[MAX];
bool vis[MAX];
vector <int> tplt;

void dfs(int u) {
	vis[u] = 1;
	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;
    
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int u = 1; u <= n; u++) {
		if (!vis[u]) {
			tplt.push_back(u);
			dfs(u);
		}
	}

	int x = (int) tplt.size();
	cout << x - 1 << "\n";
	for (int i = 0; i < x - 1; i++)
		cout << tplt[i] << " " << tplt[i + 1] << "\n";
	
    return 0;
}
