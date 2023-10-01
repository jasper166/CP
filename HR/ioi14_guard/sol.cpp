#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX_N = 8000 + 5;
const int MAX_K = 800 + 5;

int n, k;
int a[MAX_N];
ll prf[MAX_N];
using pli = pair <ll, int>;
pli f[MAX_K][MAX_N];
// f(k, i) : minimum cost to partite first I people into K parts
ll cost(int l, int r) {
    if (l > r) return 0ll;
    return (prf[r] - prf[l - 1]) * 1ll * (r - l + 1);
}

void solve(int K, int l, int r, int optl, int optr) {
    if (l > r) return;
    int m = (l + r) >> 1;
    f[K][m] = {LINF, -1};
    for (int i = optl; i <= optr; ++i) {
        ll cur = f[K - 1][i].fi + cost(i + 1, m);
        f[K][m] = min(f[K][m], {cur, i});
    }
    solve(K, l, m - 1, optl, f[K][m].se);
    solve(K, m + 1, r, f[K][m].se, optr);
}

void run_case() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prf[i] = prf[i - 1] + a[i];
    }

    for (int i = 1; i <= n; ++i) 
        f[1][i] = make_pair(cost(1, i), i);

    for (int i = 2; i <= k; ++i)
        solve(i, 1, n, 1, n);

    cout << f[k][n].fi << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


