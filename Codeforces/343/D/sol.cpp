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
const int MAX = 5e5 + 5;

int n, q;
vector <int> adj[MAX];
int pa[MAX];
int tin[MAX], tout[MAX];
int timer = 0;

struct SegmentTree {
    int f[MAX << 2], lz[MAX << 2];

    void push(int x) {
        if (lz[x]) {
            f[x << 1] = 1;
            f[x << 1 | 1] = 1;
            lz[x << 1] = 1;
            lz[x << 1 | 1] = 1;
            lz[x] = 0;
        }
    }

    void pull(int x) {
        f[x] = f[x << 1] & f[x << 1 | 1];
    }

    void update(int x, int l, int r, int u, int v, int type) {
        if (l > v || r < u)
            return;
        if (u <= l && r <= v) {
            f[x] = type & 1;
            if (type == 1)
                lz[x] = 1;
            return;
        }
        push(x);
        int m = (l + r) / 2;
        update(x << 1, l, m, u, v, type);
        update(x << 1 | 1, m + 1, r, u, v, type);
        pull(x);
    }

    int query(int x, int l, int r, int u, int v) {
        if (l > v || r < u)
            return 1; // do k phu thuoc khoang nay nen return 1;
        if (u <= l && r <= v)
            return f[x];
        push(x);
        int m = (l + r) / 2;
        int ql = query(x << 1, l, m, u, v);
        int qr = query(x << 1 | 1, m + 1, r, u, v);
        return (ql & qr);
    }
} seg;


void dfs(int u, int p) {
    pa[u] = p;
    tin[u] = ++timer;
    for (int v : adj[u]) {
        if (v != p)
            dfs(v, u);
    }
    tout[u] = timer;
}

void run_case() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cin >> q;
    while (q--) {
        int cmd, u; cin >> cmd >> u;
        if (cmd == 1) {
            if (seg.query(1, 1, n, tin[u], tout[u]) == 0 && pa[u] != 0)
                seg.update(1, 1, n, tin[pa[u]], tin[pa[u]], 0);
            seg.update(1, 1, n, tin[u], tout[u], 1);
        }
        else if (cmd == 2) {
            seg.update(1, 1, n, tin[u], tin[u], 0);
        }
        else {
            cout << seg.query(1, 1, n, tin[u], tout[u]) << "\n";
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

