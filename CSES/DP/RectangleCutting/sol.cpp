#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 166
#define debugArr(...) 166
#endif


const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int n, m;
int f[502][502];

int solve(int a, int b) {
    // debug(a, b);
    if (a == b)
        return 0;
    if (f[a][b] != -1)
        return f[a][b];
    int ans = INF;
    for (int k = 1; k < a; k++)
        ans = min(ans, 1 + solve(a - k, b) + solve(k, b));
    for (int k = 1; k < b; k++) 
        ans = min(ans, 1 + solve(a, b - k) + solve(a, k));
    return f[a][b] = ans;
}


void run_case() {
    cin >> n >> m;
    memset(f, -1, sizeof f);
    cout << solve(n, m) << "\n";
    // memset(f, 0x3f3f, sizeof f);
    // for (int i = 0; i <= max(n, m); i++) f[i][i] = 0;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         if (f[i][j] != INF)
    //             continue;
    //         for (int k = 1; k < i; k++)
    //             f[i][j] = min(f[i][j], 1 + f[i - k][j] + f[k][j]);
    //         for (int k = 1; k < j; k++)
    //             f[i][j] = min(f[i][j], 1 + f[i][j - k] + f[j][k]);
    //     }
    // }
    // // FOR(i, 1, n) FOR(j, 1, m) cout << f[i][j] << " \n"[j == m];
    // cout << f[n][m] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

