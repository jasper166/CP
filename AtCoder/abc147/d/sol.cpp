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


void run_case() {
    int n; cin >> n;
    vector <ll> a(n);
    for (ll &x : a) cin >> x;

    int bit = 0;
    ll m = *max_element(all(a));
    
    while (m) {
        bit++;
        m /= 2ll;
    }
    bit++;
    debug(bit);
    vector <int> p(bit + 2, 0);
    p[0] = 1;
    for (int i = 1; i <= bit; i++) p[i] = (1ll * p[i - 1] * 2) % MOD;
    ll ans = 0;
    for (int x = 0; x <= bit; x++) {
        int c[2] = {0};
        for (int i = 0; i < n; i++) {
            if (a[i] & (1ll << x))
                c[1]++;
            else 
                c[0]++;
        }
        // debug(c[0], c[1]);
        debug(p[x]);
        ll ways = (1ll * c[0] * c[1]) % MOD;
        (ans += (1ll * p[x] * ways) % MOD) %= MOD;
    }
    cout << ans << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

