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

int orz(){

    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(0));
    int n = rand() % 6 + 3;
    int c = rand() % 10 + 5;
    cout << n << ' ' << c << '\n';
    int w[n + 1], v[n + 1];
    for (int i = 1; i <= n; ++i){
        w[i] = rand() % 5 + 1;
        cout << w[i] << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n; ++i){
        v[i] = rand() % 20 + 10;
        cout << v[i] << ' ';
    }

}