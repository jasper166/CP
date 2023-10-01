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
const int MAX = 1e6 + 5;

struct Fenwick {
    vector <int> f;
    int n;
    Fenwick () {};
    Fenwick (int N) {
        f.resize(N + 5);
        n = N;
    }
    void upd(int x, int val) {
        for (; x <= n ; x += x & -x)
            f[x] += val;
    }
    int get(int x) {
        int ans = 0;
        for (; x; x -= x & -x)
            ans += f[x];
        return ans;
    }
};

using T = pair <double, double>;
int ans[MAX];
T houses[MAX];
T A[3];
int n, q;

struct Query {
    int r1, r2, id;
    bool operator < (const Query &x) const {
        return (r1 < x.r1);
    } 
} queries[MAX];

vector <double> dis;

double getDis(T x, T y) {
    return sqrt((x.fi - y.fi) * (x.fi - y.fi) + (x.se - y.se) * (x.se - y.se));
}
int comp(double X) {
    return (int) (lower_bound(dis.begin(), dis.end(), X) - dis.begin() + 1);
}

int f[2 * MAX][2];
void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> houses[i].fi >> houses[i].se;
    cin >> A[1].fi >> A[1].se >> A[2].fi >> A[2].se;
    cin >> q;
    vector <T> factories;
    for (int i = 1; i <= q; ++i) {
        double r1, r2;
        cin >> r1 >> r2;
        factories.push_back({r1, r2});
        dis.push_back(r1);
        dis.push_back(r2);
    }

    // debug(A[1], A[2]);
    for (int i = 1; i <= n; ++i) {
        // debug(houses[i]);
        double d1 = getDis(houses[i], A[1]);
        double d2 = getDis(houses[i], A[2]);
        dis.push_back(d1);
        dis.push_back(d2);
    }

    // debug(dis);
    sort(dis.begin(), dis.end());
    dis.resize(unique(dis.begin(), dis.end()) - dis.begin());
    vector <pii> events;
    for (int i = 1; i <= n; ++i) {
        int d1 = comp(getDis(houses[i], A[1]));
        int d2 = comp(getDis(houses[i], A[2]));
        events.push_back({d1, d2});
    }
    int sz = events.size();
    Fenwick bit(2 * MAX);
    for (int i = 0; i < sz; ++i) {
        f[events[i].fi][0]++;
        f[events[i].se][1]++;
    }

    for (int i = 1; i < MAX; ++i) {
        f[i][0] += f[i - 1][0];
        f[i][1] += f[i - 1][1]; 
    }

    for (int i = 0; i < q; ++i) {
        auto [r1, r2] = factories[i];
        queries[i + 1] = {comp(r1), comp(r2), i + 1};
    }

    sort(events.begin(), events.end());
    sort(queries + 1, queries + 1 + q);
    int pos = 0;
    for (int i = 1; i <= q; ++i) {
        auto [r1, r2, id] = queries[i];
        while (pos < sz && events[pos].fi <= r1) {
            bit.upd(events[pos].se, 1);
            ++pos;
        }
        ans[id] = f[r1][0] + f[r2][1] - bit.get(r2);
    } 
    for (int i = 1; i <= q; ++i) 
        cout << ans[i] << "\n"; 
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
