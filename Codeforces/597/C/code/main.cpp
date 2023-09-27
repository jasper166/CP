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
const int MAX = 1e5 + 5;

struct Fenwick {
    vector <vector <ll>> f;
    int n, k;
    Fenwick(int N, int K) : n(N), k(K), f(K + 5, vector <ll> (N + 5)) {};
    void add(int K, int x, ll val) {
        for (; x <= n; x += x & -x)
            f[K][x] += val;
    }
    ll qry(int K, int x) {
        ll ans = 0;
        for (; x; x -= x & -x)
            ans += f[K][x];
        return ans;
    }
};

int n, k;
int a[MAX];
ll dp[12][MAX];

void run_case() {
    cin >> n >> k;
    ++k;
    Fenwick bit(n, k);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = 1;
        bit.add(1, a[i], 1);
        for (int x = 2; x <= k; ++x) {
            dp[x][i] += bit.qry(x - 1, a[i] - 1);
            bit.add(x, a[i], dp[x][i]);
        }
        ans += dp[k][i];
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
