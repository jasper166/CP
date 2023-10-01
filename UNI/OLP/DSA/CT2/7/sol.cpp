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

ll n, k;
ll f[93];

void run_case() {
    cin >> n >> k;

    while (1){
        if (f[n - 2] < k && k <= f[n - 1] + f[n - 2]){
            k -= f[n - 2];
            --n;
        }
        else if (1 <= k && k <= f[n - 2]) n -= 2;
        if (n <= 2){
            break;
        }
        debug(k);
        debug(n);
    } 
    cout << n - 1 << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;

    f[1] = f[2] = 1;
    for (int i = 3; i <= 92; i++) f[i] = f[i - 1] + f[i - 2];

    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
