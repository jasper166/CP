/**    
* LANG: C++ 
* author: atom 
* created: 24.06.2022 23:07:58
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define end cout << '\n'
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e5 + 2;
constexpr int INF = 1e9;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

struct pii{
  int F, S;
  bool operator < (const pii & a){
    return F > a.F;
  }
};

int a[MAX][12], dp[MAX];
pii prefix[MAX];
int n, m, k;


int orz(){
  cin.tie(nullptr) -> sync_with_stdio(false);

  cin >> n >> m >> k;
  int div = k / m, rem = k % m;
  FOR(i, 1, n){
    FOR(j, 1, m){
      cin >> a[i][j];
      prefix[i].F += a[i][j];
      a[i][j] += a[i][j - 1];
    }
    prefix[i].S = i;
  }
  sort (prefix + 1, prefix + n + 1);
  dp[0] = 0;
  int ans = 0;
  FOR(i, 1, n) dp[i] += dp[i - 1] + prefix[i].F;
  FOR(i, 1, n){
    int pos = prefix[i].S;
    if (i > div) ans = max(ans, dp[div] + a[pos][rem]);
    else ans = max(ans, dp[div + 1] - prefix[i].F + a[pos][rem]); 
  }
  if (m * n == k) ans = dp[n];
  cout << ans << '\n';
}
/* problem link: 

*/
