/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 01:21:11
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif


int n;
int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    ll a[n], b[n];
    for (ll &i : a) cin >> i;
    for (ll &i : b) cin >> i;    
    ll ans = 0;
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i <= n - 1; i++){
        ans += (a[i] * b[i])
    }
    cout << ans << '\n'; 
         
}
