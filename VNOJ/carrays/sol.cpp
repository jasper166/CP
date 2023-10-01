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

int f[MAX], g[MAX];
int n, m, k;

int power(int a, int b) {
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = (1ll * ans * a) % MOD;
        a = (1ll * a * a) % MOD;
        b >>= 1;
    }
    return (int) ans;
}
// f(n) : count of array that doesnt contain any K equal element segment
// ans = total - exl;

void run_case() {
    cin >> n >> m >> k;
    memset(f, 0, sizeof f);

    for (int i = 1; i < k; i++) {
        f[i] = power(m, i);
        g[i] = (g[i - 1] + f[i]) % MOD;
    }
    for (int i = k; i <= n; i++) {
        ll x = (g[i - 1] - g[i - k] + MOD) % MOD;
        f[i] = (1ll * (m - 1) * x) % MOD;
        g[i] = (g[i - 1] + f[i]) % MOD;
    }
    cout << (power(m, n) - f[n] + MOD) % MOD << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

