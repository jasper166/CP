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
const int MAX = 20;


int a[MAX];
ll n, k;

ll lcm(int a, int b) {
    return 1ll * a / gcd(a, b) * b;
}

void run_case() {

    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> a[i];

    int r = 0;
    for (int msk = 1; msk < (1 << k); msk++) {
        int cnt = __builtin_popcount(msk);
        ll p = 1;
        for (int i = 0; i < k; i++)
            if (msk & (1 << i))
                p = lcm(p, a[i]);
        if (cnt & 1)
            r += n / p;
        else
            r -= n / p;
    }
    cout << n - r << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

