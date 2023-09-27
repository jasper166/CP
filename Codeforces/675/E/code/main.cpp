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

struct SparseTable {
    int n, k;
    vector <vector <int>> f;
    vector <int> a, lg;
    SparseTable(int N, int K) : n(N), k(K), f(K + 5, vector <int> (N + 5)), a(N + 5), lg(N + 5) {};
    void build() {
        lg[1] = 0;
        for (int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;
        for (int i = 1; i <= n; ++i) f[0][i] = i;
        for (int x = 1; x <= k; x++) {
            int step = 1 << (x - 1);
            for (int i = 1; i + step <= n; ++i) {
                int l = f[x - 1][i], r = f[x - 1][i + step];
                f[x][i] = (a[l] > a[r])? l : r;
            }
        }
    }
    int qry(int l, int r) {
        if (l > r) return -1;
        int k = lg[r - l + 1];
        int L = f[k][l], R = f[k][r - (1 << k) + 1];
        return a[L] > a[R]? L : R;
    }
};

int n;
int a[MAX];
ll dp[MAX];
void run_case() {
    cin >> n;
    SparseTable rmq(n, 18);
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        rmq.a[i] = a[i];
    }
    rmq.build();

    dp[n - 1] = 1;
    for (int i = n - 2; i >= 1; --i) {
        int j = rmq.qry(i + 1, a[i]);
        dp[i] = n - i - a[i] + j + dp[j];
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) ans += dp[i];
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
