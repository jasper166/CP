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
const int MAX = 1e4 + 5;
const int LOG = 16;

int n;
vector <pii> adj[MAX];
int dep[MAX], f[MAX], up[LOG][MAX];

int jumpKth(int u, int k) {
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            u = up[i][u];
        }
    }
    return u;
}

void dfs(int u) {
    for (auto [w, v] : adj[u]) {
        if (v == up[0][u])
            continue;
        dep[v] = dep[u] + 1;
        f[v] = f[u] + w;
        up[0][v] = u;

        for (int k = 1; k < LOG; k++)
            up[k][v] = up[k - 1][up[k - 1][v]];
        dfs(v);
    }
}

int getLCA(int u, int v) {
    if (dep[u] != dep[v]) {
        if (dep[u] < dep[v])
            swap(u, v);
        int k = dep[u] - dep[v];
        u = jumpKth(u, k);
    }
    if (u == v)
        return u;

    int k = 0;
    while ((1 << k) <= dep[u]) k++;
    for (int i = k; i >= 0; i--) {
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}

int getDist(int u, int v) {
    int x = getLCA(u, v);
    return f[u] + f[v] - 2 * f[x];
}

int getKth(int u, int v, int k) {
    int x = getLCA(u, v);
    // debug(x, u, v);
    if (dep[u] < dep[v]) {
        swap(u, v);
        k = dep[u] + dep[v] - 2 * dep[x] - k;
    }
    int d = dep[u] - dep[x];
    if (k < d)
        return jumpKth(u, k);
    else
        return jumpKth(v, dep[v] - dep[x] - k + d);
}

void run_case() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});   
    }
    dfs(1);
    string s;
    while (cin >> s) {
        // cout << s << "\n";
        if (s == "DONE") break;
        int u, v, k;
        if (s[0] == 'D') {
            cin >> u >> v;
            cout << getDist(u, v) << "\n";
        }
        else {
            cin >> u >> v >> k;
            cout << getKth(u, v, k - 1) << "\n";
        }
    }

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        f[i] = dep[i] = 0;
        for (int j = 0; j < LOG; j++) up[j][i] = 0;
    }
    cout << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

