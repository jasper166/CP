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

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
const ll LINF = 1e18;

ll n, m;


void run_case(){
    cin >> n >> m;
    if (n == 0 && m == 0) exit(0);
    if (n == 0){
        cout << -(m + (m * (m - 1))) << "\n";
        return;
    }
    if (m == 0){
        cout << (n + (n * (n - 1))) << "\n";
        return;
    }
    ll ans = -LINF;
    ll x = m + n;
    for(ll i = 1; i <= m; i++) {
            ll h = m / i;
            ll rem = m % i;
            ll zero = rem + (rem * (rem - 1));
            zero += h * (i + (i * (i - 1)));
            

            ll need = h - 1;
            ll one = need - 1;

            ll res = n - one;

            ckmax(ans, (res + (res * (res - 1)) + one - zero));
        }
    cout << ans << '\n';
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    // cin >> Test;
    for (; ;){

        run_case();
    }
}
// Codename : Jasper the Otter


