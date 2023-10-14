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
const int N = 2e6 + 5;
const int LG = 21;

int n;
int a[N];
pii dp[1 << LG];
void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        int x = a[i];
        dp[x].se = dp[x].fi;
        dp[x].fi = i;
    }

    for (int i = 0; i < LG; ++i) {
        for (int mask = (1 << LG) - 1; mask >= 0; --mask) {
            if (mask & (1 << i)) {
                int sub_mask = mask ^ (1 << i);
                if (dp[mask].fi > dp[sub_mask].fi) {
                    dp[sub_mask].se = max(dp[sub_mask].fi, dp[mask].se);
                    dp[sub_mask].fi = dp[mask].fi;
                }
                else {
                    dp[sub_mask].se = max(dp[sub_mask].se, dp[mask].fi);
                }
            }
        }
    }

    // for (int i = 0; i <= 4; ++i) {
    //     debug(dp[i]);
    // }
    //I.E: a(j) & a(k) = c
    int ans = 0;
    for (int i = 1; i <= n - 2; ++i) {
        int c = 0;
        for (int b = LG - 1; b >= 0; --b) {
            if (a[i] & (1 << b)) continue;
            if (dp[c | (1 << b)].se > i)
                c |= (1 << b);
        }
        ans = max(ans, a[i] | c);
    }
    cout << ans << "\n";
}

/*
    For fixed a(i), can we find maximum C = a(j) & a(k) (i < j < k)?

    dp(x) = (j, k) : two largest position such a(i) takes x as submask
    dp(x) = (j, k), a(j) & a(k) = X > x(x is a submask of X)
    -> any submask y of x can take (j, k) as it maximum pair
    
    Loop through each bit (as 2^b > 2^0 + ...  2^(b - 1))
    if a(i) & 2^(b) = 1 -> final answer always includes this bit -> skip
    check if (c | (2 ^ b)).se (some a(j)) > i
        if true, we can add this bit


*/

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


