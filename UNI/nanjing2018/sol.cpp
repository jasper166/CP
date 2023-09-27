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
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#define TASK "INP"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

ll n;
ll Mpow(ll a, ll x){
    ll ans = 1;
    while (x){
        if (x & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        x >>= 1;
    }
    return ans;
}

void run_case(){
    cin >> n;
    ll inv = Mpow(24, MOD - 2);
//    cout << Mpow(2, 2) << "\n";
//    debug(n);
    ll ans = Mpow(n, 4);
  //  debug(ans);
    ll temp = 6LL * Mpow(n, 3);
    temp %= MOD;
   // debug(temp);
    ans += temp;
    ans %= MOD;
    temp = 11LL * Mpow(n, 2);
   // debug(temp);
    temp %= MOD;
    ans += temp;
    ans %= MOD;
    temp = 6LL * n;
   // debug(temp);
    temp %= MOD;
    ans += temp;
    ans %= MOD;
    ans *= inv;
    ans %= MOD;
    cout << ans << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

