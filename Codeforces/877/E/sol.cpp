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


int n, q, timer = 0;
vector <int> child[MAX];
int c[MAX];
int st[MAX], en[MAX];

struct SegmentTree {
    int sz[MAX << 2];
    int f[MAX << 2];
    int lz[MAX << 2];

    void merge(int x) {
        sz[x] = sz[x << 1] + sz[x << 1 | 1];
        f[x] = f[x << 1] + f[x << 1 | 1];
    }

    void build(int x, int l, int r) {
        if (l == r) {
            sz[x] = 1;
            return;
        }
        int m = (l + r) >> 1;
        build(x << 1, l, m);
        build(x << 1 | 1, m + 1, r);
        merge(x);
    }

    void push(int x) {
        if (lz[x]) {
            f[x << 1] = sz[x << 1] - f[x << 1];
            f[x << 1 | 1] = sz[x << 1 | 1] - f[x << 1 | 1];
            lz[x << 1] ^= 1;
            lz[x << 1 | 1] ^= 1;

            lz[x] = 0;
        }
    }

    void update(int x, int l, int r, int u, int v, int val) {
        // hay o day
        if (l > v || r < u)
            return;
        if (u <= l && r <= v) {
            f[x] = sz[x] - f[x];
            lz[x] ^= val;
            return;
        }
        // o day
        push(x);
        int m = (l + r) / 2;
        update(x << 1, l, m, u, v, val);
        update(x << 1 | 1, m + 1, r, u, v, val);
        merge(x);
    }

    int query(int x, int l, int r, int u, int v) {
        if (l > v || r < u)
            return 0;
        if (u <= l && r <= v)
            return f[x];
     
        push(x);
        int m = (l + r) / 2;
        int L = query(x << 1, l, m, u, v);
        int R = query(x << 1 | 1, m + 1, r, u, v);
        return L + R;
    }
} ST;

void dfs(int u, int p) {
    st[u] = ++timer;
    for (int v : child[u]) {
        if (v == p)
            continue;
        dfs(v, u);
    }
    en[u] = timer;
}

void run_case() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        child[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    dfs(1, 0);
    ST.build(1, 1, n);  
    for (int i = 1; i <= n; i++) {
        if (c[i])
            ST.update(1, 1, n, st[i], st[i], 1);
    }

    cin >> q;
    while (q--) {
        string cmd;
        int u;
        cin >> cmd >> u;
        if (cmd[0] == 'p') {
            ST.update(1, 1, n, st[u], en[u], 1);
        }
        else {
            cout << ST.query(1, 1, n, st[u], en[u]) << "\n";
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

