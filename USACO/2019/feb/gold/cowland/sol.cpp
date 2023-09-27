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
int st[MAX], en[MAX];
int a[MAX];
int timer;
vector <int> adj[MAX];

int up[20][MAX];
int dep[MAX];

struct FenwickTree {
    int f[MAX << 2];
    void update(int x, int val) {
        for (; x <= timer; x += x & -x)
            f[x] ^= val;
    }
    int get(int x) {
        int ans = 0;
        for (; x; x -= x & -x)
            ans ^= f[x];
        return ans;
    }
} bit;

void dfs(int u, int p) {
    st[u] = ++timer;
    for (int v : adj[u]) {
        if (v == p) 
            continue;
        dep[v] = dep[u] + 1;
        up[0][v] = u;
        for (int i = 1; i < 20; i++)
            up[i][v] = up[i - 1][up[i - 1][v]];

        dfs(v, u);
    }
    en[u] = timer;
}

int getLCA(int u, int v) {
    if (dep[u] != dep[v]) {
        if (dep[u] < dep[v])
            swap(u, v);
        int k = dep[u] - dep[v];
        for (int i = 0; (1 << i) <= k; i++) {
            if (k & (1 << i))
                u = up[i][u];
        }
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


void run_case() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        bit.update(st[i], a[i]);
        bit.update(en[i] + 1, a[i]);
    }

    debug(timer);
    // xor (u -> v) = (xor (root, u) ^ xor (root, v) ^ e[lca(u, v)]);
    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int x, val; cin >> x >> val;
            bit.update(st[x], a[x] ^ val);
            bit.update(en[x] + 1, a[x] ^ val);
            a[x] = val;
        }
        else {
            int u, v; cin >> u >> v;
            int x = getLCA(u, v);
            int U = bit.get(st[u]);
            int V = bit.get(st[v]);
            debug(x, U, V);
            cout << (U ^ V ^ a[x]) << "\n";
        }
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

