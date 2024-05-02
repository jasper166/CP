#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 2e6 + 5;
const int MOD = 1e9 + 7;

int fac[N + 5], inv[N + 5];

ll bPow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

void prepare() {
    fac[0] = 1;
    for (int i = 1; i < N; ++i) 
        fac[i] = (1LL * fac[i - 1] * i) % MOD;
    
    inv[N - 1] = bPow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; --i)
        inv[i] = (1LL * inv[i + 1] * (i + 1)) % MOD;
}

int C(int n, int k) {
    if (n < k) return 0;
    return ((1LL * fac[n] * inv[n - k]) % MOD * inv[k]) % MOD;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    prepare();
    int k; cin >> k;
    string s; cin >> s;

    int S = s.size();
    int n = k + S;
    int Z = 26;

    debug(n);
    ll ans = bPow(Z, n);
    // Fixing prefix
    for (int i = 0; i < S; ++i) {
        ll exc = (1LL * bPow((Z - 1), n - i) * C(n, i)) % MOD;
        ans = (ans - exc + MOD) % MOD; 
    }
    cout << ans << "\n";
}
 