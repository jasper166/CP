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
const int MAX = 5e4 + 5;


int n, m;
int id, comp;
ll res;
struct Edge {
    int u, v, w;
    bool operator < (const Edge x) const {
        return (w < x.w);
    }
}e[MAX];


struct DSU {
    int *sz, *p;
    int n;

    void init (int N) {
        n = N;
        sz = new int[N + 1];
        p = new int[N + 1];
        for (int i = 1; i <= n; i++) sz[i] = 0, p[i]= i;
    }

    int get (int u) {
        return (u == p[u]? u : p[u] = get(p[u]));
    }  

    bool join (int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v)
            return 0;
        if (sz[u] < sz[v])
            swap(u, v);
        p[v] = u;
        sz[u] += sz[v];
        return 1;
    }
} dsu;

vector <Edge> mst;
void Kruskal () {

    comp = n;
    res = 0LL;
    
// sort mst vector (optimal)
    for (int i = (int) mst.size() - 1; i >= 1; i--) {
        if (mst[i].w < mst[i - 1].w)
            swap(mst[i], mst[i - 1]);
    }
    dsu.init(n);
    vector <Edge> nx_mst;
    for (auto& [u, v, w] : mst) {
        if (dsu.join(u, v)) {
            res += 1LL * w;
            comp--;
            nx_mst.push_back({u, v, w});
        }
    }
    mst = nx_mst;
}


void run_case() {
    cin >> n >> m;
    for (id = 1; id <= m; id++) {
        int u, v, w;
        cin >> u >> v >> w;
        mst.push_back({u, v, w});
        Kruskal();
        cout << ((comp == 1)? res : -1) << "\n";
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

