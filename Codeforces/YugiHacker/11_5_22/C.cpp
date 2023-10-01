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
#define pll pair <long long, long long>
#define pb push_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 3e5 + 2;

// #ifdef LOCAL
// #include "myLib.h"
// #else
// #define debug(...) 42
// #endif

int n;
int a[MAX];
int d[10000002];
int orz(){

   	scanf("%d\n", &n);
    for (int i = 0; i <= n - 1; i++){
        scanf("%d", &a[i]);
    }
    int k = *max_element(a, a + n);
    int frq[k + 1];
    for (int i = 0; i <= k; i++)
        frq[i] = 1;
    for (int i = 2; i <= k; i++){
        if (frq[i] == 1){
            for (int j = i; j <= k; j += i) frq[j] *= i;
        }
    }
    int cnt = 0;
    for (int i = 0; i <= n - 1; ++i){
        cnt += d[frq[a[i]]]++;    
    }
    printf("%d\n", cnt);
}