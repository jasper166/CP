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

int f[102][902];

void prepare() {
    for (int i = 1; i <= 9; i++)
        f[1][i] = 1;
    for (int i = 2; i <= 100; i++) {
        for (int sum = 0; sum <= MAXS; sum++) {
            for (int d = 0; d <= 9; d++) {
                if (sum >= d) {
                    f[i][sum] += f[i - 1][sum - d];
                    f[i][sum] %= MOD;
                }
            }
        }
    }
}

void run_case() {
    int n, k; cin >> n >> k;
    int res = (k > MAXS)? 0 : f[n][k];
    cout << res << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    prepare();
    cin >> Test;

    for (int test = 1; test <= Test; test++){
        run_case();
    }
}


