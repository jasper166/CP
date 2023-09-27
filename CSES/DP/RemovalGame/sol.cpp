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

ll f[MAX][MAX];
int n;
int a[MAX];

ll solve(int l, int r) {
    if (l > r)
        return 0;
    if (l == r)
        return a[l];
    if (f[l][r] != -1)
        return f[l][r];

    ll ans = -LINF;
    ans = max(ans, a[l] - solve(l + 1, r));
    ans = max(ans, a[r] - solve(l, r - 1));
    return (f[l][r] = ans);
}

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(f, -1, sizeof f);
    ll sum = accumulate(a + 1, a + 1 + n, 0ll);
    /*
    f1 + f2 = sum;
    f1 - f2 = x??
    */
    cout << (sum + solve(1, n)) / 2 << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

