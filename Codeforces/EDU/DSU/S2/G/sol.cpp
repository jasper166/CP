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
    int *p, *sz, *mx;
    int n;
    DisjointSets (int N) {
        this->n = N;
        p = new int[n + 1];
        sz = new int[n + 1];
        mx = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            mx[i] = 0;
            sz[i] = 1;
        }
    }

    int get (int u) {
        return (u == p[u]? u : p[u] = get(p[u]));
    }

    bool join (int u, int v, int w) {
        u = get(u);
        v = get(v);
        if (u == v)
            return 0;
        if (sz[v] > sz[u])
            swap(u, v);
        p[v] = u;
        sz[u] += sz[v];
        mx[u] = mx[v] = max({w, mx[u], mx[v]});
        return 1;
    }
};

struct Edge {
    int u, v, w;
    Edge (int u, int v, int w) : u(u), v(v), w(w) {};

    bool operator < (const Edge &a) const {
        return (w < a.w);
    }
};
int n, m;
void run_case(){
    cin >> n >> m;
    vector <Edge> e;
    DisjointSets dsu(n);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e.emplace_back(u, v, w);
    }
    sort(all(e));
    int res = 0;
    for (auto &[u, v, w] : e) {
        if (dsu.join(u, v, w)) {
            res = max(res, w);
        }
    }
    cout << res << "\n";
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

