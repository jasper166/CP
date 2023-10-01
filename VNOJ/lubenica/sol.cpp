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
const int MAX = 1e5 + 5;
const int LOG = 18;

int n;
vector <pii> adj[MAX];
int wMax[LOG][MAX];
int wMin[LOG][MAX];
int up[LOG][MAX];
int dep[MAX];

void dfs(int u) {
    for (auto [w, v] : adj[u]) {
        if (v == up[0][u]) 
            continue;
        dep[v] = dep[u] + 1;
        wMax[0][v] = wMin[0][v] = w;
        up[0][v] = u;

        for (int i = 1; i < LOG; i++) {
            wMax[i][v] = max(wMax[i - 1][v], wMax[i - 1][up[i - 1][v]]);
            wMin[i][v] = min(wMin[i - 1][v], wMin[i - 1][up[i - 1][v]]);
            up[i][v] = up[i - 1][up[i - 1][v]];
        }
        dfs(v);
    }
}

pii getLCA(int u, int v) {
    // debug(u, v);
    int maxi = 0, mini = INF;
    
    if (dep[u] != dep[v]) {
        if (dep[u] < dep[v]) 
            swap(u, v);
        int k = dep[u] - dep[v];
        for (int i = 0; (1 << i) <= k; i++) {
            if (k & (1 << i)) {
                debug(u);
                maxi = max(maxi, wMax[i][u]);
                mini = min(mini, wMin[i][u]);
                u = up[i][u];
            }
        }
    }
    debug(u, v);
    if (u == v) 
        return make_pair(mini, maxi);
    int k = 0;
    while ((1 << k) <= dep[u]) k++;
    for (int i = k; i >= 0; i--) {
        if (up[i][u] != up[i][v]) {
            maxi = max({maxi, wMax[i][u], wMax[i][v]});
            mini = min({mini, wMin[i][u], wMin[i][v]});
            u = up[i][u];
            v = up[i][v];
        }
    }
    maxi = max({maxi, wMax[0][u], wMax[0][v]});
    mini = min({mini, wMin[0][u], wMin[0][v]});
    return make_pair(mini, maxi);
}
int q;
void run_case() {
    cin >> n;
    memset(wMax, 0, sizeof wMax);
    memset(wMin, 0x3f3f3f, sizeof wMin);
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    dfs(1);
    cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        auto [x, y] = getLCA(u, v);
        cout << x << " " << y << "\n";
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

