#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("sol.in", "r", stdin);
        freopen("sol.out_good", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector <int> a(n);

    for (int i = 0; i < n; ++i) cin >> a[i];

    int sum = accumulate(a.begin(), a.end(), 0);

    cout << sum << "\n"; 
    
    return 0;
}
