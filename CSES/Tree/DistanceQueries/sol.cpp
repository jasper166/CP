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

int n, q;
int timer = 0;
vector <int> adj[MAX];
int dep[MAX], f[MAX];
int st[MAX];
int up[LOG][MAX << 1];
int tour[MAX << 1], lg[MAX << 1];
// int s

int getLCA(int u, int v) {
    int l = st[u];
    int r = st[v];
    if (l > r)
        swap(l, r);
    int k = lg[r - l + 1];
    return (dep[up[k][l]] < dep[up[k][r - (1 << k) + 1]])? up[k][l] : up[k][r - (1 << k) + 1];
}

int query(int u, int v) {
    int x = getLCA(u, v);
    // debug(x);
    return f[u] + f[v] - 2 * f[x];
}

void build() {
    lg[1] = 0;
    for (int i = 2; i <= timer; i++)
        lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= timer; i++) 
        up[0][i] = tour[i];

    for (int k = 1; k < LOG; k++)
        for (int i = 1; i + (1 << k) - 1 <= timer; i++)
            up[k][i] = (dep[up[k - 1][i]] < dep[up[k - 1][i + (1 << (k - 1))]])?
                        up[k - 1][i] : up[k - 1][i + (1 << (k - 1))];
}

void dfs(int u, int p) {
    st[u] = ++timer;
    tour[timer] = u;
    for (int v : adj[u]) {
        if (v == p)
            continue;
        f[v] = f[u] + 1;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        tour[++timer] = u;
    }
}

void run_case() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    build();
    debug(n, q);
    while (q--) {
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

