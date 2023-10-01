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

ll f[12][2][12 * 9];

ll solve(ll x) {
    if (x <= 0)
        return x;
    string X = to_string(x);
    int n = X.size();

    memset(f, 0, sizeof f);
    debug(n, X);

    // f[n][0][0] = f[n][1][0] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int sml = 0; sml < 2; sml++) {
            for (int x = 0; x <= 9 * n; x++) {
                if (sml) {
                    for (int d = 0; d <= 9; d++)
                        f[i][1][x] += d + f[i + 1][1][x + d];
                }
                else {
                    for (int d = 0; d <= (X[i] - '0'); d++) {
                        bool state = (d == (X[i] - '0'));
                        f[i][0][x] += d + f[i + 1][state][x + d];
                    }
                }
            }
        }
    }

    ll ans = f[0][0][0];
    return ans;
}


void run_case() {
    ll a, b;
    while (cin >> a >> b) {
        if (a == -1 & b == -1)
            exit(0);
        cout << solve(b) - solve(a - 1) << "\n";
    }


}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

