#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MAX = 52;

int deg[MAX];
int a[MAX][MAX];
bool vis[MAX];
vector <int> adj[MAX];
int n;
vector <int> euler;
int cnt;
void dfs(int u) {
  // cout << u << "\n";
  vis[u] = 1;
  for (auto v : adj[u]) {
    if (vis[v])
      continue;
    dfs(v);
  }
}

void run() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j]) {
        deg[j]++;
        adj[i].push_back(j);
      }
    }
  }
  // lien thong yeu
  dfs(1);
  bool bad = 0;
  for (int u = 1; u <= n; u++) {
    if (!vis[u])
      bad = 1;
  }
  int st = -1, en = -1;
  for (int i = 1; i <= n; i++) {
      if (deg[i] == adj[i].size() + 1)
        en = i;
      if (deg[i]+ 1 == adj[i].size())
        st = i;
  }
  if (st == -1 || en == -1 || bad) {
    cout << "Khong co duong di Euler\n";
    return;
  }

  for (int i = 1; i <= n; i++) 
    if (adj[i].size()) sort(adj[i].begin(), adj[i].end(), greater <int> ());
  vector <int> curPath;
  curPath.push_back(st);
  while (!curPath.empty()) {
    int u = curPath.back();
    // cout << u << "\n";
    if (!adj[u].empty()) {
      int v = adj[u].back();
      curPath.push_back(v);
      adj[u].pop_back();
    }
    else {
      euler.push_back(u);
      curPath.pop_back();
    }
  }
  reverse(euler.begin(), euler.end());
  for (int i = 0; i < euler.size() - 1; i++) cout << euler[i] << " ";
  cout << euler.back() << "\n";
}

signed main () {
  cin.tie(0) -> sync_with_stdio(0);

  int t = 1; 
  // cin >> t;
  while (t--) {
    
    run();
  }
}
