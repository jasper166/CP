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


int st[MAX], en[MAX];
int val[MAX];
int timer = 0;
vector <int> adj[MAX];
int n, q;

struct FenwickTree {
    ll *f;
    int n;

    void update(int x, int v) {
        for (; x <= n; x += x & -x)
            f[x] += v;
    }

    ll get(int x) {
        ll ans = 0;
        for (; x; x -= x & -x)
            ans += f[x];
        return ans;
    }

    ll query(int l, int r) {
        return get(r) - get(l - 1);
    }
    void init(int N) {
        n = N;
        f = new ll[N + 1];
        fill(f, f + N, 0ll);
        for (int i = 1; i <= n; i++) 
            update(st[i], val[i]);
    }
} bit;

void dfs(int u, int p) {
    st[u] = ++timer;
    for (int v : adj[u]) {
        if (v == p)
            continue;
        dfs(v, u);
    }
    en[u] = timer;
}

void run_case() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) 
        cin >> val[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    bit.init(n);
    while (q--) {
        int op, u, x;
        cin >> op;
        if (op == 1) {
            cin >> u >> x;
            bit.update(st[u], x - val[u]);
            val[u] = x;
        }
        else {
            cin >> u;
            ll res = bit.query(st[u], en[u]);
            cout << res << "\n";
        }
    }
    debug(timer);
    FOR(i, 1, n) cout << st[i] << " ";
    cout << "\n";
    FOR(i, 1, n) cout << en[i] << " ";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

