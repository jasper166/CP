#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

struct CHT {
    struct Line {
        ll a, b;
        Line (ll _a = 0, ll _b = 0) { a = _a; b = _b; };
        ll cal(ll x) { return a * x + b; }
        long double cross(Line o) { return (long double) (b - o.b) / (long double) (o.a - a); }
    };

    Line q[MAX];

    struct Pre {
        int pos, top;
        Line past;
        Pre (int a, int b, Line c) : pos(a), top(b), past(c) {};
    };

    vector <Pre> undo;
    int top;

    void add(ll a, ll b) {
        Line nLine(a, b);
        int pos = top + 1;
        int l = 2, r = top;
        while (l <= r) {
            int m = (l + r) / 2;
            if (q[m - 1].cross(nLine) <= q[m - 1].cross(q[m])) {
                pos = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }

        undo.push_back({pos, top, q[pos]});
        q[pos] = nLine;
        top = pos;
    }

    void roll_back() {
        if (undo.empty()) return;
        Pre x = undo.back(); undo.pop_back();
        top = x.top;
        q[x.pos] = x.past;
    }

    ll qry(ll x) {
        int l = 1, r = top;
        ll ans = q[l].cal(x);
        while (l < r) {
            int m = (l + r) / 2;
            ll lhs = q[m].cal(x);
            ll rhs = q[m + 1].cal(x);
            if (lhs > rhs)
                l = m + 1;
            else
                r = m;
            ans = min({ans, lhs, rhs});
        }
        return ans;
    }
} hull;


int n;
int s[MAX], v[MAX];
ll dp[MAX];
ll dep[MAX];
vector <pii> adj[MAX];

void dfs(int u, int p) {
//    debug(u, p);
    for (auto [w, x] : adj[u]) {
        if (x ^ p) {
            dep[x] = dep[u] + w;
            dp[x] = hull.qry(v[x]) + dep[x] * v[x] + s[x];
            hull.add(-dep[x], dp[x]);

            dfs(x, u);
            hull.roll_back();
        }
    }
}

void run_case() {
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    for (int i = 2; i <= n; ++i) cin >> s[i] >> v[i];
    hull.add(0, 0);
    dfs(1, 0);
    for (int i = 2; i <= n; ++i) cout << dp[i] << " \n"[i == n];
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
