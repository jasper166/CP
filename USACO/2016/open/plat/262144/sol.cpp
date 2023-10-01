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
const int N = 262144 + 5;
const int VAL = 40;

int n;
int a[N];
int dp[VAL * 2][N];
// max ans = 40 + log2(n)
// dp(i, x) = j : index j such x is the maximum number can be formed, starting at i
void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];

    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; ++i)
        dp[a[i]][i] = i;

    int ans = 0;

    for (int x = 1; x < VAL * 2; ++x) {
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, a[i]);
            if (dp[x - 1][i] == -1) continue;
            // check the next index of a(j) = (x - 1)
            dp[x][i] = dp[x - 1][dp[x - 1][i] + 1];
            if (dp[x][i] != -1)
                ans = max(ans, x);
        }
    }
    cout << ans << "\n";
}

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    // setIO("262144");   
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


