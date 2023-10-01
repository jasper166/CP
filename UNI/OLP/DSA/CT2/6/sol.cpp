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
#define debug(...) 42
#define debugArr(...) 42
#endif
#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 32;

ll f[93];

int helper (int n, int k) {
    if(k & 1)
        return 1;
    ll ans = pow(2, n - 1);
    if(k == ans)
        return n;
    return ((k >= ans)? helper(n - 1, k - ans) : helper(n - 1, k));
}

void run_case() {
    int n, k;
    cin >> n >> k;
    int res = helper (n, k);
    cout <<  (char) (res + 'A' - 1) << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;

    f[1] = 1;
    for (int i = 2; i <= 26; i++) 
        f[i] = f[i - 1] >> 1;

    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
