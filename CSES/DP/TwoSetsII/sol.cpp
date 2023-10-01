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
const int MAX = 5e2 + 5;

int f[MAX][MAX * (MAX  - 1) / 2];
int n;

int power(int a, int b) {
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = (1ll * ans * a) % MOD;
        a = (1ll * a * a) % MOD;
        b >>= 1;
    }
    // cout << ans << "\n";
    return ans;
}

void run_case() {
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum & 1) {
        cout << "0\n";
        return;
    }
    int x = sum / 2;
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            f[i][j] = (f[i][j] + f[i - 1][j]) % MOD;
            if (j >= i)
                f[i][j] = (f[i][j] + f[i - 1][j - i]) % MOD;
        }
    }

    int ans = (1ll * f[n][x] * power(2, MOD - 2)) % MOD;
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

