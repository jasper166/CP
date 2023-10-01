#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MAX = 52;

int a[MAX][MAX];
bool vis[MAX];
int n, cnt;
vector <pair<int, int>> mst;

void bfs(int u) {
    queue <int> q;
    vis[u] = 1;
    q.push(u);
    while (!q.empty()) {
      auto x = q.front();
      q.pop();
      for (int y = 1; y <= n; y++) {
        if (!vis[y] && a[x][y]) {
          mst.push_back({x, y});
          vis[y] = 1;
          q.push(y);
        }
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
  bfs(u);
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
