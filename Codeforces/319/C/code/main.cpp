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
        Line(ll _a, ll _b) : a(_a), b(_b) {};
        ll cal(ll x) { return a * x + b; }
        double cross(Line o) { return (double) (b - o.b) / (double) (o.a - a); }
    };

    deque <Line> q;
    void add(ll a, ll b) {
        Line nLine(a, b);
        while (q.size() >= 2 && q[0].cross(nLine) <= q[0].cross(q[1]))
            q.pop_front();
        q.push_front(nLine);
    }
    ll qry(ll x) {
        int l = 0, r = q.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (q[m].cal(x) > q[m + 1].cal(x))
                l = m + 1;
            else
                r = m;
        }
        return q[l].cal(x);
    }
};

ll dp[MAX];
int n, a[MAX], b[MAX];
void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    // As, b(n) is guaranteed to = 0, we want to reach n with as minimum cost as possible
    // dp(i) : min(dp(j) + a[i] * b[j]);
    // as b is decreasing, obviously we should choose j close to i (which implies the j with maximum id)
    CHT hull;
    hull.add(b[1], 0);
    for (int i = 2; i <= n; ++i) {
        dp[i] = hull.qry(a[i]);
        hull.add(b[i], dp[i]);
        // debug(i);
        // REP(k, hull.q.size()) {
        //     debug(hull.q[k].a, hull.q[k].b);
        // }
    }
    cout << dp[n] << "\n";
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
