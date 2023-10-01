#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MAX = 52;

int deg[MAX];
int a[MAX][MAX];
bool vis[MAX];
int n, cnt;
vector <int> euler;

void dfs(int u) {
  euler.push_back(u);
  for (int v = 1; v <= n; v++) {
    if (a[u][v]) {
        a[u][v] = 0;
        a[v][u] = 0;
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
        deg[i]++;
        // cout << i << " " << j << "\n";
      }
    }
  }
  int st = -1, en = -1;
  int v = 0;
  for (int i = 1; i <= n; i++)
    if (deg[i] & 1) {
      v++;
      if (st == -1) st = i;
      else en = i;
    }
  // cout << st << " " << en << "\n";
  if (v > 2) {
    cout << "Khong co duong di Euler\n";
    return;
  }
  // if (st != -1) {
  //   a[st][en]++;
  //   a[en][st]++;
  // }

  dfs(st);
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
