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
const int MAX = 1e3 + 5;

int n, m;
int a[MAX][MAX];
int f[MAX][MAX];
int g[MAX][MAX];

void run_case() {
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            f[i][j] = a[i][j];
            g[i][j] = a[i][j] ^ 1;
            if (a[i][j]) {
                f[i][j] = 1 + min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]});
                g[i][j] = 0;
            }
            else {
                f[i][j] = 0;
                g[i][j] = 1 + min({g[i - 1][j], g[i][j - 1], g[i - 1][j - 1]});
            }
            ans = max({ans, f[i][j], g[i][j]});
        }
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

