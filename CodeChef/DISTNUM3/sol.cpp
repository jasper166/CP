#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

// Mo's with update: BLOCK = n ^ (2 / 3)
const int BLOCK = 2155;
const int N = 1e5 + 5;
const int K = 18;

int n, q;
int c[N];
vector <int> adj[N];

int tin[N], tout[N];
int timer = 0;
int dep[N], up[K][N];
int tree[N << 1];

void dfs(int u, int p) {
    tin[u] = ++timer;
    tree[timer] = u;

    for (int v : adj[u]) {
        if (v == p) continue;
        up[0][v] = u;
        dep[v] = dep[u] + 1;
        for (int k = 1; k < K; ++k)
            up[k][v] = up[k - 1][up[k - 1][v]];
        dfs(v, u);
    }
    tout[u] = ++timer;
    tree[timer] = u;
}

int lca(int u, int v) {
    if (dep[u] != dep[v]) {
        if (dep[u] < dep[v]) swap(u, v);
        int k = dep[u] - dep[v];
        for (int i = K - 1; i >= 0; --i) 
            if (k & (1 << i))
                u = up[i][u]; 
    }
    if (u == v) return u;
    for (int i = K - 1; i >= 0; --i) {
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}

struct Query {
    int l, r, id, pa;
    bool operator < (const Query& ot) const {
        if (l / BLOCK != ot.l / BLOCK)
            return l < ot.l;
        if (r / BLOCK != ot.r / BLOCK)
           return r < ot.r;
        return id < ot.id;
    }

};
vector <Query> queries;

bool vis[N];
int cnt[N * 10];
int ans[N];
int res;

void add(int i) {
    int u = tree[i];
    vis[u] ^= 1;
    if (vis[u]) {
        cnt[c[u]]++;
        if (cnt[c[u]] == 1) ++res;
    }

    else {
        cnt[c[u]]--;
        if (cnt[c[u]] == 0) --res;
    }
}

void del(int i) {
    int u = tree[i];
    vis[u] ^= 1;
    if (vis[u]) {
        cnt[c[u]]++;
        if (cnt[c[u]] == 1) ++res;
    }

    else {
        cnt[c[u]]--;
        if (cnt[c[u]] == 0) --res;
    }
}


int prv[N];
int qt[N], qx[N], qy[N];

signed main() {

    cin.tie(0) -> sync_with_stdio(0);

    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif



    cin >> n >> q;
    vector <int> vals;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        vals.push_back(c[i]);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= q; ++i) {
        cin >> qt[i] >> qx[i] >> qy[i];
        if (qt[i] == 2) vals.push_back(qy[i]);
    }

    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());

    for (int i = 1; i <= n; ++i)
        c[i] = (int) (lower_bound(vals.begin(), vals.end(), c[i]) - vals.begin()) + 1;

    for (int i = 1; i <= q; ++i)
        if (qt[i] == 2)
            qy[i] = (int) (lower_bound(vals.begin(), vals.end(), qy[i]) - vals.begin()) + 1;

    dfs(1, 0);



    vector <int> ups;
    for (int i = 1; i <= q; ++i) {
        int cmd = qt[i];
        if (cmd == 1) {
            if (tin[qx[i]] > tin[qy[i]]) swap(qx[i], qy[i]);
            int u = qx[i];
            int v = qy[i];
            int p = lca(u, v);
            int L, R;
            if (p == u) {
                L = tin[u];
                R = tin[v];
            }
            else {
                L = tout[u];
                R = tin[v];
            }
            queries.push_back({L, R, i, p});
        }
        else
            ups.push_back(i);
    }

    sort(queries.begin(), queries.end());
    int l = 1, r = 0, t = -1;
    for (int i = 0; i < (int) queries.size(); ++i) {
        auto [L, R, id, p] = queries[i];
        // debug(T, L, R, id, p);
        while (l > L) add(--l);
        while (r < R) add(++r);
        while (l < L) del(l++);
        while (r > R) del(r--);
        while (t + 1 < (int) ups.size() && ups[t + 1] < id) {
            ++t;
            int x = qx[ups[t]];
            int y = qy[ups[t]];
            if (vis[x]) {
                --cnt[c[x]];
                if (cnt[c[x]] == 0) --res;
                ++cnt[y];
                if (cnt[y] == 1) ++res;
            }
            prv[t] = c[x];
            c[x] = y;
        }

        while (t >= 0 && ups[t] > id) {
            int x = qx[ups[t]];
            int y = prv[t];
            if (vis[x]) {
                --cnt[c[x]];
                if (cnt[c[x]] == 0) --res;
                ++cnt[y];
                if (cnt[y] == 1) ++res;
            }
            c[x] = y;
            --t;
        }

        ans[id] = res;
        if (p && cnt[c[p]] == 0) ++ans[id];
    }
    for (int i = 1; i <= q; ++i) {
        if (qt[i] == 1) 
            cout << ans[i] << "\n";
    }

}



