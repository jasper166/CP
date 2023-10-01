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
const int MAX = 2e4 + 5;

struct CHT {
    struct Line {
        ll a, b;
        Line (ll _a, ll _b) {
            a = _a;
            b = _b;
        }
        ll cal(ll x) { return a * x + b; }
        ll cross(Line o) { return (long double) (b - o.b) / (o.a - a); }
    };
    deque <Line> q;
    void add(ll a, ll b) {
        Line nLine = Line(a, b);
        while (q.size() >= 2 && q[0].cross(nLine) >= q[0].cross(q[1]))
            q.pop_front();
        q.push_front(nLine);
    }
    ll qry(int x) {
        int l = 0, r = q.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (q[m].cross(q[m + 1]) < x)
                l = m + 1;
            else
                r = m;
        }
        return q[l].cal(x);
    }
};


int n;
int d[MAX], w[MAX];
ll D[MAX], W[MAX];
void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> d[i];
        W[i] = W[i - 1] + w[i];
    }
    for (int i = n; i >= 1; --i) D[i] = D[i + 1] + d[i];

    ll cost = 0;
    for (int i = 1; i <= n; ++i) {
        cost += w[i] * D[i];
    }
//    debug(cost, W[3], D[3], W[6], D[6]);
    CHT hull;
    hull.add(0, 0);
    ll ans = LINF;
    for (int x = 1; x <= n; ++x) {
        ll cur = -hull.qry(D[x]) + cost - W[x] * D[x];
        hull.add(-W[x], W[x] * D[x]);
        ans = min(ans, cur);
    }
    cout << ans << "\n";
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
