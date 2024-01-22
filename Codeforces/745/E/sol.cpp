#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi firsts
#define se second
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 16;
const int SUM = 280;

int n;
char c[N];
int r[N], b[N];
int dp[1 << N][SUM];
// dp(mask, curR) : Maximum Blue tokens we can obtain at mask state and current curR Red tokens
void run_case() {
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> c[i] >> r[i] >> b[i];

    int totR = 0, totB = 0;
    // total Red and Blue tokens
    for (int i = 0; i < n; ++i) {
        totR += r[i];
        totB += b[i];
    }

    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int cntR = 0, cntB = 0;
        //  current Red cards, Blue cards at this mask
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i))
                (c[i] == 'R')? ++cntR : ++cntB;
        }

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) continue;
            int nxt_mask = mask | (1 << i);
            // Buying this card
            for (int curR = 0; curR < SUM; ++curR) {
                if (dp[mask][curR] != -1) {
                    /*
                        int need = max({r[i] - cntR - curR, b[i] - cntB - curB, 0});
                        -> remR = curR + need - max(r[i] - cntR, 0);
                        -> remB = curB + need - max(b[i] - cntB, 0);
                    */
                    int curB = dp[mask][curR];
                    // - cntR : if (ri > cntR) -> 
                    int nxt_curR = curR + min(r[i], cntR);
                    int nxt_curB = curB + min(b[i], cntB);
                    //
                    dp[nxt_mask][nxt_curR] = max(dp[nxt_mask][nxt_curR], nxt_curB);
                }
            }
        }
    }

    int ans = INF;
    int full = (1 << n) - 1;
    for (int curR = 0; curR < SUM; ++curR) {
        if (dp[full][curR] != -1) {
            int curB = dp[full][curR];
            ans = min(ans, max(totR - curR, totB - curB));
        }
    }
    // adding n as we need n moves to buy all n cards
    ans += n;
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


