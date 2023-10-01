#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

//#define int long long
using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

ll eval(ll n, ll k, ll x) {
    ll ans = (n + 20 * x) * (k - 4 * x);
//    debug(n, k, x, ans);
    return ans;
}

ll cal(int n, int k, int t) {
    // finding max of function : (n + 20 * x) * (k - x);
//    debug(n, k, t);
    int lo = 0, hi = (k - t) / 4;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (eval(n, k, m) < eval(n, k, m + 1))
            lo = m + 1;
        else
            hi = m - 1;
    }
    return eval(n, k, lo);
}
int n, k;
void run_case() {
    cin >> n >> k;
    int d = n % 10;
    ll ans = 1ll * n * k;
    if (d == 5)
        ans = max(ans, 1ll * (n + d) * (k - 1));
    else if (d) {
        if (d & 1) {
            n = n + d;
            --k;
        }
//        debug(n, k);
        for (int t = 0; t < 4; ++t) {
            if (k > 0)
                ans = max(ans, cal(n, k, t));
            n += n % 10;
            --k;
        }
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
