#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
ll f[92], g[92];
map <pair<int, ll>, int> dp;
int func(int n, ll k) {
  if (k > f[n]) return 0;
  if (n <= 2) return g[n];
  if (dp[{n, k}])
    return dp[{n, k}];
  int res = 0;
  if (k <= f[n - 2]) {
    res += func(n - 2, k) % MOD;
  }  
  else {
    res += g[n - 2] % MOD;
    res += func(n - 1, k - f[n - 2]) % MOD;
  }
  return dp[{n, k}] = res;
}

void run() {
  int n, k;
  cin >> n >> k;
  // cout << f[n] << "\n";
  cout << func(n, k) << "\n";
}

signed main () {
  cin.tie(0) -> sync_with_stdio(0);

  f[1] = f[2] = 1LL;
  g[1] = 0; g[2] = 1LL;
  for (int i = 3; i <= 90; i++) {
    f[i] = f[i - 1] + f[i - 2];
    g[i] = g[i - 1] + g[i - 2];
  }
  // cout << f[90] << "\n"; 
  int t; cin >> t;
  while (t--) {
    run();
  }
}
