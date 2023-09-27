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

int n, q;
vector <int> adj[MAX];
vector <int> euler;
int st[MAX], en[MAX];
int val[MAX];
int timer = 0;


void dfs(int u, int p) {
    euler.push_back(u);
    st[u] = ++timer;
    for (int v : adj[u]) {
        if (v == p)
            continue;
        dfs(v, u);
    }
    en[u] = timer;
    euler.push_back(u);
}


struct SegTree {
    ll *f;
    int n;
    void init(int N) {
        n = N;
        f = new ll[N + 2];
        fill(f, f + n + 1, 0);
        for (int i = 1; i <= n; i++) {
            update(st[i], val[i]);
            update(en[i] + 1, -val[i]);
        }
    }
    void update(int x, int val) {
        for (; x <= n; x += x & -x)
            f[x] += val;
    }

    ll query(int x) {
        ll res = 0;
        for (; x; x -= x & -x)
            res += f[x];
        return res;
    }
} tree;



void run_case() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    tree.init(n);

    while (q--) {
        int cmd, u, x;
        cin >> cmd;
        if (cmd == 1) {
            cin >> u >> x;
            tree.update(st[u], x - val[u]);
            tree.update(en[u] + 1, -(x - val[u]));
            val[u] = x; 
        }
        else {
            cin >> u;
            cout << tree.query(st[u]) << "\n";
        }
    }
    debug(euler);
    // tree.build(timer);

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

