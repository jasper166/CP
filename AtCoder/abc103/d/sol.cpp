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


void run_case() {
    int n, m;
    cin >> n >> m;
    vector <pii> a(m);
    for (int i = 0; i < m; i++) cin >> a[i].fi >> a[i].se;
    sort(all(a));
    // remove bridges as at index x: [x, n] is sastified 
    // if (a <= x < b) then we're done as [a, x] is not connected to [x, b];
    int last = INF;
    int cnt = 0;
    for (int i = m - 1; i >= 0; i--) {
        if (last < a[i].se) continue;
        ++cnt;
        last = a[i].first;
    }
    cout << cnt << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

