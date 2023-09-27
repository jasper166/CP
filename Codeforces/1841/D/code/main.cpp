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
const int MAX = 2e3 + 5;

int n;
pii a[MAX];
void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].fi >> a[i].se;

    vector <pii> segs;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            pii x = make_pair(min(a[i].fi, a[j].fi), max(a[i].se, a[j].se));
            if (a[i].fi <= a[j].fi && a[i].se >= a[j].fi)
                segs.push_back(x);
            if (a[i].fi >= a[j].fi && a[j].se >= a[i].fi)
                segs.push_back(x);
        }
    }
//    debug(segs);
    int x = 0;
    sort(segs.begin(), segs.end(), [] (pii x, pii y) {
            return (x.se < y.se);
        }
    );
    int last = -1;
    for (auto [l, r] : segs) {
        if (last < l) {
            last = r;
            ++x;
        }
    }
    cout << (n - 2 * x) << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
