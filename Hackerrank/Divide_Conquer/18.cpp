/**    
* LANG: C++ 
* author: atom 
* created: 09.06.2022 06:54:52
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


vector <ll> center (ll n){
    vector <ll> ans;
    ll a = 2;
    ans.pb(0);
    for (; n / 2 > 0; n >>= 1, a *= 2){
        ans.pb(a);
    }
    debug(ans.size());
    debug(ans);
    return ans;
}

ll inRange(vector <ll> a, ll k, ll n, ll pos){
    if (pos == 1) return n % 2;
    ll tmp = a[pos - 1];
    if (k == tmp) return n % 2;
    if (k < tmp) return inRange(a, k, n / 2, pos - 1);
    return inRange(a, k - tmp - 1, n / 2, pos - 1);
}


int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, r;
    cin >> n >> l >> r;
    vector <ll> a = center(n);
    ll ans = 0;
    for (ll i = l; i <= r; i++){
        ans += inRange(a, i, n, a.size());
    }
    cout << ans << '\n';
}
