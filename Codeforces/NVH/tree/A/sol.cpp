#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;

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
using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int n;
vector <pii> adj[MAX];
int f[2][MAX];

void dfs(int u, int p) {
    vector <int> subtree;
    for (auto [w, v] : adj[u]) {
        if (v ^ p) {
            dfs(v, u);
            subtree.push_back(w + f[0][v]);
        }
    }
    // is a leaf
    if (subtree.empty()) {
        f[0][u] = 0;
        return;
    }

    int f1 = -1, f2 = -2;
    for (auto fv : subtree) {
        if (f1 < fv) {
            f2 = f1;
            f1 = fv;
        }
        else if (f2 < fv)
            f2 = fv;
    }

    if (f1 != -1)
        f[0][u] = max(f[0][u], f1);
    if (f2 != -1)
        f[1][u] = max(f[1][u], f1 + f2);

}

void run_case() {
    cin >> n;
    
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    dfs(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) 
        ans = max({ans, f[0][i], f[1][i]});
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

