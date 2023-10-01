#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

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
#define TASK "INP"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

struct DisjointSets {
    int *sz, *p;
    int n;
    DisjointSets (int N) {
        this->n = N;
        sz = new int[N + 1];
        p = new int[N + 1];
        for (int i = 1; i <= n; i++) sz[i] = 1, p[i] = i;
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
        sz[u] += sz[v];
        p[v] = u;
        return 1;
    }
};

struct Edge {
    int u, v, w, id;
    Edge (int u, int v, int w, int id) : u(u), v(v), w(w), id(id) {};
    bool operator < (const Edge &a) const {
        return (w > a.w);
    }
};
int n, m;
ll s;

void run_case(){
    cin >> n >> m >> s;
    vector <Edge> e;
    vector <bool> used(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e.emplace_back(u, v, w, i);
    }

    sort(all(e));
    DisjointSets dsu(n);
    for (auto &[u, v, w, id] : e) {
        if (dsu.join(u, v)) {
            used[id] = 1;
        }
    }
    // debug(mst);
    vector <int> res;
    for (int i = m - 1; i >= 0; i--) {
        if (!used[e[i].id] && s >= e[i].w) {
            res.push_back(e[i].id);
            s -= e[i].w;
        }
    }
    sort(all(res));
    cout << res.size() << "\n";
    for (auto &x : res) cout << x << " ";
    cout << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

