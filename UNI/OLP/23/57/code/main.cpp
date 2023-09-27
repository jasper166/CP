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
const int MAX = 2e3 + 5;

int a[MAX][MAX];
int n, k;
ll prf[MAX][MAX];
ll dp[2][MAX];
ll cost(int l, int r) {
    if (l > r) return LINF;
    // f(A, B) - f(A, b - 1) - f(a - 1, B) + f(a - 1, b - 1);
    return prf[r][r] - prf[r][l - 1] - prf[l - 1][r] + prf[l - 1][l - 1];
}

void solve(int l, int r, int opt_l, int opt_r) {
    if (l > r) return;
    int m = (l + r) / 2;
    int split = -1;
    ll best = LINF;
    for (int i = opt_l; i <= min(opt_r, m - 1); ++i) {
        ll cur = dp[0][i] + cost(i + 1, m);
        if (cur < best) {
            split = i;
            best = cur;
        }
    }
    dp[1][m] = best;
    solve(l, m - 1, opt_l, split);
    solve(m + 1, r, split, opt_r);
}


void run_case() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            prf[i][j] = prf[i - 1][j] + prf[i][j - 1] - prf[i - 1][j - 1] + a[i][j];
        }
    }
//    debug(cost(1, 2));
    for (int i = 1; i <= n; ++i) dp[0][i] = cost(1, i);
    for (int i = 2; i <= k; ++i) {
        solve(1, n, 1, n);
        swap(dp[0], dp[1]);
    }
    cout << (dp[0][n] / 2) << "\n";
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
