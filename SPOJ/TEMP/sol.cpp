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

string X;
int n;
ll f[20][12][2][2];

ll cal(int pos, int last, int smaller, int zero) {
    if (pos == n)
        return 1;

    if (f[pos][last][smaller][zero] != -1)
        return f[pos][last][smaller][zero];

    ll ans = 0;
    int upper = (smaller? 9 : X[pos] - '0');

    // debug(pos, last, smaller, zero, upper);
    for (int d = 0; d <= upper; d++) {
        //...1dd..
        if (d == last && zero == 0)
            continue;

        if (zero)
            ans += cal(pos + 1, d, smaller || (d < X[pos] - '0'), zero && (d == 0));
        else
            ans += cal(pos + 1, d, smaller || (d < X[pos] - '0'), 0);
    }

    return f[pos][last][smaller][zero] = ans;
}

ll solve(ll x) {
    if (x == -1)
        return 0;

    X = to_string(x);
    n = X.size();
    memset(f, -1, sizeof f);
    // debug(n, X);
    // 10 denotes init val;
    return cal(0, 10, 0, 1);
}

void run_case() {
    ll l, r;
    cin >> l >> r;
    ll ansR = solve(r);
    ll ansL = solve(l - 1);
    // debug(ansR);
    cout << ansR - ansL << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

