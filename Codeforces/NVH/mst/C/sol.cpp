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
#define debug(...) 42
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e2 + 5;

struct Edge {
    int u, v, w;
    bool operator < (const Edge x) const {
        return (w < x.w);
    }
};

struct DSU {
    int *sz, *p;
    int n;
    void init (int N) {
        this->n = N;
        sz = new int[N + 1];
        p = new int[N + 1];
        for (int i = 1; i <= n; i++) sz[i] = 0, p[i] = i;
    }

    int get (int u) {
        return (u == p[u]? u : p[u] = get(p[u]));
    }

    bool join (int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v)
            return 0;
        if (sz[v] > sz[u])
            swap(u, v);
        sz[u] += sz[v];
        p[v] = u;
        return 1;
    }

    bool sameComp (int u, int v) {
        return (get(u) == get(v));
    }
} dsu;

int n, k;
int c[MAX][MAX];

void run_case() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> c[i][j];
    }

    vector <Edge> e;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            e.push_back({i, j, c[i][j]});
        }
    }
    sort(all(e));
    int sz = e.size();
    vector <bool> used(sz, 0);

    int comp = n;
    dsu.init(n);
    for (int i = 0; i < sz; i++) {
        // leave the rest makes up to K components;
        if (comp == k)
            break;
        auto [u, v, w] = e[i];
        if (dsu.join(u, v)) {
            comp--;
            used[i] = 1;
        }
    }
    int res = INF;
    for (int i = 0; i < sz; i++) {
        auto [u, v, w] = e[i];
        if (dsu.sameComp(u, v))
            continue;
        res = min(res, e[i].w);
    }
    cout << res << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

