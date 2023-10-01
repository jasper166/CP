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

int n, m, x;

struct DSU {
    int pa[MAX], sz[MAX];
    int n;
    void init(int N) {
        n = N;
        for (int i = 1; i <= n; i++) {
            sz[i] = 1;
            pa[i] = i;
        }
    }
    int get(int u) {
        return (u == pa[u]? u : pa[u] = get(pa[u]));
    }

    bool unite(int u, int v) {  
        u = get(u);
        v = get(v);
        if (u == v)
            return 0;
        if (sz[u] < sz[v])
            swap(u, v);
        sz[u] += sz[v];
        pa[v] = u;
        return 1;
    }
} dsu;

void run_case() {
    cin >> n >> m >> x;
    dsu.init(n);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
    }
    vector <int> comp;
    for (int u = 1; u <= n; u++) {
        if (u != x && dsu.get(x) != dsu.get(u))
            comp.push_back(u);
    }
    for (int v : comp) cout << v << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

