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
const int MAX = 2e3 + 5;

int n, k, t;

ll f[MAX][MAX];
ll cost[MAX][MAX];
ll prf[MAX];
ll a[MAX];
// f(k, i) = min(f(k - 1, j) + cost(j + 1, i);
// k = 1 -> v : median
// k = 2 -> v : parabola minimum
//

ll cal(ll A, ll B, ll C, ll x) {
    return (A * x * x + B * x + C);
}


int getMin(ll A, ll B, ll C) {
    if ((-B) % (2 * A) == 0) {
        return (-B) / (2 * A);
    }
    int x = (-B) / (2 * A);
    pair <ll, int> x1, x2;
    x1 = {cal(A, B, C, x), x};
    x2 = {cal(A, B, C, x + 1), x + 1};
    return min(x1, x2).se;
}

ll get(int l, int r) {
    return prf[r] - prf[l - 1];
}


void prepare() {
    if (t == 1) {
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                int x = i + (j - i  + 1) / 2;
                cost[i][j] = a[x] * (x - i + 1) - get(i, x) + get(x + 1, j) - a[x] * (j - x);
            }
        }
    }
    else {
        for (int i = 1; i <= n; ++i) {
            ll A = 0, B = 0, C = 0;
            for (int j = i; j <= n; ++j) {
                C += a[j] * a[j];
                B += a[j];
                A = j - i + 1;
                int x = getMin(A, -2 * B, C);
                cost[i][j] = A * x * x - 2 * B * x + C;
            }
        }
    }
}

void solve(int x, int l, int r, int optl, int optr) {
    if (l > r) return;
    int m = (l + r) / 2;
    int opt_pos = -1;
    for (int i = optl; i <= optr; ++i) {
        ll cur = f[x - 1][i] + cost[i + 1][m];
        if (cur < f[x][m]) {
            f[x][m] = cur;
            opt_pos = i;
        }
    }
    solve(x, l, m - 1, optl, opt_pos);
    solve(x, m + 1, r, opt_pos, optr);
}

void run_case() {
    cin >> n >> k >> t;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prf[i] = prf[i - 1] + a[i];
    }
    prepare();

    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= n; ++j)
            f[i][j] = LINF;
//    FOR(i, 1, n) FOR(j, i, n) { debug(cost[i][j]); }
    for (int i = 1; i <= n; ++i) f[1][i] = cost[1][i];
    for (int i = 2; i <= k; ++i)
        solve(i, 1, n, 1, n);

    cout << f[k][n] << "\n";
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
