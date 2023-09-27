/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 09:56:51
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

int n, x;
vector <int> a;

int find(){
    int l = 0, r = n - 1, ans = -1;
    while (l <= r){
        int m = (l + r ) >> 1;
        if (a[m] <= x){
            ans = a[m];
            l = m + 1;
        }
        else r = m - 1;
    }
    return ans;
}


int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    a.resize(n);
    for (int &i : a) cin >> i;
    cout << find() << '\n';
}
