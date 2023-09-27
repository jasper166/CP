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
const int MAX = 2e5 + 5;

struct CHT {
    struct Line {
        ll a, b;
        Line (ll _a, ll _b) {
            a = _a;
            b = _b;
        }
        ll cal(ll x) { return (a * x + b); };
        ll cross(Line o) { return (long double) (b - o.b) / (long double) (o.a - a); };
    };

    deque <Line> q;
    void add(ll a, ll b) {
        Line nLine = Line(a, b);
        while (q.size() >= 2 && q[0].cross(nLine) >= q[0].cross(q[1]))
            q.pop_front();
        q.push_front(nLine);
    }

    ll qry(ll x) {
        int l = 0, r = q.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (q[mid].cross(q[mid + 1]) < x)
                l = mid + 1;
            else
                r = mid;
        }
        return q[l].cal(x);
    }
};

int n;
int a[MAX];
ll f[MAX], g[MAX], dp[MAX];
//ll dp[MAX];
void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
        g[i] = g[i - 1] + 1ll * i * a[i];
    }
    CHT hull;
//    hull.add(-1ll * a[1], 0);
    ll ans = 0;
    for (int x = 1; x <= n; ++x) {
        hull.add(-1ll * x, 1ll * (x - 1) * f[x - 1] - g[x - 1]);
        ans = max(ans, hull.qry(f[x]) + f[x] + g[x]);

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

