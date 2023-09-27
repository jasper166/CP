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

    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, q;
    n = rand() % 10 + 1;
    i64 a[n + 1];
    i64 sum = 0;    
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
            sum += a[i];
        }
    i64 i, x, j = -1;
    // cout << sum << '\n';
    while (q--){
    	int t;
        cin >> t;
        if (t == 1){
            cin >> i >> x;
            if (j == -1) sum = sum + x - a[i];
            else sum = sum - j + x;
        }
        else {
            cin >> x;
            j = x;
            sum = n * x;
        }
        cout << sum << '\n';
    }
    
}

