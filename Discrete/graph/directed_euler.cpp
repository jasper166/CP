#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MAX = 52;

int degI[MAX], degO[MAX];
int a[MAX][MAX];
bool vis[MAX];
int n, cnt;

void dfs(int u) {
  vis[u] = 1;
  cnt++;
  for (int v = 1; v <= n; v++) {
    if (a[u][v] || a[v][u]) {
      if (vis[v])
        continue;
        dfs(v);
    }
  }
}

void run() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j]) {
        degO[i]++; 
        degI[j]++;
      }
    }
  }

  dfs(1);
  if (cnt == n) {
    bool ok = 1;
    for (int u = 1; u <= n; u++)
      if (degI[u] != degO[u]) ok = 0;
    if (ok) {
      cout << "La do thi Euler\n";
      return;
    }
  }
  cout << "Khong phai do thi Euler" << "\n";
}

signed main () {
  cin.tie(0) -> sync_with_stdio(0);

  int t = 1; 
  // cin >> t;
  while (t--) {
    run();
  }
}
