#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

int bPow(int a, int b, int MOD) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (1LL * ans * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return (int) ans;
}


int a, b, c, MOD;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> a >> b >> c >> MOD;

    ll ans = bPow(a, b, MOD);
    ans = (ans * 1LL * bPow(c, MOD - 2, MOD)) % MOD;
    cout << ans << "\n";
}

