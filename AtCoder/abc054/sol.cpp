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
const int MAX = 10;

int n, m;
bool edge[MAX][MAX];

void run_case() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        edge[u][v] = edge[v][u] = 1;
    }
    
    vector <vector <int>> f((1 << n) + 2, vector <int> (n + 2, 0));    
    f[1][0] = 1;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u)))
                continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v) || edge[u][v] == 0)
                    continue;
                int nxt_mask = mask | (1 << v);
                f[nxt_mask][v] += f[mask][u];
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) 
        res += f[(1 << n) - 1][i];
    cout << res << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

