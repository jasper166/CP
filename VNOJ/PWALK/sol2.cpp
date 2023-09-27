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
const int MAX = 1e3 + 5;
const int LOG = 12;

int n, q;
vector <pii> adj[MAX];
int up[LOG][MAX];
int dep[MAX], d[MAX];
// dis(u, v) = d[u] + d[v] - 2 * d[lca(u, v)];
void dfs(int u) {
    for (auto [w, v] : adj[u]) {
        if (v == up[0][u])
            continue;
        dep[v] = dep[u] + 1;
        d[v] = d[u] + w;
        up[0][v] = u;

        for (int i = 1; i < LOG; i++) 
            up[i][v] = up[i - 1][up[i - 1][v]];
        dfs(v);
    }
}

int getLCA(int u, int v) {
    if (dep[u] != dep[v]) {
        // nhay len to tien thu k de dep(u) = dep(v);
        if (dep[u] < dep[v])
            swap(u, v);
        int k = dep[u] - dep[v];
        for (int i = 0; (1 << i) <= k; i++)
            if (k & (1 << i))
                u = up[i][u];
    }
    if (u == v) return u;
    
    int k = 0;
    while ((1 << k) <= dep[u]) k++;
    for (int i = k; i >= 0; i--) {
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}

int query(int u, int v) {
    int x = getLCA(u, v);
    return d[u] + d[v] - 2 * d[x];
}

void run_case() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    dfs(1);
    for (int i = 1; i <= q; i++) {
        int u, v; cin >> u >> v;
        cout << query(u, v) << "\n";
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

