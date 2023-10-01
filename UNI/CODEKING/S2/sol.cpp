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
const int MAX = 1e6 + 5;
const ll LINF = 1e18 + 5;
ll n, k, ans;
vector < ll > prime;
void init1() {
    cin >> n >> k;

    auto get = [&](ll k) {
        if (k == 0) return 0ll;
        ll a = 1, x = 1;
        for (ll i = 1; i < k; i++) {
            a = (a * 10ll) % MOD;
            x = (x * 10ll + 1ll) % MOD;
        }
        return (a * x * 45ll) % MOD;
    };

    ans = (get(k) - get(k - 1) + 1ll * MOD * MOD) % MOD;
}
void init2() {
    for (ll i = 2; 1ll * i * i <= n; i++)
        if (n % i == 0) {
            prime.push_back(i);
            while (n % i == 0) n /= i;
        }
    if (n != 1) prime.push_back(n);
}
void solve() {
    vector < pair < ll, ll > > ex;
    ex.emplace_back(1ll, -1ll);
    auto get = [&](ll x, ll k) {
        ll n = 0ll, s = 1ll;
        for (int i = 1; i <= k; i++){
            s = s * 10ll;
            n = (n * 10ll + s / x) % MOD;
            s %= x;
        }
        if(s == 0ll) n = (n - 1 + MOD) % MOD;

        ll ret = x;
        ret %= MOD;
        ret *= n;
        ret %= MOD;
        ret *= n + 1;
        ret %= MOD;
        ret *= 11546001ll;
        ret %= MOD;
        return ret;
    };

    for (auto x : prime)
        for (ll i = (ll) ex.size() - 1; i >= 0; i--) {
            auto [y, z] = ex[i];
            ex.emplace_back(x * y, z * (-1ll));
            ans = (ans + z * (get(x * y, k) - get(x * y, k - 1) + 1ll * MOD * MOD) + 1ll * MOD * MOD) % MOD;
        }
    
    cout << ans << "\n";
}
void run_case() {
    init1();
    init2();
    solve();

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
