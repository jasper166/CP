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
const int MAX = 4e5 + 5;

int n, q;
vector <int> adj[MAX];
int c[MAX];

int tin[MAX], tout[MAX];
int timer = 0;

struct SegmentTree {
    ll f[MAX << 2];
    ll lz[MAX << 2];

    void push(int x) {
        if (lz[x]) {
            f[x << 1] = lz[x];
            f[x << 1 | 1] = lz[x];
            lz[x << 1] = lz[x];
            lz[x << 1 | 1] = lz[x];

            lz[x] = 0;
        }
    }

    ll merge(ll l, ll r) {
        return (l | r);
    }

    void build(int x, int l, int r) {
        if (l == r) {
            f[x] = 1ll << c[l];
            return;
        }

        int m = (l + r) / 2;
        build(x << 1, l, m);
        build(x << 1 | 1, m + 1, r);
        f[x] = merge(f[x << 1], f[x << 1 | 1]);
    }

    void update(int x, int l, int r, int u, int v, int val) {
        if (l > v || r < u)
            return;
        if (u <= l && r <= v) {
            f[x] = 1ll << val;
            lz[x] = 1ll << val;
            return;
        }
        push(x);
        int m = (l + r) / 2;
        update(x << 1, l, m, u, v, val);
        update(x << 1 | 1, m + 1, r, u, v, val);
        f[x] = merge(f[x << 1], f[x << 1 | 1]);
    }

    ll query(int x, int l, int r, int u, int v) {
        if (l > v || r < u)
            return 0ll;
        if (u <= l && r <= v)
            return f[x];

        push(x);
        int m = (l + r) / 2;
        ll L = query(x << 1, l, m, u, v);
        ll R = query(x << 1 | 1, m + 1, r, u, v);
        return merge(L, R);
    }

} seg;

void dfs(int u, int p) {
    tin[u] = ++timer;
    for (int v : adj[u]) {
        if (v == p)
            continue;
        dfs(v, u);
    }
    tout[u] = timer;
}

void run_case() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (c[i])
            seg.update(1, 1, n, tin[i], tin[i], c[i]);
    }
    while (q--) {
        int cmd, u, x;
        cin >> cmd >> u;
        if (cmd == 1) {
            cin >> x;
            seg.update(1, 1, n, tin[u], tout[u], x);
        }
        else {
            ll res = seg.query(1, 1, n, tin[u], tout[u]);
            cout << __builtin_popcountll(res) << "\n";
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

