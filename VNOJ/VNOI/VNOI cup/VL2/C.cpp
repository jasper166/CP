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
#define pii pair <int, int>
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define end cout << '\n'
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int t, n;
int a[MAX];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> t;
	while (t--){
		cin >> n;
		FOR(i, 1, n) cin >> a[i];

      int i = 0, cnt = 0;
      if (a[i]) cnt++;
      while(i <= n - 1){
          if(a[i] == 0 && a[i + 1]){
              cnt++;
              i++;
          }
          else i++;
      }
      if (cnt >= 2) cnt = 2;
      cout << cnt << '\n';
	}		 
}
/* problem link: 
	https://codeforces.com/contest/1696/problem/B
*/
