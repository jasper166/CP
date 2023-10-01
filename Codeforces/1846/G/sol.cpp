#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using pii = pair < int, int >;

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

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;

array <int, 3> med[MAX];
int n, m;
int sym;
bitset <10> s;
int dp[1 << 10];
// min days to get to msk state by using some meds from 1 to i
void run_case() {
    cin >> n >> m >> s;
    sym = (int) (s.to_ulong());
    for (int i = 1; i <= m; ++i) {
        cin >> med[i][0];
        cin >> s; med[i][1] = (int) (s.to_ulong());
        cin >> s; med[i][2] = (int) (s.to_ulong());
        // debug(med[i][0], med[i][1], med[i][2]);
    }


    priority_queue <pii, vector <pii>, greater <pii>> q; 
    fill(dp, dp + (1 << n), INF);
    // debug(dp[sym]);
    dp[sym] = 0;
    q.push({0, sym});

    while (!q.empty()) {
        auto [du, u] = q.top(); q.pop();
        if (du != dp[u]) continue;
        // debug(du, u);
        for (int i = 1; i <= m; ++i) {
            auto [dv, rmv, add] = med[i];
            int nxt = u & (((1 << n) - 1) ^ rmv);
            nxt |= add;
            if (dp[nxt] > dp[u] + dv) {
                dp[nxt] = dp[u] + dv;
                q.push({dp[nxt], nxt}); 
            }
        }
    }
    if (dp[0] == INF) dp[0] = -1;
    cout << dp[0] << "\n"; 
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


