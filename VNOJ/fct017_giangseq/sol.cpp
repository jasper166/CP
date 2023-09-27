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
const int MAX = 2e3 + 5;

#define int long long
int n, k;
int a[MAX], f[MAX];

bool isOk(int x) {
    f[1] = 0;
    int res = n - 1;
    for (int i = 2; i <= n; i++) {
        f[i] = i - 1;
        for (int j = 1; j < i; j++) {
            // if, aj and ai no needed to change
            if (1ll * abs(a[i] - a[j]) <= 1ll * x * (i - j))
                f[i] = min(f[i], f[j] + (i - 1 - j));
        }
        res = min(res, f[i] + (n - i));
    }
    return (res <= k);
}

void run_case() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int lo = 0, hi = 2 * INF;
    int ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (isOk(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
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
