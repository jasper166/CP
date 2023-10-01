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
#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

struct Query {
    char cmd;
    int id, u, w;
}query[MAX];

struct Edge {
    int u, v;
}e[MAX];

int n, m, q;
bool del[MAX];
priority_queue <pair <ll, int>> Q;

struct DisjointSets {
    int *rk, *p;
    ll *res;
    int n;
    DisjointSets (int N) {
        this->n = N;
        p = new int[N + 1];
        rk = new int[N + 1];
        res = new ll[N + 1];
        for (int i = 1; i <= n; i++) {
            rk[i] = res[i] = 0;
            p[i] = i;
        }
    }

    int get (int u) {
        return (u == p[u]? u : p[u] = get(p[u]));
    }

    bool unite (int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v) 
            return 0;
        if (rk[v] > rk[u])
            swap(u, v);
        if (rk[u] == rk[v])
            rk[u]++;
        p[v] = u;
        res[u] += res[v];
        res[v] = 0;
        Q.emplace(res[u], u);
        return 1;
    }
};

void run_case(){
    cin >> n >> m >> q;
    DisjointSets dsu(n);

    for (int i = 1; i <= n; i++) {
        cin >> dsu.res[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v;
    }

    for (int i = 1; i <= q; i++) {
        char cmd = '$';
        int id = -1, u = 0, w = 0;
        cin >> cmd;
        if (cmd == 'D') {
            cin >> id;
            del[id] = 1;
        }
        else {
            cin >> u >> w;
            int cur = dsu.res[u];
            dsu.res[u] = w;
            w -= cur;
        }
        query[i] = {cmd, id, u, w};
    }

    for (int i = 1; i <= n; i++)
        Q.emplace(dsu.res[i], i);

    for (int i = 1; i <= m; i++) {
        if (!del[i]) {
            dsu.unite (e[i].u, e[i].v);
        }
    }
 
    vector <int> res;
    for (int i = q; i >= 1; i--) {
        auto [cmd, id, u, w] = query[i];
        while (!Q.empty() && Q.top().fi != dsu.res[Q.top().se])
            Q.pop();
        res.emplace_back(Q.top().fi);

        if (cmd == 'D') {
            dsu.unite(e[id].u, e[id].v);
        }

        else {
            int root = dsu.get(u);
            dsu.res[root] -= w; 
            Q.emplace(dsu.res[root], root);
        }
    }


    reverse(all(res));
    for (auto x : res) {
        cout << x << "\n";
    }
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

