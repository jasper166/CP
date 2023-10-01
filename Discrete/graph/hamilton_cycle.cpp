#include "bits/stdc++.h"
#include <algorithm>
using namespace std;
using ll = long long;

const int MAX = 52;

int a[MAX][MAX];
vector <int> adj[MAX];
int n, s;
bool vis[MAX];
void run() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  cin >> s;
  vector <int> perm;
  for (int i = 1; i <= n; i++) perm.push_back(i);

  int cnt = 0;
  do {

      int u = perm[0];
      if (!a[s][u] || perm.back() != s) continue;
      bool bad = 0;
      for (int i = 0; i < n; i++) { 
        if (i < n - 1 && !a[perm[i]][perm[i + 1]]) {
          bad = 1;
          break;
        }
        vis[perm[i]] = 1;
      }
      if (bad) continue;
      cnt++;
      cout << s;
      for (int i : perm) cout << " " << i;
      cout << "\n";
  } while (next_permutation(perm.begin(), perm.end()));
  cout << cnt << "\n";
}

signed main () {
  cin.tie(0) -> sync_with_stdio(0);

  int t = 1; 
  // cin >> t;
  while (t--) {
    
    run();
  }
}
