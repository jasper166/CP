/**    
 *  @Author: Hiu 
 *  @Handle: at0miccat
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

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


int orz(){

    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        char a[n][m];
        int k = m - 1;
        for (int i = 0; i <= n - 1; ++i)
            for (int j = 0; j <= m - 1; ++j){
                cin >> a[i][j];
                if (a[i][j] == 'R')
                    k = min(k, j);
            }
        bool flag = true;
        for (int i = 0; i <= n - 1; ++i){
            for (int j = 0; j <= m - 1; ++j){
                if (a[i][j] == 'R'){
                    if (j - k == 0) cout << "YES\n";
                    else cout << "NO\n";
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }    
    }    
    
}