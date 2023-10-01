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
const int N = 5e3 + 5;
const int VAL = 1e6 + 5;

int cnt[VAL * 3];
ll dp[N][N];
int n, q;
int a[N];

ll qry(int l, int r) {
    if (l > r) return 0;
    return dp[l][r];
}
void run_case() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += VAL;
    }

    // Fixed (i, j) : dp(i, j) : number of k such a(i) + a(j) + a(k) = 0 (i < j < k);
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int x = 3 * VAL - a[i] - a[j];
            if (0 <= x && x < VAL * 3)
                dp[i][j] = cnt[x];
            cnt[a[j]]++;
        }
        for (int j = i + 1; j <= n; ++j)
            cnt[a[j]]--;
    }
    // dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
    for (int i = n; i >= 1; --i)
        for (int j = i; j <= n; ++j)
            dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];

    while (--q) {
        int l, r;
        cin >> l >> r;
        cout << qry(l, r) << "\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


