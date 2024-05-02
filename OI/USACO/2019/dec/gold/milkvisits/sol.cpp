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
const int LOG = 20;

int n, q;
vector <int> adj[MAX];
int up[LOG][MAX];
int dep[MAX];
int a[MAX];
int st[MAX * 2], en[MAX * 2];
int timer;
vector <int> fst[MAX], lst[MAX];

void dfs(int u, int pa) {
    st[u] = timer;
    fst[a[u]].push_back(timer++);
    for (int v : adj[u]) {
        if (v ^ pa) {
            dep[v] = dep[u] + 1;
            up[0][v] = u;
            for (int i = 1; i < LOG; i++)
                up[i][v] = up[i - 1][up[i - 1][v]];
            dfs(v, u);
        }
    }
    lst[a[u]].push_back(timer++);
}

int lca(int u, int v) {
    if (dep[u] != dep[v]) {
        if (dep[u] < dep[v])
            swap(u, v);
        int k = dep[u] - dep[v];
        for (int i = 0; (1 << i) <= k; i++)
            if (k & (1 << i))
                u = up[i][u];
    }
    if (u == v)
        return u;
    int k = 0;
    while ((1 << k) <= dep[u]) ++k;
    for (int i = k; i >= 0; i--) {
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}

int qry(int u, int v, int c) {
    if (dep[u] > dep[v]) swap(u, v);
    int l = st[u];
    int r = st[v];
    // counting all node on euler tour
    int total = upper_bound(fst[c].begin(), fst[c].end(), r) - lower_bound(fst[c].begin(), fst[c].end(), l);
    // counting node that not on the path (u, v) (appear twice : fst and lst);
    int sub = upper_bound(lst[c].begin(), lst[c].end(), r) - lower_bound(lst[c].begin(), lst[c].end(), l);
    return total - sub;
}

void run_case() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    timer = 1;
    dfs(1, 0);

    while (q--) {
        int u, v, c;
        cin >> u >> v >> c;
        int x = lca(u, v);
        int fu = qry(u, x, c);
        int fv = qry(v, x, c);
        int cnt = fu + fv - (a[x] == c);
        // debug(fu, fv, x);
        cout << (cnt ? 1 : 0);
    }
    cout << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

