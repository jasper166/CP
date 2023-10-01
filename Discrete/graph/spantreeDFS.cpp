#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MAX = 52;

int a[MAX][MAX];
bool vis[MAX];
int n, cnt;
vector <pair<int, int>> mst;

void dfs(int u) {
  vis[u] = 1;
  for (int v = 1; v <= n; v++) {
    if (a[u][v]) {
      if (vis[v])
        continue;
        mst.push_back({u, v});
        dfs(v);
    }
  }
}

void run() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  int u; cin >> u;
  dfs(u);
  if (mst.size() != n - 1){
    cout << "Do thi khong lien thong\n";
    return;
  }
  for (auto [u, v] : mst) cout << u << " " << v << "\n";

}

signed main () {
  cin.tie(0) -> sync_with_stdio(0);

  int t = 1; 
  // cin >> t;
  while (t--) {
    run();
  }
}
