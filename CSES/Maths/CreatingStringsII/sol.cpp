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

int fact[MAX], invf[MAX];
    
int Power(int a, int b) {
    // debug(a, b);
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (1ll * ans * a) % MOD;
        a = (1ll * a * a) % MOD;
        b >>= 1;
    }
    return (int) ans;
}

void prepare() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = (1ll * fact[i - 1] * i) % MOD;
    invf[MAX - 1] = Power(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--)
        invf[i] = (1ll * invf[i + 1] * (i + 1)) % MOD;
}

int C(int n, int k) {
    if (k > n)
        return 0;
    return (1ll * fact[n] * (1ll * invf[n - k] * invf[k]) % MOD) % MOD;
}


void run_case() {
    prepare();
    string s; cin >> s;
    map <char, int> cnt;
    for (auto x : s)
        cnt[x]++;
    int n = s.size();
    ll ans = fact[n];
    debug(ans);
    for (auto [x, c] : cnt) {
        // debug(x, c, invf[c]);
        ans = (1ll * ans * invf[c]) % MOD;
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

