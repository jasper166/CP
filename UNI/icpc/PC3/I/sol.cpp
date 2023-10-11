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
 
const int INF = 2e9 + 5;
const int MOD = 23092001LL;
const int MAX = 1e5 + 5;
const ll LINF = 1e18 + 5;

int n, t;
pii a[MAX];

void run_case() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + 1 + n, [](const pii x, const pii y){
        if (x.se == y.se) return x.fi > y.fi;
        return x.se < y.se;
    });
    ll ans = 0;
    int pre = -1;
    for (int i = 1; i <= n; i++){
        if (pre < a[i].se){
            ans += (ll) a[i].fi;
            pre = a[i].se;
        }
    }
    cout << ans << "\n";
}
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
 
    int Test = 1;
   // cin >> Test;
    FOR(i, 1, Test){
 
        run_case();
    }
}
// Codename : Jasper the Otter
