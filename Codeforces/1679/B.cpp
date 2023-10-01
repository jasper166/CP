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

    ll n, q;
    cin >> n >> q;
    ll a[n + 1];
    ll sum = 0;    
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
            sum += a[i];
        }
    ll i, x, j = 0;
    map <int, int> mp;

    // cout << sum << '\n';
    while (q--){
        int t;
        cin >> t;
        if (t == 1){
            cin >> i >> x;
            if(!mp.count(i)) mp[i] = j; 
            sum += mp[i] + x;
            mp[i] = x; 
        }   
        else {
            cin >> x;
            j = x;
            mp.clear();
            sum = 1ll * n * x;
        }
        cout << sum << '\n';
    }
    
}

