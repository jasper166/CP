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
    int n;
    int *sz, *p, *f, *nf;

    void init (int N) {
        this->n = N;
        sz = new int[N + 1];
        p = new int[N + 1];
        f = new int[N + 1];
        nf = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            sz[i] = 1;
            p[i] = i;
            f[i] = nf[i] = 0;
        }
    }

    int get (int u) {
        return (u == p[u]? u : get(p[u]));
    }

    void join (int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v)
            return;
        if (sz[v] > sz[u])
            swap(u, v);
        sz[u] += sz[v];
        p[v] = u;
        nf[v] = f[u];
    }

    void add (int u, int val) {
        u = get(u);
        f[u] += val;
    }
    int query (int u) {
        return (u == p[u]? f[u] : (f[u] - nf[u] + query(p[u])));
    }
};

int n, q;
void run_case(){
    cin >> n >> q;
    DisjointSets DSU;
    DSU.init(n);
    while (q--) {
        string s;
        cin >> s;
        if (s == "add") {
            int u, val;
            cin >> u >> val;
            DSU.add(u, val);
        }
        else if (s == "join") {
            int u, v;
            cin >> u >> v;
            DSU.join(u, v);
        }
        else {
            int u; cin >> u;
            cout << DSU.query(u) << "\n";
        }
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


