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
const int MAX = 1e6 + 5;

struct BIT {
    vector <int> f;
    BIT () {f.assign(MAX << 1, 0);}
    void add(int x, int val) {
        for (; x < MAX * 2; x += x & -x)
            f[x] += val;
    }
    int qry(int x) {
        int ans = 0;
        for (; x > 0; x -= x & -x)
            ans += f[x];
        return ans;
    }
    int qry(int l, int r) {
        return qry(r) - qry(l - 1);
    }
};

int n;
void run_case() {
    cin >> n;
    vector <array <int, 4>> a;
    BIT bit;
    for (int i = 1; i <= n; ++i) {
        int x, y, X, Y;
        cin >> x >> y >> X >> Y;
        if (x == X) {
            a.push_back({y, x, 1, 1});
            a.push_back({Y, x, 1, 3});
        }
        else
            a.push_back({y, x, X, 2});
    }
    sort(a.begin(), a.end());

    ll ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        auto x = a[i];
        x[1] += MAX - 5;
        x[2] += MAX - 5;
        if (x[3] == 2) {
            debug(bit.qry(7));
            ans += bit.qry(x[1], x[2]);
        }
        else if (x[3] == 1)
            bit.add(x[1], 1);
        else
            bit.add(x[1], -1);
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
