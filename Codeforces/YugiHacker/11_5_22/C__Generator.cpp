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

    srand(time(0));
   	int t = rand() % 10 + 1;
    printf("%d\n", t);
    while (t--){
        int x = rand() % MAX + 1;
        printf("%d\n", x);    
    }
 
}