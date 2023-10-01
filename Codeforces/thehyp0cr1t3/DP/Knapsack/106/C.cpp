/**    
* LANG: C++ 
* author: atom 
* created: {command:date +"%d.%m.%Y %H:%M:%S"}
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

struct buns{
	int a, b, c, d;
};

int n, m, x, y;
int dp[1005][15];
// dp(i, j) maximum profit if used i dough and at 1-->j index;
// knapsack in disguise
int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m >> x >> y;

	buns buns[m + 1];
	for (int i = 1; i <= m; i++) 
		cin >> buns[i].a >> buns[i].b >> buns[i].c >> buns[i].d;

	FOR(i, 0, n) dp[i][0] = 0;
	int ans = 0;
	FOR(i, 0, n){
		FOR(j, 1, m){
			int p = buns[j].a / buns[j].b;
			FOR(k, 0, p){
				if (i >= buns[j].c * k){
					dp[i][j] = max(dp[i][j], dp[i - buns[j].c * k][j - 1] + buns[j].d * k);
					ans = max(ans, dp[i][j]);
				}
			}
		}
		ans = max(ans, dp[i][m] + (n - i) / x * y);		
	}
	cout << ans << '\n';
		 
}
/* problem link: 
https://codeforces.com/problemset/problem/106/C
*/
