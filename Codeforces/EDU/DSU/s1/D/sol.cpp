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
    DisjointSets (int N){
        this->n = N;
        sz = new int[N + 1];
        p = new int[N + 1];
        for (int i = 1; i <= n; i++) {
            sz[i] = 1;
            p[i] = i;
        }
    }

    int get (int u) {
        return (u == p[u]? u : p[u] = get(p[u]));
    }

    bool same_sets (int u, int v) {
        return (get(u) == get(v));
    }
    void unite (int u, int v) {
        u = get(u);
        v = get(v);
        if (sz[v] > sz[u])
            swap(u, v);
        p[v] = u;
        sz[u] += sz[v];
    }

};
struct Query{
    string s;
    int u, v;
};

int n, m, q;
Query *query;

void run_case(){
    cin >> n >> m >> q;
    DisjointSets dsu(n);
    query = new Query[q + 1];

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
    }
    
    for (int i = 1; i <= q; i++)
        cin >> query[i].s >> query[i].u >> query[i].v;

    vector <string> ans;
    for (int Q = q; Q >= 1; Q--) {
        auto [s, u, v] = query[Q];
        if (s[0] == 'a') {
            if (dsu.same_sets(u, v))
                ans.push_back("YES");
            else 
                ans.push_back("NO");
        }
        else 
            dsu.unite(u, v);
    }
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

