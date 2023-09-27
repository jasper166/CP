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
    ll ans = 0;
    priority_queue <ll, vector <ll>, greater <ll>> pq;
    for (int i = 0; i < n; ++i){
        ll x;
        cin >> x;
        pq.push(x);
    }
    while (pq.size() != 1){
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        ans += (a + b);
        pq.push(a + b);
    }

    cout << ans << '\n';
         
}
