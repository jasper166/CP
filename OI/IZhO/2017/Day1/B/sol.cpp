#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int MOD = 1e9 + 7;
const int N = 1e3 + 5;

string s, t;
int n, m;

int dp[N][N];
// dp(i, j) : do dai cua xau con chung dai nhat tai vi tri i cua S, j cua T

int solve(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    if (i == 0 || j == 0) return 0;

    int ans = 0;
    if (s[i] == t[j]) ans = 1 + solve(i - 1, j - 1);
    else ans = max(solve(i - 1, j), solve(i, j - 1)); 

    return dp[i][j] = ans;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> s >> t;
    n = s.size();
    m = t.size();
    s = "@" + s;
    t = "@" + t;

    memset(dp, -1, sizeof dp);
    cout << solve(n, m) << "\n";
}

