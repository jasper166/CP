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

// #define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e3 + 5;


int fact[MAX], invf[MAX];

int Power(int a, int b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (1ll * res * a) % MOD;
        a = (1ll * a * a) % MOD;
        b >>= 1;
    }
    return (int) res;
}

void prepare(int N) {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) 
        fact[i] = (1ll * i * fact[i - 1]) % MOD;

    invf[N] = Power(fact[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--)
        invf[i] = (1ll * invf[i + 1] * (i + 1)) % MOD;
}

int C(int n, int k) {
    // debug(n, k);
    if (n < k) return 0;
    return ((1ll * fact[n] * invf[n - k]) % MOD * 1ll * invf[k]) % MOD;
}

void run_case() {
    int n, k;
    cin >> n >> k;

    prepare(MAX - 1);
    for (int i = 1; i <= k; i++) {
        int ways = C(k - 1, i - 1);
        int res = (1ll * ways * C(n - k + 1, i)) % MOD;
        cout << res << "\n";
    }

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

