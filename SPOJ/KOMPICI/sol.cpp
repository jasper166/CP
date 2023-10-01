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

// #define int unsigned long long

// const int LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 11;

int n;
int cnt[1 << MAX | 1];

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        int msk = 0;
        while (x) {
            int d = x % 10;
            msk |= (1 << d);
            x /= 10;
        }
        cnt[msk]++;
    }
    ll ans = 0;
    // check different number;
    for (int msk = 0; msk < (1 << 10); msk++) {
        if (cnt[msk] == 0)
            continue;
        for (int msk2 = msk + 1; msk2 < (1 << 10); msk2++) {
            if (msk & msk2)
                ans += 1ll * cnt[msk] * cnt[msk2];
        }
    }

    // check for same number;
    ll add = 0;
    for (int msk = 0; msk < (1 << 10); msk++)
        add += 1ll * cnt[msk] * (cnt[msk] - 1);
    cout << ans + add / 2 << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    // cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

