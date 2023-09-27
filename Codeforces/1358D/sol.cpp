#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

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
#define TASK "1358D"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

ll n, x;
ll a[2 * MAX];

void run_case(){
    cin >> n >> x;
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
        a[i + n] = a[i];
    }
    n *= 2;
    
    ll ans = 0;
    ll day = 0, hug = 0;
    for (ll l = 1, r = 0; l <= n && r <= n; l++){
        day += a[l];
        hug += 1LL * a[l] * (a[l] + 1) / 2;
        while (day - a[r] >= x && r <= n){
            day -= a[r];
            hug -= 1LL * a[r] * (a[r] + 1) / 2;
            ++r;
        }
        ll exclude = day - x;
        if (exclude >= 0){
            ll cur_hug = hug - exclude * (exclude + 1) * 1LL / 2;
            ans = max(ans, cur_hug);
        }
                    
    }
    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    //if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}




