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

#define int long long
using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

// Inclusion Exclusion

bool used[MAX];
int n, m, l, r;

int bPow(int a, int b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (1ll * ans * a) % MOD;
        a = (1ll * a * a) % MOD;
        b >>= 1;
    }
    return ans % MOD;
}

int cal(int x) {
    vector <int> d;
    for (int i = 2; i <= x; ++i) {
        if (x % i == 0) {
            int p = 1;
            while (x % i == 0) {
                x /= i;
                p *= i;
            }
            d.push_back(p);
        }
    }
    int sz = d.size();
    int total = bPow(m, n);
    int excl = 0;
    for (int msk = 1; msk < (1 << sz); ++msk) {
        int cnt = 0;
        for (int j = 0; j < sz; ++j) {
            if (msk & (1 << j)) {
                for (int k = d[j]; k <= m; k += d[j])
                    used[k] = 1;
            }
        }

        for (int j = 1; j <= m; j++) {
            if (!used[j]) ++cnt;
            used[j] = 0;
        }
        if (__builtin_popcount(msk) & 1)
            excl += bPow(cnt, n);
        else
            excl -= bPow(cnt, n);
        while (excl < 0) excl += MOD;
    }
    int ans = total - excl;
    while (ans < MOD) ans += MOD;
    ans %= MOD;
    return ans % MOD;
}

void run_case() {
    cin >> n >> m >> l >> r;
    ll ans = 0;
    for (int i = l; i <= r; ++i) {
        ans += cal(i);
        ans %= MOD;
    }
    cout << ans << "\n";
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
