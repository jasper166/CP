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
const int MAX = 22;

int n, x;
int a[MAX];
pii f[1 << MAX];

void run_case() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int msk = 0; msk < (1 << n); msk++) f[msk] = {INF, 0};
    f[0] = {1, 0};
    for (int msk = 0; msk < (1 << n); msk++) {
        for (int i = 0; i < n; i++) {
            if (msk & (1 << i))
                continue;
            int nxt = msk | (1 << i);
            auto here = f[msk];
            if (here.second + a[i] <= x) {
                here.second += a[i];
            }
            else {
                here.first += 1;
                here.second = a[i];
            }
            f[nxt] = min(f[nxt], here);

        }
    }
    // for (int msk = 0; msk < (1 << n); msk++) {debug(msk, f[msk]);};
    cout << f[(1 << n) - 1].first << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

