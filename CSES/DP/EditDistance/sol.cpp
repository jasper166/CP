
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
const int MAX = 5e3 + 5;

string s, t;
int f[MAX][MAX];

void run_case() {
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    
    memset(f, 0x3f3f3f, sizeof f);
    // debug(0x3f3f);
    // -1 for empty string but has to zeroing index
    for (int i = 0; i <= n; i++)
        f[i][0] = i;
    for (int j = 0; j <= m; j++)
        f[0][j] = j;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else
                f[i][j] = min(f[i][j], 1 + min({f[i][j - 1], f[i - 1][j], f[i - 1][j - 1]}));
        }
    }
    // FOR(i, 1, n) FOR(j, 1, m) cout << f[i][j] << " \n"[j == m];
    cout << f[n][m] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

