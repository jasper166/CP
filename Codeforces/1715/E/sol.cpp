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
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

struct LiChaoTree {
    struct Line {
        ll a, b;
        Line(ll _a = 0, ll _b = INF) : a(_a), b(_b) {};
        ll cal(ll x) { return a * x + b; }
    };

    int n;
    vector <Line> f;
    void init(int _n) {
        n = _n;
        f.resize(4 * n + 5);
    }

    void add(int x, int l, int r, Line line) {
        if (l == r) {
            if (f[x].cal(l) > line.cal(l)) 
                f[x] = line;
            return;
        }
        int m = (l + r) >> 1;
        // Current line always has smaller slope
        if (line.a > f[x].a) swap(line, f[x]);
        if (f[x].cal(m) > line.cal(m)) {
            swap(line, f[x]);
            add(x << 1, l, m, line);
        }
        else
            add(x << 1 | 1, m + 1, r, line);
    }

    ll qry(int x, int l, int r, int p) {
        ll ans = f[x].cal(p);
        if (l == r) return ans;
        int m = (l + r) >> 1;
        if (p <= m) return min(ans, qry(x << 1, l, m, p));
        else return min(ans, qry(x << 1 | 1, m + 1, r, p));
    }

    void add(ll a, ll b) { add(1, 1, n, Line(a, b)); }
    ll qry(int x) {return qry(1, 1, n, x); }
};

vector <pii> adj[N];
int n, m, k;
ll dp[N];

void dijkstra() {
    priority_queue <pii, vector <pii>, greater <pii>> q;
    for (int u = 1; u <= n; ++u)
        q.push({dp[u], u});
    while (!q.empty()) {
        auto [du, u] = q.top(); q.pop();
        if (du > dp[u]) continue;
        for (auto [w, v] : adj[u]) {
            if (dp[v] > dp[u] + w) {
                dp[v] = dp[u] + w;
                q.push({dp[v], v});
            }
        }
    }
}

void run_case() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    // O(k * nlogm);
    for (int i = 1; i <= n; ++i) dp[i] = INF;
    dp[1] = 0;
    dijkstra();
    
    // dp(v) = min u : dp(u) + (u - v)^2
    // dp(v) = dp(u) + u^2 - 2*u*v + v^2
    LiChaoTree lc;
    for (int i = 1; i <= k; ++i) {
        lc.init(n);
        for (int u = 1; u <= n; ++u)
            lc.add(-2ll * u, dp[u] + 1ll * u * u);
        for (int v = 1; v <= n; ++v)
            dp[v] = lc.qry(v) + 1ll * v * v;
        dijkstra();
    }

    for (int u = 1; u <= n; ++u)
        cout << dp[u] << " \n"[u == n];
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
