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

int orz(){

   	int t;
    scanf("%d", &t);
    while (t--){
        int x;
        scanf("%d", &x);
        i64 sum = 0;
        for (int i = 1; i <= x; i++)
            if (i & 1) sum += 1ll * i * i;  
        printf("%lld\n", sum);    
    }
 
}