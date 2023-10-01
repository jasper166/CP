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

ll f[52][2][18][18][18];
int n;
string X;

ll cal(int pos, int sml, int c3, int c6, int c9) {
    if (pos == n) {
        return (c3 && (c3 == c6) && (c6 == c9));
    }

    if (c3 >= 18 || c6 >= 18 || c9 >= 18)
        return 0;

    if (sml && f[n - pos - 1][sml][c3][c6][c9] != -1)
        return f[n - pos - 1][sml][c3][c6][c9];

    int upper = (sml? 9 : X[pos] - '0');
    ll ans = 0;
    for (int d = 0; d <= upper; d++) {
        int n_sml = sml || (d < X[pos] - '0');
        int n_c3 = c3 + (d == 3);
        int n_c6 = c6 + (d == 6);
        int n_c9 = c9 + (d == 9);
        ans += cal(pos + 1, n_sml, n_c3, n_c6, n_c9) % MOD;
        ans %= MOD;
    }
    if (sml)
        f[n - pos - 1][sml][c3][c6][c9] = ans;
    return ans;
}

ll solve(string& x) {
    X = x;
    n = X.size();
    return cal(0, 0, 0, 0, 0);
}

void run_case() {
    string a, b;
    cin >> a >> b;

    array <int, 3> c = {0, 0, 0};
    for (auto x : a) {
        if (x == '3') c[0]++;
        if (x == '6') c[1]++;
        if (x == '9') c[2]++;
    }

    ll res = 0;
    if (c[0] && (c[0] == c[1]) && (c[1] == c[2])) res++; 
    res = (res + solve(b) - solve(a) + MOD) % MOD;
    cout << res << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    memset(f, -1, sizeof f);
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

