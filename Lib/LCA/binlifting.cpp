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

using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const int LOG = 22;

int n, q;
int dep[MAX];
int up[LOG][MAX];
vector <int> adj[MAX];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v ^ p) {
            up[0][v] = u;
            dep[v] = dep[u] + 1;
            for (int k = 1; k < LOG; ++k)
                up[k][v] = up[k - 1][up[k - 1][v]];
            dfs(v, u);
        }
    }
}

int getLCA(int u, int v) {
    if (dep[u] != dep[v]) {
        if (dep[u] < dep[v]) swap(u, v);
        int k = dep[u] - dep[v];
        for (int i = LOG - 1; i >= 0; --i) {
            if ((k >> i) & 1)
                u = up[i][u];
        }
    }
    if (u == v)
        return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}


int getDis(int u, int v) {
    int x = getLCA(u, v);
    return dep[u] + dep[v] - 2 * dep[x];
}

void run_case() {
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Prepare();
    dfs(1, 0);
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
