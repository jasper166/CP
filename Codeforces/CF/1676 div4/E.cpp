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

int a[MAX];

int orz(){

   	int t;
    scanf("%d", &t);
    while (t--){
        int n, q;
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1, greater <int> ());
        for (int i = 1; i <= n; i++){
            a[i] += a[i - 1];
        }
        for (; q; q--){
            int k;
            scanf("%d", &k);
            int res = lower_bound(a + 1, a + n + 1, k) - a;
            res = (res == n + 1)? -1 : res;
            printf("%d\n", res);
        }
    }
 
}