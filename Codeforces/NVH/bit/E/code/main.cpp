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
const int MOD = 1e9;
const int MAX = 1e4 + 5;

const int K = 12;

struct BIT {
    int f[MAX][K];
    int N;
    void init(int _N) {
        N = _N;
    }
    void upd(int k, int x, int val) {
        for ( ; x; x -= x & -x)
            f[x][k] = (f[x][k] + val) % MOD;
    }
    int qry(int k, int x) {
        int ans = 0;
        for (; x <= N; x += x & -x)
            ans = (ans + f[x][k]) % MOD;
        return ans;
    }
} bit;

int n, k;
int a[MAX];
int f[MAX][K];

void run_case() {
    cin >> n >> k;
    bit.init(n);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (j == 1) {
                f[i][1] = 1;
                bit.upd(1, a[i], f[i][1]);
            }
            else {
                f[i][j] = bit.qry(j - 1, a[i] + 1);
                bit.upd(j, a[i], f[i][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + f[i][k]) % MOD;
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
//    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
