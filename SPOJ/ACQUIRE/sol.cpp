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
const int MAX = 5e4 + 5;

int n;
struct Rect {
    int w, h;
    bool operator < (const Rect& o) const {
        return (w < o.w);
    }
} a[MAX];

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
// Query for min;
struct ConvexHull {
    deque <Line> q;
    void add(Line nLine) {
        while (q.size() >= 2 && q[q.size() - 2].cross(nLine) <= q[q.size() - 1].cross(q[q.size() - 2]))
            q.pop_back();
        q.push_back(nLine);
    }

    ll qry(ll x) {
        while (q.size() >= 2 && q[0].cal(x) >= q[1].cal(x))
            q.pop_front();
        return q[0].cal(x);
    }
};

ll f[MAX];
// min cost to buy (1...i) lands;
bool useless (const Line& y1, const Line& y2, const Line& y3) {
    return (y2.b - y1.b) * (y1.a - y3.a) >= (y3.b - y1.b) * (y1.a - y2.a);
}

void run_case() {   
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].w >> a[i].h;
    sort(a + 1, a + 1 + n);
    
    vector <Rect> b;
    for (int i = 1; i <= n; i++) {
        while (!b.empty() && b.back().h < a[i].h)
            b.pop_back();
        b.push_back(a[i]);
    }

    ConvexHull cht;
    ll ans = LINF;
    ll bestF = 0;
    for (int i = 0; i < (int) b.size(); i++) {
        int x = b[i].w;
        cht.add(Line(b[i].h, bestF));
        bestF = cht.qry(x);
    }
    cout << bestF << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


