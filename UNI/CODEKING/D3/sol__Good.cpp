#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair < int, int >;
using pll = pair < ll, ll >;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#define debugArr(...) 42
#endif

const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const ll LINF = 1e18 + 5;

ll n, m;
ll a[MAX], b[MAX];

bool ok(ll x) {
    vector < int > mark(n + 100, 0);
    for (int i = 1; i <= m; ++i) {
        int pos1 = upper_bound(a + 1, a + 1 + n, b[i] + x) - a - 1;
        int pos2 = lower_bound(a + 1, a + 1 + n, b[i] - x) - a;
        if(pos1 < 1 || pos2 > n)continue;
        mark[pos2]++;
        mark[pos1 + 1]--;

    }
    // if (x == 2){
    //     FOR(i, 1, n) cout << mark[a[i]] << " \n";
    // }
    int s = 0;
    for(int i = 1; i <= n; i++){
        s += mark[i];
        if(s == 0)return false;
    }

    return 1;
}


void run_case() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    ll l = 0, r = LINF, ans = 0;
    while (l <= r) {
        ll x = (l + r) / 2;
        if (ok(x)) {
            ans = x;
            r = x - 1;
        }
        else
            l = x + 1;
    }
    cout << ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int Test = 1;
    //    cin >> Test;
    FOR(i, 1, Test) {

        run_case();
    }
}
// Codename : Jasper the Otter