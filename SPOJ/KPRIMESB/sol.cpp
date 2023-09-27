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

#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

bool pr[MAX];
int f[MAX];
int n, k;
int a[20];

void prepare() {
    memset(pr, 1, sizeof pr);
    pr[0] = pr[1] = 0;
    for (int i = 1; i * i < MAX; i++) {
        if (pr[i])
            for (int j = i * i; j < MAX; j += i)
                pr[j] = 0;
    }
    for (int i = 1; i < MAX; i++)
        f[i] = f[i - 1] + (pr[i]);
}

void run_case() {
    // since we used K primes and others (including 1) in [1, n] dont contribute to answer; -> 
    cin >> n >> k;
    
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        if (a[i] <= n)
            cnt++;
    }

    int r = 0;
    int other = f[n] - cnt + 1; // other primes and 1;
    for (int msk = 1; msk < (1 << k); msk++) {
        ll p = 1;
        int cnt = __builtin_popcount(msk);
        for (int i = 0; i < k; i++) {
            if (msk & (1 << i))
                p *= 1ll * a[i];
        }
        if (cnt & 1)
            r += n / p;
        else
            r -= n / p;
    }
    // debug(other, n, r);
    int ans = n - r - other; // 1 doesnt contribute 
    if (ans < 0) ans = 0;
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    prepare();
    for (int test = 1; test <= Test; test++){
        cout << "Case " << test << ": ";
        run_case();
    }
}

