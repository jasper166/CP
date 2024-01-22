#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 35005;
int n, k;
int a[N];
int cnt[N];
int ret, l, r;
int dp[52][N];

int cost(int ql, int qr) {
    // (l, r) -> (l - 1, r)
    while (l > ql) {
        --l;
        cnt[a[l]]++;
        if (cnt[a[l]] == 1) ++ret;
    }
    // (l, r) -> (l, r + 1);
    while (r < qr) {
        ++r;
        cnt[a[r]]++;
        if (cnt[a[r]] == 1) ++ret;
    }
    // (l, r) -> (l, r - 1);
    while (r > qr) {
        cnt[a[r]]--;
        if (cnt[a[r]] == 0) --ret;
        --r;
    }
    // (l, r) -> (l + 1, r);
    while (l < ql) {
        cnt[a[l]]--;
        if (cnt[a[l]] == 0) --ret;
        ++l;
    }
    return ret;
}

void dnc(int x, int lb, int rb, int opt_l, int opt_r) {
    if (lb > rb) return;
    int m = (lb + rb) / 2;

    int p = -1;
    for (int i = opt_l; i <= min(m, opt_r); ++i) {
        int cur = dp[x - 1][i] + cost(i + 1, m);
        if (cur > dp[x][m]) {
            dp[x][m] = cur;
            p = i;
        }
    }
    dnc(x, lb, m - 1, opt_l, p);
    dnc(x, m + 1, rb, p, opt_r);
}


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        cnt[a[i]]++;
        if (cnt[a[i]] == 1) ++ret;
        dp[1][i] = ret;
    }

    ret = 0, l = 1, r = 0;
    memset(cnt, 0, sizeof cnt);
    for (int x = 2; x <= k; ++x)
        dnc(x, 1, n, 1, n);

    cout << dp[k][n] << "\n";
}
