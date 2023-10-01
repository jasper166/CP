#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e3 + 5;

struct DisjointSets {
    int n;
    vector <int> sz, pa;
    DisjointSets(int _n) {
        n = _n;
        sz.resize(n + 5); pa.resize(n + 5);
        for (int i = 1; i <= n; ++i) {
            sz[i] = 1;
            pa[i] = i;
        }
    }
    int get(int u) { return (pa[u] == u? u : pa[u] = get(pa[u])); }
    bool unite(int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v) return 0;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        pa[v] = u;
        return 1;
    }
};

int n;
int a[N];
bool isConnected() {
    int c = n;
    DisjointSets dsu(n);
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) return 0;
        for (int j = i + 1; j <= n; j++) {
            if (a[i] & a[j])
                c -= dsu.unite(i, j);
        }
    }
    return (c == 1);
}

inline void giveAns(int x) {
    cout << x << "\n";
    for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
}
void run_case() {
    
    int C = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            C++;
            a[i]++;
        }
    }

    // Check if graph is connected
    if (isConnected()) {
        debug("1");
        giveAns(C);
        return;
    }   
    for (int i = 1; i <= n; ++i) {
        // a(i) + 1;
        a[i]++;
        if (isConnected()) {
            debug("2");
            giveAns(C + 1);
            return;
        }
        a[i]--;
        // a(i) - 1; 
        a[i]--;
        if (isConnected()) {
            debug("3");
            giveAns(C + 1);
            return;
        }
        a[i]++;
    }
    // Case 2;
    debug("4");
    int k = 0;
    for (int i = 1; i <= n; ++i) 
        k = max(k, a[i] & -a[i]);
    vector <pii> x;
    for (int i = 1; i <= n; ++i)
        if ((a[i] & -a[i]) == k)
            x.push_back({a[i], i});
    a[x[0].se]--;
    C++;
    if ((int) x.size() > 1) {
        C++;
        a[x[1].se]++;
    }
    giveAns(C);
}
 
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
