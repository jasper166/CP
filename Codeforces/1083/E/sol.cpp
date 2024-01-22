#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using pii = pair < int, int >;

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

#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

struct Rect {
    ll x, y, a;
    bool operator < (const Rect& o) const {
        return (x < o.x);
    }
} a[MAX];
int n;

struct Line {
    ll a, b;
    Line (ll _a, ll _b) {
        a = _a;
        b = _b;
    }
    ll cal(ll x) {
        return (a * x + b); 
    }
    long double cross(Line o) {
        return (long double) (b - o.b) / (o.a - a);
    }
};
// Query for max;
struct ConvexHull {
    deque <Line> q;
    void add(Line nLine) {
        while (q.size() >= 2 && q[q.size() - 1].cross(nLine) >= q[q.size() - 1].cross(q[q.size() - 2]))
            q.pop_back();
        q.push_back(nLine);
    }

    ll qry(ll x) {
        while (q.size() >= 2 && q[0].cal(x) <= q[1].cal(x))
            q.pop_front();
        return q[0].cal(x);
    }
};

/*
    f[j] = x(i) * y(i) - a[i] + max(f[j] - x[j] * y[i]) with j < i;
*/
ll f[MAX];
void run_case() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].a;
    }
    sort(a + 1, a + n + 1);

    ConvexHull cht;
    cht.add(Line(0, 0));
    ll bestF = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        debug(a[i].y);
        REP(k, cht.q.size()) {
            debug(cht.q[k].a, cht.q[k].b);
        }
        
        bestF = 1ll * a[i].x * a[i].y - a[i].a + cht.qry(a[i].y);
        ans = max(ans, bestF);
        cht.add(Line(-a[i].x, bestF));
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
