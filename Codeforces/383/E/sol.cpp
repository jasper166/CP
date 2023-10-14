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
const int N = 1e6 + 5;
const int M = 24;

int n;
int dp[1 << M];

void run_case() {
    cin >> n;
    // for (int i = 1; i <= n; ++i) {
    //     string s; cin >> s;
    //     int sz = s.size();
    //     // take non-empty mask
    //     for (int it = 1; it < (1 << sz); ++it) {
    //         int mask = 0, c = 0;
    //         for (int j = 0; j < sz; ++j) {
    //             if (it & (1 << j)) {
    //                 ++c;
    //                 int x = s[j] - 'a';
    //                 mask |= (1 << x);
    //             }
    //         }
    //         dp[mask] += (c & 1)? 1 : -1;
    //     }
    // }

    // for (int i = 0; i < M; ++i) {
    //     for (int mask = 0; mask < (1 << M); ++mask)
    //         if (mask & (1 << i))
    //             dp[mask] += dp[mask ^ (1 << i)];
    // }

    // int ans = 0;
    // for (int mask = 0; mask < (1 << M); ++mask) {
    //     ans = (ans ^ (dp[mask] * dp[mask]));
    // }
    // cout << ans << "\n";
}

/*
    dp(mask) : numbers of string has at least a vowel 
    overlapped counting -> inclusion - exclusion

    OR

    dp(mask) : numbers of string has at least a consonant
    -> (n - dp(mask)) is answer
*/

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


