#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 166
#define debugArr(...) 166
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
const double EPS = 1e-9;

struct BIT {
    int f[MAX];
    int get(int x) {
        int ans = 0;
        for (; x; x -= x & -x)
            ans += f[x];
        return ans;
    }
    void upd(int x, int val) {
        for (; x < MAX; x += x & -x)
            f[x] += val;
    }
} bit;

int n;
struct Line {
    double x;
    int y1, y2, id;
    bool operator < (const Line& o) const{
        return (x < o.x);
    }
};

vector <double> Y;
double blue_x1[MAX], blue_x2[MAX], blue_y[MAX];
double red_x[MAX], red_y1[MAX], red_y2[MAX];
vector <Line> lines;

void run_case() {
    cin >> n;    
    for (int i = 1; i <= n; i++) {
        double x1, x2, y;
        cin >> x1 >> x2 >> y;
        if (x1 > x2) swap(x1, x2);
        blue_x1[i] = x1;
        blue_x2[i] = x2;
        blue_y[i] = y;
        Y.push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        double y1, y2, x;
        cin >> y1 >> y2 >> x;
        if (y1 > y2) swap(y1, y2);
        red_x[i] = x;
        red_y1[i] = y1;
        red_y2[i] = y2;
        Y.push_back(y1);
        Y.push_back(y2);
    }
    // debug(Y);
    sort(Y.begin(), Y.end());
    Y.resize(unique(Y.begin(), Y.end()) - Y.begin());
    // debug(Y);
    for (int i = 1; i <= n; i++) {
        int ny = lower_bound(Y.begin(), Y.end(), blue_y[i]) - Y.begin() + 1;
        lines.push_back({blue_x1[i] - EPS, 0, ny, 1});
        lines.push_back({blue_x2[i] + EPS, 0, ny, 2});
    }

    for (int i = 1; i <= n; i++) {
        int ny1 = lower_bound(Y.begin(), Y.end(), red_y1[i]) - Y.begin() + 1;
        int ny2 = lower_bound(Y.begin(), Y.end(), red_y2[i]) - Y.begin() + 1;
        lines.push_back({red_x[i], ny1, ny2, 3});
    }
    
    sort(lines.begin(), lines.end());
    ll ans = 0;
    for (auto [x, y1, y2, id] : lines) {
        // debug(x, y1, y2, id);
        if (id == 1)
            bit.upd(y2, 1);
        if (id == 2)
            bit.upd(y2, -1);
        if (id == 3)
            ans += bit.get(y2) - bit.get(y1 - 1);
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

