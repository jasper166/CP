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
int dep[MAX], up[LOG][MAX];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p)
            continue;
        up[0][v] = u;
        dep[v] = dep[u] + 1;
        for (int i = 1; i < LOG; i++)
            up[i][v] = up[i - 1][up[i - 1][v]];
        dfs(v, u);
    }
}

int getLCA(int u, int v) {
    if (dep[u] != dep[v]) {
        if (dep[u] < dep[v]) swap(u, v);
        int k = dep[u] - dep[v];
        for (int i = 0; (1 << i) <= k; i++)
            if (k & (1 << i))
                u = up[i][u];
    }
    if (u == v)
        return u;
    int k = 0;
    while ((1 << k) <= dep[u]) k++;
    for (int i = k; i >= 0; --i)
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    return up[0][u];
}


struct SegTree {
    int *f;
    int n;

    int merge(int u, int v) {
        return getLCA(u, v);
        // return u + v;
    }

    void build(int N) {
        n = N;
        f = new int[(N << 1) + 2];
        for (int i = 1; i <= n; i++) 
            f[i + n] = i;
        for (int i = n; i; i--)
            f[i] = merge(f[i << 1], f[i << 1 | 1]);
    }

    int query(int l, int r) {
        int ans = l;
        // int lef = 0, rig = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) 
                ans = merge(ans, f[l++]);
            if (r & 1) 
                ans = merge(ans, f[--r]);
        }
        return ans;
    }

} st;


void run_case() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    st.build(n);
    while (q--) {
        int u, v; cin >> u >> v;
        debug(getLCA(u, v));
        cout << st.query(u, v) << "\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    while (Test--){

        run_case();
    }
}

