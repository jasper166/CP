/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 16:04:59
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


int n, k;
vector <int> a;
vector <int> b;

void next_combi(){
    b = a;
    int i = k;
    while (i >= 1 && b[i] == n - k + i) --i;
    
    int res = (i == 0)? k : k - i + 1;
    cout << res << '\n';
}

int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    a.resize(k + 1);
    for (int i = 1; i <= k; ++i) cin >> a[i];

    next_combi();

}
