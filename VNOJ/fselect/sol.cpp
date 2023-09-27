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

int n, k;
vector <int> adj[MAX];
vector <int> group[MAX >> 1];
int dep[MAX], up[LOG][MAX], f[MAX];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p)
            continue;

        up[0][v] = u;
        dep[v] = dep[u] + 1;
        f[v] = f[u] + 1;
        for (int i = 1; i < LOG; i++)
            up[i][v] = up[i - 1][up[i - 1][v]];
        dfs(v, u);
    }
}

int getLCA(int u, int v) {
    if (dep[u] != dep[v]) {
        if (dep[u] < dep[v])
            swap(u, v);
        int k = dep[u] - dep[v];
        for (int i = 0; (1 << i) <= k; ++i) {
            if (k & (1 << i)) 
                u = up[i][u];
        } 
    }

    if (u == v)
        return u;
    int k = 0;
    while ((1 << k) <= dep[u]) ++k;
    for (int i = k; i >= 0; i--)
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    return up[0][u];
}



int getDist(int u, int v) {
    if (u == v) return 0;
    int x = getLCA(u, v);
    // debug(x, u, v);
    return f[u] + f[v] - 2 * f[x];
}

int diameter(int x) {
    int d = 0, A = group[x][0];
    int B = A;
    for (int u : group[x]) {
        int cd = getDist(A, u);
        // debug(cd);
        if (cd > d) {
            d = cd;
            B = u;
        }
    }
    d = 0;
    for (int u : group[x]) {
        int cd = getDist(B, u);
        d = max(d, cd);
    }
    return d;
}

void run_case() {
    cin >> n >> k;
    int root = 0;
    for (int u = 1; u <= n; u++) {
        int x, v;
        cin >> x >> v;
        group[x].push_back(u);
        if (v == 0) 
            root = u;
        else {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    dfs(root, 0);
    // FOR(i, 1, n) cout << f[i] << "\n";
    for (int i = 1; i <= k; i++)
        cout << diameter(i) << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

