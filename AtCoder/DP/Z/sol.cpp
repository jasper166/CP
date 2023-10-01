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

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int n;
int a[MAX];
ll f[MAX];
ll c;
struct Line {
    ll a, b;
    Line (ll _a, ll _b) {
        a = _a;
        b = _b;
    }
    ll cal(ll x) {
        return (a * x + b);
    }

    long double cross (Line o) {
        return (long double) (b - o.b) / (o.a - a);
    }
};

struct CHT {
    deque <Line> q;
    void add(Line nLine) {
        while (q.size() >= 2 && q[q.size() - 2].cross(nLine) <= q[q.size() - 2].cross(q[q.size() - 1]))
            q.pop_back();
        q.push_back(nLine);
    }

    ll qry(ll x) {
        while (q.size() >= 2 && q[0].cal(x) >= q[1].cal(x))
            q.pop_front();
        return q[0].cal(x);
    }
};

// slope is decreasing, qry is increasing
void run_case() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    CHT cht;
    f[1] = 0;
    cht.add(Line(-2ll * a[1], f[1] + 1ll * a[1] * a[1]));
    for (int i = 2; i <= n; i++) {
        
        f[i] = cht.qry(a[i]) + 1ll * a[i] * a[i] + c;
        cht.add(Line(-2ll * a[i], f[i] + 1ll * a[i] * a[i]));
        debug(f[i]);
    }
    cout << f[n] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


