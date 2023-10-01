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
const int MAX = 2e5 + 5;
const int LOG = 20;

struct Data {
    int u, c1, c2;
};

int n;
ll res;
vector <Data> adj[MAX];
int f[MAX], dep[MAX], up[LOG][MAX];

void dfs(int u, int p) {
    for (auto [v, c1, c2] : adj[u]) {
        if (v == p)
            continue;
        dep[v] = dep[u] + 1;
        up[0][v] = u;
        for (int i = 1; i < LOG; i++)
            up[i][v] = up[i - 1][up[i - 1][v]];

        dfs(v, u);
    }
}


void update(int u, int p) {
    for (auto [v, c1, c2] : adj[u]) {
        if (v == p)
            continue;
        update(v, u);
        f[u] += f[v];
        res += min(1ll * f[v] * c1, 1ll * c2);
    }
    // debug(res);
}

int getLCA(int u, int v) {
    if (dep[u] != dep[v]) {
        if (dep[u] < dep[v]) swap(u, v);
        int k = dep[u] - dep[v];
        for (int i = 0; (1 << i) <= k; i++)
            if (k & (1 << i))
                u = up[i][u];
    }
    if (u == v)
        return u;

    int k = 0;
    while ((1 << k) <= dep[u]) ++k;
    for (int i = k; i >= 0; i--) {
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}

void run_case() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, c1, c2;
        cin >> u >> v >> c1 >> c2;
        adj[u].push_back({v, c1, c2});
        adj[v].push_back({u, c1, c2});
    }
    dfs(1, 0);
    for (int i = 1; i < n; i++) {
        int x = getLCA(i, i + 1);
        // debug(x);
        f[i]++, f[i + 1]++;
        f[x] -= 2;
    }
    res = 0ll;
    FOR(i, 1, n) cout << f[i] << " \n"[i == n];
    update(1, 0);
    FOR(i, 1, n) cout << f[i] << " \n"[i == n];
    cout << res << "\n";
}
// idea nhu bai xay cau`, f[u] de dem so lan tham node u;
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
