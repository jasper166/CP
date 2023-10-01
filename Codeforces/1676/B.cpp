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
   	int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
        int k = 0, j = MOD;
        for (int i = 0; i <= n - 1; i++){
            cin >> a[i];
            k += a[i];
            j = min(j, a[i]);
        }
        cout << k - n * j << '\n';
    }
   	
 
}