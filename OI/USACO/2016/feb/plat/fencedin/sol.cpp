#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

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

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 3e4 + 5;

int A, B, n, m;
int a[N], b[N];
int fa[N], fb[N];
void run_case() {
    cin >> A >> B >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    
    a[n + 1] = A, b[m + 1] = B;   
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    for (int i = 0; i <= n; ++i)
        fa[i] = a[i + 1] - a[i];
    for (int i = 0; i <= m; ++i)
        fb[i] = b[i + 1] - b[i];
    // Sorting here doesn't change the connectivity
    sort(fa, fa + 1 + n);
    sort(fb, fb + 1 + m);
    // have to do this first
    ll ans = 1ll * m * fa[0] + 1ll * n * fb[0];
    int i = 1, j = 1;
    while (i <= n && j <= m) {
        if (fa[i] < fb[j]) {
            ans += 1ll * fa[i] * (m - j + 1);
            ++i;
        }
        else {
            ans += 1ll * fb[j] * (n - i + 1);
            ++j;
        }
    }
    cout << ans << "\n";
}
/*
    -MST? But we can't use Kruskal here
    but we can follow its greedy algorithm.
    It is optimal to remove fence in the same row or column
    -> 
    1. Sorting the fence length.
    2. If we at ith fence of vertical (A) or jth fence of horizontal(B), 
        we should have remove (n + 1 - i) or (m + 1 - j) fence before depend
        on which is minimimum;
*/
void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    // setIO("fencedin");   
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


