#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 2e5 + 5;
const int K = 20;

int n, m, q;
int a[N];
vector <int> adj[N];
// Euler-tour LCA
int tin[N], dep[N], tree[N << 1], lg[N << 1];
pair <int, int> up[K][N << 1];
int timer = 0;

void dfs(int u, int p) {
    tree[++timer] = u;
    tin[u] = timer;
    for (int v : adj[u]) {
        if (v ^ p) {
            dep[v] = dep[u] + 1;
            dfs(v, u);
            tree[++timer] = u;
        }
    }
}
void prepare() {
    dfs(1, 0);

    lg[1] = 0;
    for (int i = 2; i <= timer; ++i) lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= timer; ++i)
        up[0][i] = {dep[tree[i]], tree[i]};
    for (int k = 1; k < K; ++k) {
        int step = 1 << (k - 1);
        for (int i = 1; i + step <= timer; ++i)
            up[k][i] = min(up[k - 1][i], up[k - 1][i + step]);
    }
}
int lca(int u, int v) {
    int l = tin[u], r = tin[v];
    if (l > r) swap(l, r);
    int k = lg[r - l + 1];
    return min(up[k][l], up[k][r - (1 << k) + 1]).second;
}
// End of LCA

set <int> same[N], diff[N];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> m >> q;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    prepare();
    for (int i = 1; i <= m; ++i) cin >> a[i]; 

    for (int i = 1; i <= m; ++i)
        same[a[i]].insert(i);
    for (int i = 1; i < m; ++i) {
        int p = lca(a[i], a[i + 1]);
        diff[p].insert(i);
    }

    for (int _q = 1; _q <= q; ++_q) {
        int cmd, x, y, u;
        cin >> cmd >> x >> y;

        // debug(cmd, x, y);
        if (cmd == 1) {
            same[a[x]].erase(x);
            if (2 <= x) {
                int p = lca(a[x], a[x - 1]);
                diff[p].erase(x - 1);
            }
            if (x < m) {
                int p = lca(a[x], a[x + 1]);
                diff[p].erase(x);
            }
            
            a[x] = y;

            same[a[x]].insert(x);
            if (2 <= x) {
                int p = lca(a[x], a[x - 1]);
                diff[p].insert(x - 1);
            }
            if (x < m) {
                int p = lca(a[x], a[x + 1]);
                diff[p].insert(x);
            }
        }
        else {
            cin >> u;   
            // debug(u, ":", same[u], ":", diff[u]);
            pair <int, int> ans = {-1, -1};
            // On the same branch
            auto it_s = same[u].lower_bound(x);
            // On two separated branch
            auto it_d = diff[u].lower_bound(x);
            if (it_s != same[u].end() && *it_s <= y) {
                ans = make_pair(*it_s, *it_s);
            }
            else if (it_d != diff[u].end() && *it_d + 1 <= y) {
                ans = make_pair(*it_d, *it_d + 1);
            }
            cout << ans.first << " " << ans.second << "\n";
        }
    }  
}


