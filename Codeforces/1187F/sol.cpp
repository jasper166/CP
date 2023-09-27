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

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif


const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int n;
vector <int> adj[MAX];
ll f[MAX], g[MAX];
int sz[MAX];
ll ans;

void dfs(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v ^ p) {
            dfs(v, u);
            sz[u] += sz[v];
            f[u] += f[v];
        }
    }
    f[u] += sz[u];
}

void change(int u, int v) {
    // root is v
    int sv = sz[v];

    sz[v] = sz[u];
    sz[u] -= sv;

    f[u] -= f[v] + sv;
    f[v] += f[u] + sz[u];
}

void reroot(int u, int p) {
    ans = max(ans, f[u]);
    for (int v : adj[u]) {
        if (v ^ p) {
            // f[v] = f[u] + n - 2ll * sz[v];
            change(u, v);
            reroot(v, u);
            change(v, u);
        }
    }
}

void run_case() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    reroot(1, 0);

    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

