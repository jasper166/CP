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
const int N = 4e2 + 5;
const int M = 3e5 + 5;

int dp[N][N][N];
int a[N];
int n, m;

int cal(int k, int l, int r, int x) {
    // debug(k, l, r, x);
    return max(dp[k - 1][l][x], a[r] - a[x]);
}
void run_case() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];

    for (int k = 1; k <= n; ++k) {
        for (int l = 1; l <= n; ++l) {
            for (int r = 1; r <= n; ++r) {
                dp[k][l][r] = INF;
            }
        }
    }

    for (int l = 1; l <= n; ++l)
        for (int r = l; r <= n; ++r)
            dp[0][l][r] = a[r] - a[l];

    for (int k = 1; k <= n; ++k) {
        for (int l = 1; l <= n; ++l) {
            int j = l;
            for (int r = 1; r <= n; ++r) {
                while (j + 1 <= r && cal(k, l, r, j) > cal(k, l, r, j + 1))
                    ++j;
                dp[k][l][r] = cal(k, l, r, j);
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; ++i) {
        int s, f, c, r;
        cin >> s >> f >> c >> r;
        debug(s, f, r, c);
        ans = max(ans, dp[r][s][f] * 1ll * c);
    }
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


