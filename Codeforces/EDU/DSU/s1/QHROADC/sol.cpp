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

int n, m, q;
int N;

struct Edge {
    int u, v;
};

struct DisjointSets {
    int *sz, *p;
    int n;
    DisjointSets (int N) {
        this->n = N;
        p = new int[N + 1];
        sz = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            sz[i] = 1;
            p[i] = i;
        }
    }

    int get (int u) {
        return (u == p[u]? u : p[u] = get(p[u]));
    }

    void unite (int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v)
            return;
        if (sz[v] > sz[u])
            swap(u, v);
        sz[u] += sz[v];
        p[v] = u;
    }
};

Edge *e;
bool *d;
int *query;

void connect (Edge x, DisjointSets dsu) {
    if (dsu.get(x.u) != dsu.get(x.v)) {
        dsu.unite(x.u, x.v);
        N--;
    }
}

void run_case(){
    cin >> n >> m >> q;
    e = new Edge[m + 1];
    d = new bool[m + 1];
    query = new int[q + 1];

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[i] = {u, v};
        d[i] = 0;
    }

    for (int i = 1; i <= q; i++) {
        int x; cin >> x;
        d[x] = 1;
        query[i] = x;
    }
    N = n;
    DisjointSets dsu(n);

    for (int i = 1; i <= m; i++) {
        if (!d[i])
            connect(e[i], dsu);
    }
    debug(N);
    vector <int> ans;
    ans.push_back(N);
    for (int i = q; i >= 1; i--) {
        connect(e[query[i]], dsu);
        ans.push_back(N);
    }
    ans.pop_back();
    reverse(all(ans));
    for (auto x : ans) cout << x << "\n";
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

