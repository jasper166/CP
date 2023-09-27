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

int n;
int c[MAX];
int f[MAX][MAX];

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    memset(f, 0x3f3f3f, sizeof f);

    for (int len = 1; len <= n; len++) {
        for (int l = 1; l <= n - len + 1; l++) {
            int r = l + len - 1;
            if (l == r) {
                f[l][r] = 1;
                continue;
            }
            if (l + 1 == r) {
                f[l][r] = (c[l] == c[r])? 1 : 2;
                continue;
            }
            // try to make (l, r) panlindrome
            if (c[l] == c[r]) 
                f[l][r] = f[l + 1][r - 1];
            // DP on range;
            for (int x = l + 1; x <= r; x++)
                f[l][r] = min(f[l][r], f[l][x - 1] + f[x][r]);
        }
    }
    cout << f[1][n] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

