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
#define debug(...) 42
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

struct Edge {
    int u, v, t;
} e[MAX];


struct DSU {
    int *rk, *p;
    int n;

    void init (int N) {
        n = N;
        rk = new int[N + 1];
        p = new int[N + 1];
        for (int i = 1; i <= N; i++) rk[i] = 0, p[i] = i;
    }

    int get (int u) {
        return (u == p[u]? u : p[u] = get(p[u]));
    }

    bool join (int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v)
            return 0;
        if (rk[u] < rk[v])
            swap(u, v);
        p[v] = u;
        if (rk[u] == rk[v])
            rk[u]++;
        return 1;
    }
} dsu;

int n, m, k;
bool keep[MAX];

void run_case() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].t;
    }

    dsu.init(n);
    int X = 0;
    for (int i = 1; i <= m; i++) {
        if (e[i].t == 0)
            X += dsu.join(e[i].u, e[i].v);
    }

    dsu.init(n);
    int Y = 0;
    for (int i = 1; i <= m; i++) {
        if (e[i].t == 1)
            Y += dsu.join(e[i].u, e[i].v);
    }
    
    if (Y < k || X < n - 1 - k) {
        cout << "-1\n";
        return;
    }

    for (int i = 1; i <= m; i++) {
        if (e[i].t == 0)
            keep[i] = dsu.join(e[i].u, e[i].v);
    }

    dsu.init(n);
    int x = 0;
    for (int i = 1; i <= m; i++) {
        if (keep[i])
            x += dsu.join(e[i].u, e[i].v);
    }

    for (int i = 1; i <= m && x < n - 1 - k; i++) {
        if (!keep[i] && e[i].t == 0) {
            if (dsu.join(e[i].u, e[i].v)) {
                keep[i] = 1;
                x++;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        if (e[i].t == 1)
            keep[i] = dsu.join(e[i].u, e[i].v);
    }

    for (int i = 1; i <= m; i++) {
        if (keep[i])
            cout << i << " ";
    }
    cout << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

