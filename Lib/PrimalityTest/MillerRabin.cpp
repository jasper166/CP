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

using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e2 + 5;

// Miller - Rabbin primality test: n <= 1e18, O(k * log2(n)) k : numbers of a;
// Using u128 : c++17
using u64 = uint64_t;
using u128 = __uint128_t;

u64 bPow(u64 a, u64 b, u64 mod) {
    u64 ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) ans = (u128) ans * a % mod;
        a = (u128) a * a % mod;
        b >>= 1;
    }
    return ans;
}

bool check_composite(u64 n, u64 a, u64 m, int k) {
    u64 x = bPow(a, m, n);
    if (x == 1 || x == n - 1)
        return 0;
    for (int i = 1; i < k; ++i) {
        x = (u128) x * x % n;
        if (x == n - 1)
            return 0;
    }
    return 1;
}

bool MillerRabin(u64 n) {
    if (n < 2) return 0;
    if (n % 2 == 0) return (n == 2);

    // N = n - 1 = 2^k * m;
    u64 m = n - 1;
    int k = 0;
    while ((m & 1) == 0) {
        m >>= 1;
        ++k;
    }
    // Check with a
    for (u64 a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return 1;
        if (check_composite(n, a, m, k))
            return 0;
    }
    return 1;

}

void run_case() {
    u64 n; cin >> n;
    cout << (MillerRabin(n)? "YES\n" : "NO\n");
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
