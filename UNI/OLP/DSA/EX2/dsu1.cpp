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

#define int long long
const int MAX = 1e2 + 5;
const int BLOCK = 350;
const int MAX_VAL = 1e6 + 2;
const int LINF = 1e18 + 5;

int n, m, q;
int d[MAX][MAX];
void run_case() {
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, n) {
        if (i == j)
            d[i][j] = d[j][i] = 0;
        else
            d[i][j] = d[j][i] = LINF;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = d[v][u] = w;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) 
                d[j][i] = d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
    cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        cout << d[u][v] << "\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}