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
const int MAX = 1e3 + 5;

ll f[MAX][MAX];
ll dis[MAX][MAX];
// from i move forward d;
int n, k;
int a[MAX];
int root = 0;

ll cost(int l, int r) {
    return dis[(l + root) % n][r - l];
}

void solve(int x, int l, int r, int optl, int optr) {
    if (l > r) return;
    int m = (l + r) / 2;
    int opt_m = -1;
    for (int i = optl; i <= optr; i++) {
        ll cur = f[x - 1][i] + cost(i + 1, m);
        if (cur < f[x][m]) {
            f[x][m] = cur;
            opt_m = i;
        }
    }
    solve(x, l, m - 1, optl, opt_m);
    solve(x, m + 1, r, opt_m, optr);
}


void run_case() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) {
        for (int d = 1; d <= n; ++d) {
            dis[i][d] = dis[i][d - 1] + a[(i + d) % n] * d;
        }
    }

    ll ans = LINF;
    for (; root < n; ++root) {
        for (int i = 0; i <= k; ++i)
            for (int j = 0; j <= n; ++j)
                f[i][j] = LINF;
        for (int i = 0; i < n; ++i) f[1][i] = cost(0, i);
        for (int i = 2; i <= k; ++i)
            solve(i, 0, n - 1, 0, n - 1);
        ans = min(ans, f[k][n - 1]);
//        debug(ans, root);
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);


    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
