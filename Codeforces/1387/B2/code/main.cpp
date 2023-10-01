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

int sz[MAX];
int n;
ll total;
vector <int> adj[MAX];
vector <int> tree;
int ans[MAX];
void dfs(int u, int p, int t) {
    sz[u] = 1;
    if (t)
        tree.push_back(u);
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, t);
            sz[u] += sz[v];
            if (t)
                total += min(sz[v], n - sz[v]);
        }
    }
}

int getCentroid(int u, int p) {
    for (int v : adj[u])
        if (v != p && sz[v] > n / 2)
            return getCentroid(v, u);
    return u;
}

void run_case() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    int x = getCentroid(1, 0);
    dfs(x, 0, 1);
    cout << total * 2 << "\n";
    for (int i = 0; i < n; ++i) {
        ans[tree[i]] = tree[(i + n / 2) % n];
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " \n"[i == n];

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
