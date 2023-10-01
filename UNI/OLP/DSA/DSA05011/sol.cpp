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

#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAXS = 900;

int f[102][902][2];

int func(string s, int k) {
    int n = s.size();

    memset(f, 0, sizeof f);
    f[n][0][0] = f[n][0][1] = 1;
    // tight = 1 -> form suffix that not greater than number suffix
    for (int i = n - 1; i >= 0; i--) {
        for (int sum = 0; sum < 901; sum++) {
            for (int tight = 0; tight < 2; tight++) {
                if (tight) {
                    if (sum >= (s[i] - '0')) {
                        f[i][sum][1] += f[i + 1][sum - (s[i] - '0')][1];
                        f[i][sum][1] %= MOD;
                    }
                    for (int d = 0; d < (s[i] - '0'); d++) {
                        if (sum >= d) {
                            f[i][sum][1] += f[i + 1][sum - d][0];
                            f[i][sum][1] %= MOD;
                        }
                    } 
                }
                else {
                    for (int d = 0; d < 10; d++) {
                        if (sum >= d) {
                            f[i][sum][0] += f[i + 1][sum - d][0];
                            f[i][sum][0] %= MOD;
                        }
                    }
                }
            }
        }
    }
    int ans = f[0][k][1];
    return ans;
}

void run_case() {
    int n, k; cin >> n >> k;
    if (k > MAXS) {
        cout << "0\n";
        return;
    }
    string L, R;
    for (int i = 1; i <= n; i++) {
        R += "9";
        if (i < n) L += "9";
    }
    int sr = func(R, k);
    int sl = func(L, k);
    int res= sr - sl;
    while (res < 0)
        res += MOD;
    cout << res << "\n";
    // debug(L, R);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    // prepare();
    cin >> Test;

    for (int test = 1; test <= Test; test++){
        run_case();
    }
}


