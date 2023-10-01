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
const int MAX = 1e5 + 5;

struct DSU {
    int *rk, *p;
    int n;

    void init (int N) {
        this->n = N;
        rk = new int[N + 1];
        p = new int[N + 1];
        for (int i = 0; i <= N; i++) rk[i] = 0, p[i] = i;
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
        if (rk[u] == rk[v])
            rk[u]++;
        p[v] = u;
        return 1;
    }
};

struct Edge {
    int u, v, t;
} e[MAX];

int n, m;
int a[MAX], b[MAX];
DSU dsu;
bool keep[MAX];

void reset () {
    cin >> n >> m;
    for (int i = 0; i <= m; i++)
        keep[i] = 0;

    dsu.init(n);
    for (int i = 1; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> b[i];
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].t;
}

void run_case() {
    reset();

    dsu.init(n);
    int X = 0;
    // take maximum edges from a;
    for (int i = 1; i <= m; i++) {
        if (e[i].t == 1) 
            X += dsu.join(e[i].u , e[i].v);
    }

    dsu.init(n);
    int Y = 0;
    // take maximum edges from b;
    for (int i = 1; i <= m; i++) {
        if (e[i].t == 2) 
            Y += dsu.join(e[i].u , e[i].v);
    }

    int x = -1;
    int val = 2 * INF;
    for (int i = max(0, n - 1 - Y); i <= min(X, n - 1); i++) {
        if (a[i] + b[n - 1 - i] < val) {
            x = i;
            val = a[i] + b[n - 1 - i];
        }
    }
    // x : maximum edge if take from a to make the minimum cost
    // find must-have edge from A of MST.
    for (int i = 1; i <= m; i++) {
        if (e[i].t == 1) {
            keep[i] = dsu.join(e[i].u, e[i].v);
        }
    }

    dsu.init(n);
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (keep[i] && e[i].t == 1)
            cnt += dsu.join(e[i].u, e[i].v);
    }
    // take x - cnt edge from A
    for (int i = 1; i <= m && cnt < x; i++) {
        if (e[i].t == 1 && !keep[i]) {
            int add = dsu.join(e[i].u, e[i].v );
            cnt += add;
            keep[i] = add;
        }
    }
    // take the rest from B
    for (int i = 1; i <= m; i++) {
        if (e[i].t == 2 && !keep[i]) {
            keep[i] = dsu.join(e[i].u, e[i].v );
        }
    }

    for (int i = 1; i <= m; i++) 
        if (keep[i])
            cout << i << " ";
    cout << "\n";
}   

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

