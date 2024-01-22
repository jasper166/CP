#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e6;
// 0 -> 999999 (1e6)
int n, a[N + 5];
int g[N + 5];
int pw2[N + 5];
struct Data {
    int s0, s1, s2;
    // size of set, sum, sum square
    Data(int _s0 = 0, int _s1 = 0, int _s2 = 0) : s0(_s0), s1(_s1), s2(_s2) {};
} dp[N + 5];

Data merge(Data x, Data y) {
    return 
    {
        ((1ll * x.s0 + 1ll * y.s0)) % MOD, 
        ((1ll * x.s1 * pw2[y.s0]) % MOD + (1ll * y.s1 * pw2[x.s0]) % MOD) % MOD,
        ((1ll * x.s2 * pw2[y.s0]) % MOD + (2ll * x.s1 * y.s1) % MOD + (1ll * y.s2 * pw2[x.s0]) % MOD) % MOD
    };
}

void run_case() {
    cin >> n;

    pw2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        dp[x] = merge(dp[x], {1, x, (1ll * x * x) % MOD});
        pw2[i] = (2ll * pw2[i - 1]) % MOD; 
        // debug(dp[x].s0, dp[x].s1, dp[x].s2);
    }

    // // calculate f(S) >= x by SOS
    // // Take leftmost digit   
    for (int i = 1; i <= N; i *= 10) {
        for (int x = N - 1; x >= 0; --x) {
            int d = (x / i) % 10;
            if (d != 9 && x + i < N)
                dp[x] = merge(dp[x], dp[x + i]);
            // x is a submask of (x + i)
        }
    }

    // // Update g(i)
    for (int i = 0; i < N; ++i) 
        g[i] = dp[i].s2;

    // // Exclude f(S) > x by SOS
    for (int i = 1; i <= N; i *= 10) {
        for (int x = 0; x < N; ++x) {
            int d = (x / i) % 10;
            if (d != 9 && x + i < N)
                g[x] = (g[x] - g[x + i] + MOD) % MOD;
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ans ^= (1ll * i * g[i]);
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
