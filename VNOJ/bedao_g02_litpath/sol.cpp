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

int n;
vector <pii> adj[MAX];
ll f[5][MAX];
ll ans = 0, res = 0;

void dfs(int u, int p) {
    for (auto [w, v] : adj[u]) {
        if (v == p)
            continue;
        dfs(v, u);
        (w)? f[3][v]++ : f[0][v]++;
        if (w) {
            // u is the end;
            ans += (2 * f[3][v] + f[2][v] + f[0][v]);
            // goes through u;
            ans += f[3][u] * f[3][v] * 2;
            ans += f[3][u] * f[0][v];
            ans += f[0][u] * f[3][v];
            ans += f[3][u] * f[2][v];
            ans += f[2][u] * f[3][v];

            f[2][u] += f[0][v] + f[2][v];
            f[3][u] += f[3][v];
        }
        else {
            // u is the end;
            ans += (2 * f[0][v] + f[3][v] + f[1][v]);
            // goes through u;
            ans += f[0][u] * f[0][v] * 2;
            ans += f[3][u] * f[0][v];
            ans += f[0][u] * f[3][v];
            ans += f[1][u] * f[0][v];
            ans += f[0][u] * f[1][v];

            f[0][u] += f[0][v];
            f[1][u] += f[1][v] + f[3][v];
        }
    }
}

void run_case() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    ans = 0;
    dfs(1, 0);
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

