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
    vector <pii> a(n);
    for (pii &i : a) cin >> i.F >> i.S;
    sort (all(a), [&] (const pii &a, const pii &b) { return a.S < b.S ;});
    int ans = 1, pre = a[0].S;
    for (int i = 1; i <= n - 1; i++){
        if (a[i].F > pre){
            ans++;
            pre = a[i].S;
        }
    }
    cout << ans << '\n';
         
}
