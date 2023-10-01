
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
const int MAX = 15;

int n, g;
pii a[MAX];
void run_case() {
    cin >> n >> g;
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    int ans = INF;
    // 1 : solve all p(i) problems  0: solve <= p(i) problems;
    for (int mask = 0; mask < (1 << n); mask++) {
        int curPoint = 0, curPro = 0;
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                auto [d, c] = a[i];
                curPoint += 100 * (i + 1) * d + c;
                curPro += d;
            }
            else 
                last = i;
        }
        if (curPoint < g) {
            auto [d, c] = a[last];
            int point = 100 * (last + 1);
            int need = (g - curPoint + point - 1) / point;

            if (need >= d)
                continue;
            curPro += need;
        }
        ans = min(ans, curPro);
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

