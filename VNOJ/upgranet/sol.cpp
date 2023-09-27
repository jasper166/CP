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

#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

struct DSU {
    int n;
    int *rk, *p;
    void init(int N) {
        n = N;
        rk = new int[N + 1];
        p = new int[N + 1];
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
            rk[i] = 0;
        }
    }

    int get(int u) {
        return (u == p[u]? u : p[u] = get(p[u]));
    }

    bool unite (int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v)
            return 0;
        if (rk[u] < rk[v])
            swap(u, v);
        if (rk[u] == rk[v])
            rk[u]++;
        p[v] = u;
        return 1;
    }
} dsu;

struct Edge {
    int u, v, w;
};

const int LOG = 20;

int n, m;
vector <Edge> e;
bool used[MAX];
vector <pii> adj[MAX];
int dep[MAX], up[LOG][MAX];
int eMin[LOG][MAX];


void dfs(int u, int p) {
    for (auto [w, v] : adj[u]) {
        if (v == p)
            continue;
        dep[v] = dep[u] + 1;
        up[0][v] = u;
        eMin[0][v] = w;
        for (int i = 1; i < LOG; i++) {
            eMin[i][v] = min(eMin[i - 1][v], eMin[i - 1][up[i - 1][v]]);
            up[i][v] = up[i - 1][up[i - 1][v]];
        }

        dfs(v, u);
    }
}

int getLCA(int u, int v) {
    int ans = INF;
    if (dep[u] != dep[v]) {
        if (dep[u] < dep[v])
            swap(u, v);
        int k = dep[u] - dep[v];
        for (int i = 0; (1 << i) <= k; i++)
            if (k & (1 << i)) {
                ans = min(ans, eMin[i][u]);
                u = up[i][u];
            }
    }

    if (u == v)
        return ans;

    int k = 0;
    while ((1 << k) <= dep[u]) ++k;
    for (int i = k; i >= 0; i--) {
        if (up[i][u] != up[i][v]) {
            ans = min({ans, eMin[i][u], eMin[i][v]}); 
            u = up[i][u];
            v = up[i][v];
        }
    }
    ans = min({ans, eMin[0][u], eMin[0][v]}); 
    return ans;
}


void run_case() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e.push_back({u, v, w});
    }
    // find the max span tree
    sort(e.begin(), e.end(), [] (const Edge &x, const Edge &y) {
        return x.w > y.w;
    });
    dsu.init(n);
    // int res = 0;
    for (int i = 0; i < e.size(); i++) {
        auto [u, v, w] = e[i];
        if (dsu.unite(u, v)) {
            used[i] = 1;
            // debug(u, v);
        }
    }
    // build graph on mst;
    for (int i = 0; i < m; i++) {
        if (used[i]) {
            auto [u, v, w] = e[i];
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
    }
    dfs(1, 0);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        if (!used[i]) {
            auto [u, v, w] = e[i];
            int x = getLCA(u, v);
            debug(u, v, x);
            // debug(dU, dV);
            ans += 1ll * (x - w);
        }
    }
    cout << ans << "\n";
}
/*
    Thong luong (u, v) : Canh lon nhat trong cac canh nho nhat cua cac duong 
    noi (u, v) la x;
    ->  Ta can: (x - w) min
        voi dk x >= w;
    -> Dung cay khung cuc dai (de voi moi (u, v) chua dung den ta co x >= w);
*/

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

