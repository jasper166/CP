/**    
 *  @Author: Hiu 
 *  @Handle: at0miccat
**/
#include "bits/stdc++.h"
using namespace std;
using i64 = long long;

#define orz main
#define fi first
#define se second
#define pii pair <int, int>
#define pb push_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e5 + 2;

// #ifdef LOCAL
// #include "myLib.h"
// #else
// #define debug(...) 42
// #endif

int c, n;
int orz(){

    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;
    int w[n + 1], v[n + 1];
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) cin >> v[i];
    
    int dp[n + 1][c + 1];
    memset(dp, 0, sizeof(dp));  
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= c; j++){
            
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[n][c] << '\n';

}