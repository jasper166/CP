/**    
* LANG: C++ 
* author: atom 
* created: 24.06.2022 23:07:58
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <ll, ll>
#define pll pair <ll, ll>
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)
#define end cout << '\n'
constexpr ll MOD = 1e9 + 7;
constexpr ll MAX = 1e5 + 2;
constexpr ll INF = 1e9;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

ll a[MAX][12];
ll dp[MAX];
pll prefix[MAX];
ll n, m, k;


int orz(){
  cin.tie(nullptr) -> sync_with_stdio(false);

  cin >> n >> m >> k;
  ll div = k / m, rem = k % m;
  FOR(i, 1, n){
    FOR(j, 1, m){
      cin >> a[i][j];
      prefix[i].F += a[i][j];
      a[i][j] += a[i][j - 1];
    }
    prefix[i].S = i;
  }
  sort (prefix + 1, prefix + n + 1, [&] (const pll &a, const pll &b){
	 if (a.F == b.F) return a.S < b.S; 	
	 return a.F > b.F;
  });
  // FOR(i, 1, n) cout << prefix[i].F << ' ' << prefix[i].S << '\n';
  dp[0] = 0;
  ll ans = 0;
  FOR(i, 1, n) dp[i] += dp[i - 1] + prefix[i].F;
  FOR(i, 1, n){
    ll pos = prefix[i].S;
    if (i > div) ans = max(ans, dp[div] + a[pos][rem]);
    else ans = max(ans, dp[div + 1] - prefix[i].F + a[pos][rem]); 
  }
  if (m * n == k) ans = dp[n];
  cout << ans << '\n';
}
/* problem link: 

*/
