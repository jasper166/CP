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


int n;
vector <int> adj[MAX];
int f[MAX][2];

void dfs(int u, int p) {
    vector <int> val;
    for (int v : adj[u]) {
        if (v == p)
            continue;
        dfs(v, u);
        val.push_back(f[v][0]);
    }
    int f1 = -1, f2 = -1;
    // if node u is a leaf
    if (val.empty()) {
        f[u][0] = 0;
        return;
    }

    for (auto x : val) {
        if (f1 < x) {
            f2 = f1;
            f1 = x;
        }
        else if (f2 < x)
            f2 = x;
    }
        
    if (f1 != -1)
        f[u][0] = 1 + f1;
    if (f2 != -1 && val.size() >= 2)
        f[u][1] = 2 + f1 + f2;
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
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max({ans, f[i][0], f[i][1]});
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

