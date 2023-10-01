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
const int MAX = 1e6 + 5;

int n, m;
struct DisjointSets {
    int *rk, *p;
    int n, comp;
    void init(int N) {
        n = comp = N;
        rk = new int[n + 2];
        p = new int[n + 2];
        for (int i = 1; i <= n; i++) {
            rk[i] = 0;
            p[i] = i;
        }
    }

    int get(int u) {
        return(u == p[u]? u : p[u] = get(p[u]));
    }

    bool join(int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v)
            return 0;
        if (rk[v] > rk[u]) swap(u, v);
        if (rk[u] == rk[v])
            rk[u]++;
        p[v] = u;
        comp--;
        return 1;
    }

} dsu;


void run_case() {
    cin >> n >> m;
    dsu.init(n);
    for (int i = 1; i <= m; i++) {
        int x, y, z; cin >> x >> y >> z;
        dsu.join(x, y);
    }
    cout << dsu.comp << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
/*
    properties: for each (x, y, z):
    if z even:
        + a(x) + a(y) even -> a(x) = a(y);
    if z odd:    
        + a(x) + a(y) odd -> a(x) = 3 - a(y);
    -> or if we know each a(x) or a(y) we can determine the other 
    Generalize, if we know a value of a set {x1, x2, x3, ...} we can determine the rest
    -> Counting graph component

*/


