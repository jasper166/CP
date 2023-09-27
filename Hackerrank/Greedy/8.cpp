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
    for (auto &i : a){
        int x, y, z;
        cin >> x >> y >> z;
        i.F = y;
        i.S = z;
    }
    sort (all(a), [&] (const pii &a, const pii &b) { return a.S > b.S; });
    vector <bool> used(n, true);
    int ans = 0;

    for (int i = 0; i <= n - 1; i++){
        for (int j = a[i].F - 1; j >= 0; j--){
            if (used[j]){
                ans += a[i].S;
                used[j] = false; 
                break;
            }
        }
    }
    cout << ans << '\n';
         
}
