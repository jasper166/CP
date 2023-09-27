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

int n, k;
vector <int> adj[MAX];
int f[MAX], sz[MAX], dep[MAX];

void dfs(int u, int p) {
    bool isLeaf = 1;
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v ^ p) {
            isLeaf = 0;
            dep[v] = dep[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
    f[u] = dep[u] - (sz[u] - 1);
}

void run_case() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    // FOR(i, 1, n) {debug(sz[i], dep[i], f[i]);};
    
    sort(f + 1, f + 1 + n, greater <int> ());
    ll ans = 0;
    for (int i = 1; i <= k; i++)
        ans += f[i];
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

