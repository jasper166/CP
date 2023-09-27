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
const int MAX = 1e4 + 5;
const int LOG = 15;

int n, q;
vector <int> child[MAX];
int dep[MAX];
int up[LOG][MAX];

void dfs(int u) {
    for (int v : child[u]) {
        if (v == up[0][u])
            continue;
        up[0][v] = u;
        dep[v] = dep[u] + 1;
        for (int k = 1; k < LOG; k++)
            up[k][v] = up[k - 1][up[k - 1][v]];
        dfs(v);
    }
}

int getLCA(int u, int v) {
    if (dep[u] != dep[v]) {
        if (dep[u] < dep[v]) swap(u, v);
        int k = dep[u] - dep[v];
        // find the kth ancestor such that dep[u] = dep[v];
        for (int i = 0; (1 << i) <= k; i++)
            if (k & (1 << i))
                u = up[i][u];
    }
    // if same node then LCA is it own
    if (u == v)
        return u;
    int k = 0;
    while ((1 << k) <= dep[u]) k++;
    for (int i = k; i >= 0; i--) {
        // if the (2 ^ i)th ancestor differs
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}


void run_case() {
    cin >> n;
    for (int u = 0; u < n; u++) {
        int m; cin >> m;
        for (int j = 1; j <= m; j++) {
            int v; cin >> v;
            child[u].push_back(v);
        }
    }
    dfs(0);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int u, v; cin >> u >> v;
        cout << getLCA(u, v) << "\n";
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

