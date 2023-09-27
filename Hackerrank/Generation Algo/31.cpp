/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 20:35:43
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif


int n, s;
int ans = -1e9;


int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;    
    int w[n], v[n];
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) cin >> v[i];
  

   int dp[1002][1002];
	memset(dp, 0, sizeof(dp));
   for (int i = 1; i <= n; i++){
   		for (int j = 1; j <= s; j++){
   			if (j >= w[i]){
   				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
   			}
   			else dp[i][j] = dp[i - 1][j];
   		}
   }
   // for (int i = 0; i <= n; i++){
   // 		for (int j = 0; j <= s; j++){
   // 			cout << dp[i][j] << ' ';   			
   // 		}
   // 		cout << '\n';
   // 	}

    cout << dp[n][s] << '\n';     
}
