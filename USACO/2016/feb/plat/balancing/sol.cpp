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
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
struct SegmentTree {
    vector <int> f;
    int n;
    SegmentTree(int _n) : f(_n * 2 + 5, 0), n(_n) {};
    void upd(int x, int val) {
        f[x += n] += val;
        for (; x >= 1; x >>= 1)
            f[x >> 1] = f[x] + f[x ^ 1];
    }
    int qry(int l, int r) {
        int ql = 0, qr = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ql += f[l++];
            if (r & 1) qr += f[--r];
        }
        return ql + qr;
    }
};
SegmentTree north(N), south(N);
int n;
pii cows[N];

int cal(int x, int type) {
    int north_west = north.qry(1, x);
    int north_east = north.qry(x + 1, N);
    int south_west = south.qry(1, x);
    int south_east = south.qry(x + 1, N);
    int lhs = max(north_west, south_west);
    int rhs = max(north_east, south_east);
    // maximum value belong to the west;
    if (type == 1) 
        return (lhs >= rhs)? lhs : -1;
    else 
        return (rhs >= lhs)? rhs : -1;
    // or it belongs to the east
}

int qry(int type) {
    int l = 1, r = N, ans = INF;
    while (l <= r) {
        int m = (l + r) / 2;
        int cur = cal(m, type);
        // debug(m, cur, ans);
        if (cur != -1) {
            ans = min(ans, cur);
            (type == 1)? r = m - 1 : l = m + 1;
        }
        else 
            (type == 1)? l = m + 1 : r = m - 1;
    }
    return ans;
}

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> cows[i].fi >> cows[i].se;
    sort(cows + 1, cows + 1 + n, [] (pii x, pii y) {
        return x.se < y.se;
    });
    
    int ans = INF;
    // sweepline from bottom to top -> all cows first belong to north side
    for (int i = 1; i <= n; ++i) 
        north.upd(cows[i].fi, 1);
    for (int i = 1; i <= n;) {
        // Move cows from north to south
        int j = i;
        while (j <= n && cows[j].se == cows[i].se) {
            north.upd(cows[j].fi, -1);
            south.upd(cows[j].fi, 1);
            ++j;
        }
        // debug(north.qry(1, N));
        // debug(south.qry(1, N));
        ans = min({ans, qry(1), qry(2)});
        i = j;
    }
    cout << ans << "\n";
}

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    // setIO("balancing");
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


