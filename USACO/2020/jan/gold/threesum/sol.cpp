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
const int MAX = 5e3 + 5;
const int MAX_VAL = 1e6;

ll f[MAX][MAX];
int a[MAX];
int frq[MAX_VAL * 3];
int n, q;

ll qry(int l, int r) {
    if (l > r) swap(l, r);
    return f[l][r];
}
void run_case() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += MAX_VAL;
    }
    
    for (int i = 1; i <= n; i++) {    
        for (int j = i + 1; j <= n; j++) {
            int rem = MAX_VAL * 3 - a[i] - a[j];
            if (0 <= rem && rem < MAX_VAL * 3)
                f[i][j] = frq[rem];
            frq[a[j]]++;
        }
        for (int j = i + 1; j <= n; j++) frq[a[j]]--;
    }

    for (int i = n; i >= 1; i--) {
        for (int j = i; j <= n; j++) {
            f[i][j] += f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1];
        }
    }

    for (int _ = 1; _ <= q; _++) {
        int l, r; cin >> l >> r;
        cout << qry(l, r) << "\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

