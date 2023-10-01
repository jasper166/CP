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
constexpr int MAX = 1002;

// #ifdef LOCAL
// #include "myLib.h"
// #else
// #define debug(...) 42
// #endif

int n, m, a[MAX][MAX];
int orz(){

   	int t;
    scanf("%d", &t);
    while (t--){
        scanf("%d%d", &n, &m);
        i64 l[MAX], r[MAX], res = 0;
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        
        for (int i = 0; i <= n - 1; i++)
            for (int j = 0; j <= m - 1; j++){
                scanf("%d", &a[i][j]);
                int k = i + 500;
                l[j + k] += a[i][j];
                r[k - j] += a[i][j];

            }   
        for (int i = 0; i <= n - 1; i++)
            for (int j = 0; j <= m - 1; j++){
             int k = i + 500;
             i64 cur = r[k - j] + l[j + k] - a[k - 500][j];
             if (cur > res ) 
                res = cur;
            }
        printf("%lld\n", res);     
    } 
}