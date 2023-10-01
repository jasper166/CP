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
const int MAX = 3e3 + 5;

int n, k;
string s;
int prf[MAX][MAX], suf[MAX][MAX];
int cnt[MAX];
int dp[MAX];

void run_case() {
    cin >> n >> k >> s;
    s = "@" + s;

    for (int i = 0; i <= n + 1; ++i) {
        dp[i] = -INF;
        cnt[i] = 0;
        for (int x = 0; x <= n + 1; ++x)
            prf[x][i] = suf[x][i] = 0;
    }

    for (int i = 1; i <= n; ++i) cnt[i] = cnt[i - 1] + (s[i] == '1');
    // prefix and suffix of longest 0s ending at i, use j operator
    
    for (int i = 1; i <= n; ++i) {
        int c = 0;
        for (int x = 0; x <= n; ++x) prf[x][i] = prf[x][i - 1];
        for (int j = i; j >= 1; --j) {
            if (s[j] == '0') ++c;
            prf[c][i] = max(prf[c][i], i - j + 1);
        }
    }

    for (int i = n; i >= 1; --i) {
        int c = 0;
        for (int x = 0; x <= n; ++x) suf[x][i] = suf[x][i + 1];
        for (int j = i; j <= n; ++j) {
            if (s[j] == '0') ++c;
            suf[c][i] = max(suf[c][i], j - i + 1);
        }
    }
   
    dp[0] = prf[k][n];
    for (int l = 1; l <= n; ++l) {
        for (int r = l; r <= n; ++r) {
            int x = cnt[r] - cnt[l - 1];
            int len = r - l + 1;
            if (k >= x)
                dp[len] = max(dp[len], max(prf[k - x][l - 1], suf[k - x][r + 1]));
        }
    }

    for (int a = 1; a <= n; ++a) {
        ll ans = -INF;
        for (int len = 0; len <= n; ++len)
            ans = max(ans, 1ll * a * len + dp[len]);
        cout << ans << " \n"[a == n];
    } 
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


