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

int func(string a, string b){
    int res = 0;
    for (int i = 0; i <= a.length() - 1; i++)
        res += abs(b[i] - a[i]);
    return res;
}



int orz(){

    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);
   	int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector <string> a(n);
        int res = MOD;
        for (int i = 0; i <= n - 1; i++) cin >> a[i];
        for (int i = 0; i <= n - 1; ++i)
            for (int j = 0; j <= i - 1; ++j)
                res = min(func(a[i], a[j]), res);
        cout << res << '\n';
    }
   	
 
}