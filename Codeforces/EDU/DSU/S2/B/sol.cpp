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
    int *p, *sz;
    int n;
    DisjointSets (int N) {
        this->n = N;
        p = new int[N + 1];
        sz = new int[N + 1];
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
    }

    int get (int u) {
        return (u == p[u]? u : p[u] = get(p[u]));
    }

    bool unite (int u, int v) {
        u = get(u);
        v = get(v);
        // debug(u, v);
        if (u == v)
            return 0;
        p[u] = v;
        sz[v] += sz[u];
        return 1;
    }
};

int n;
void run_case(){
    cin >> n;
    DisjointSets dsu(n);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        x = dsu.get(x);
        cout << x << "\n"; 
        int nx = (x + 1) % (n + 1);
        dsu.unite(x, nx? nx : 1);
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

