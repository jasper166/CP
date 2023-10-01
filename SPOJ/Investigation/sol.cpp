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

int k;
ll f[12][2][92][92];
int pw[12];
string X;
int n;

ll cal(int pos, int sml, int rmD, int rmN) {
    if (pos == n) {
        return (rmD == 0) && (rmN == 0);
    }

    if (sml && f[n - pos - 1][sml][rmD][rmN] != -1)
        return f[n - pos - 1][sml][rmD][rmN];

    int upper = (sml? 9 : X[pos] - '0');
    ll ans = 0;

    for (int d = 0; d <= upper; d++)
        ans += cal(pos + 1, sml || (d < X[pos] - '0'), (rmD + d) % k, (rmN * 10 + d) % k);
    if (sml)
        f[n - pos - 1][sml][rmD][rmN] = ans;
    return ans;
}

ll solve(ll x) {
    if (x < 0)
        return 0;

    X = to_string(x);
    n = X.size();
    
    // debug(X, n);
    return cal(0, 0, 0, 0);
}

void run_case() {
    ll a, b;
    cin >> a >> b >> k;
    cout << solve(b) - solve(a - 1) << "\n"; 

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    memset(f, -1, sizeof f);
    for (int test = 1; test <= Test; test++){
        cout << "Case " << test << ": ";
        run_case();
    }
}

