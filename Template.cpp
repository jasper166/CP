#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 5e5 + 5;
int a[N];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int n, k, d;
    cin >> n >> k >> d;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    sort(a + 1, a + 1 + n);    
    vector <bool> dp(n + 1, false);
    dp[0] = true;

    int j = 1;
    for (int i = 0; i <= n; ++i) {
        if (dp[i] == true) {
            j = max(j, i + k);
            while (j <= n && a[j] - a[i + 1] <= d) {
                dp[j] = true;
                debug(i, j);
                ++j;
            }
        }
    }

    cout << (dp[n]? "YES\n" : "NO\n");
    
    return 0;
}

