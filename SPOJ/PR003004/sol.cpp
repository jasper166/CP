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

ll f[18][2][18 * 9];
int n;

ll cal(string X, int pos, bool smaller, ll sum) {
    if (pos == n)
        return sum;
    if (f[pos][smaller][sum] != -1)
        return f[pos][smaller][sum];

    ll ans = 0;
    int limit = (smaller)? 9 : (X[pos] - '0');
    for (int i = 0; i <= limit; i++) {
        ans += cal(X, pos + 1, smaller || (i < X[pos] - '0'), sum + i);
    }
    return f[pos][smaller][sum] = ans;
}

ll solve(ll x) {
    if (x <= 0)
        return 0;
    string X = to_string(x);
    n = X.size();
    memset(f, -1, sizeof f);
    debug(X);
    return cal(X, 0, 0, 0);
}

void run_case() {
    ll l, r; 
    cin >> l >> r;
    if (l > r) swap(l, r);
    cout << (solve(r) - solve(l - 1)) << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

