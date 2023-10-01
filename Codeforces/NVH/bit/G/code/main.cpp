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
const int MOD = 30103;
const int MAX = 1e3 + 5;

struct BIT_2D {
    int f[MAX][MAX * 2];
    int N, M;
    void init(int _n, int _m) {
        N = _n;
        M = _m;
    }
    void upd(int x, int y, int val) {
        for (; x; x -= x & -x)
            for (int z = y; z; z -= z & -z)
                f[x][z] = (f[x][z] + val) % MOD;
    }

    int qry(int x, int y) {
        int ans = 0;
        for (; x <= N; x += x & -x) {
            for (int z = y; z <= M; z += z & -z)
                ans = (ans + f[x][z]) % MOD;
        }
        return ans;
    }

} bit;

int n;
int a[MAX];
int f[MAX][MAX];
// Numbers of special subset that begins at i and end at j;
void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int m = *max_element(a + 1, a + 1 + n);
    bit.init(n, m * 2);

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            // base case: when  the subset contains only 2 elements (but it's invalid);
            f[i][j] = 1;
            f[i][j] = (f[i][j] + bit.qry(j + 1, a[i] + a[j] + 1)) % MOD;
            bit.upd(j, a[i] + a[j], f[i][j]);\
            // subtract invalid case;
            ans = (ans + f[i][j] - 1 + MOD) % MOD;
        }
    }
//    FOR(i, 1, n) FOR(j, 1, n) cout << f[i][j] << " \n"[j == n];
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
