#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

ll dp[25][MAX];
int a[MAX];
int cnt[MAX];
int l = 1, r = 0;
int n, k;
ll ans = 0;
ll cost(int L, int R) {
    while (l > L) {
        --l;
        int x = a[l];
        ans += cnt[x]++;
    }
    while (r < R) {
        ++r;
        int x = a[r];
        ans += cnt[x]++;
    }
    while (l < L) {
        int x = a[l];
        ans -= --cnt[x];
        l++;
    }
    while (r > R) {
        int x = a[r];
        ans -= --cnt[x];
        r--;
    }
    return ans;
}

void solve(int x, int lb, int rb, int opt_l, int opt_r) {
    if (lb > rb) return;
    int m = (lb + rb) / 2;
    int split = -1;
    for (int i = opt_l; i <= min(m - 1, opt_r); ++i) {
        ll cur = dp[x - 1][i] + cost(i + 1, m);
        if (cur < dp[x][m]) {
            dp[x][m] = cur;
            split = i;
        }
    }
    solve(x, lb, m - 1, opt_l, split);
    solve(x, m + 1, rb, split, opt_r);
}
void run_case() {
    cin >> n >> k;
    for (int i = 0; i <= k; ++i) for (int j = 0; j <= n; ++j) dp[i][j] = LINF;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ans += cnt[a[i]]++;
        dp[1][i] = ans;
    }
    fill(cnt, cnt + MAX, 0);
    ans = 0;
    for (int i = 2; i <= k; ++i) {
        solve(i, 1, n, 1, n);
    }
    cout << dp[k][n] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
