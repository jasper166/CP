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
    int *p, *res;
    int n;
    vector <set <int>> child;
    DisjointSets (int N) {
        child.assign(N + 1, set <int> ());
        p = new int[N + 1];
        res = new int[N + 1];
        this->n = N;
        for (int i = 1; i <= N; i++) {
            p[i] = i;
            res[i] = -1;
            child[i].insert(i);
        }

    }

    int get (int u) {
        // debug(u);
        return (u == p[u]? u : p[u] = get(p[u]));
    }

    void unite (int u, int v, int time) {
        u = get(u);
        v = get(v);
        if (u == v)
            return;
        if (u > v)
            swap(u, v);
        
        // if drop from the leader monkey
        if (u == 1){
            for (auto &c : child[v])
                res[c] = time;
        }
        else {
            //debug(u, v, time);
            for (auto &c : child[v])
                child[u].insert(c);
            // sort(all(child[u]));
            // child[u].resize(unique(child[u].begin(), child[u].end()) - child[u].begin());
        }
        p[v] = u;
    }
};

int n, m;

void run_case(){
    cin >> n >> m;
    vector <pii> edge(n + 1), drop(m + 1);
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        edge[i] = {l, r};
    }

    vector <pii> remove = edge;
    debug(remove);
    for (int i = 0; i < m; i++) {
        int p, h;
        cin >> p >> h;
        drop[i] = {p, h};
        if (h == 1)
            remove[p].fi = -1;
        else 
            remove[p].se = -1;
    }
    DisjointSets dsu(n);
    // dsu.unite(1, 2, -1);
    // build graph
    for (int u = 1; u <= n; u++) {
        auto [l, r] = remove[u];
        //debug(l, r);
        if (l != -1)
            dsu.unite(u, l, -1);
        if (r != -1)
            dsu.unite(u, r, -1);
    }

    for (int time = m - 1; time >= 0; time--) {
        auto& [u, h] = drop[time];
        int v = (h == 1)? edge[u].fi : edge[u].se;
        dsu.unite(u, v, time);
    }
    for (int i = 1; i <= n; i++) 
        cout << dsu.res[i] << "\n";
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

