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
constexpr int MAX = 1e6 + 2;

// #ifdef LOCAL
// #include "myLib.h"
// #else
// #define debug(...) 42
// #endif

int x[] = {-1, -1, 0};
int y[] = {0, -1, -1};

int orz(){

    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    char a[n][n];
    int dp[n][n];
    for (int i = 0; i <= n - 1; ++i)
        for (int j = 0; j <= n - 1; ++j){
            cin >> a[i][j];
        }
   
    memset(dp, 0, sizeof(dp));
    dp[0][0] = (a[0][0] == '.')? 1 : 0;
    

    for (int i = 0; i <= n - 1; ++i){
        for (int j = 0; j <= n - 1; ++j){
            if (a[i][j] == '*') dp[i][j] = 0;
            else {
                if (i >= 1 && i <= n - 1) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j >= 1 && j <= n - 1) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
     // for (int i = 0; i <= n - 1; ++i){
     //    for (int j = 0; j <= m - 1; ++j)
     //        cout << dp[i][j] << ' ';
     //    cout << '\n';
     //    }

    cout << dp[n - 1][n - 1] << '\n';
}