#include "bits/stdc++.h"
#include <sys/types.h>

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
const int MAX = 2e5 + 5;
const int LIM = 32767;
const double EPS = 1e-6;

ll gcd(ll a, ll b){
    return (b? gcd(b, a % b) : a);
}


ll x, y;

void run_case(){
    cin >> x >> y;
    ll n1 = 1e9, d1 = 1, n2 = 1, d2 = 1e9;
    for (ll i = 1; i <= LIM; ++i){
        ll j = i * x / y + 1;
        if (j * d1 < i * n1){
            ll g = gcd(i, j);
            n1 = j / g;
            d1 = i / g;
        }
    }

    for (ll i = 1; i <= LIM; ++i){
        ll j = i * x / y;
        if (x * i == j * y) --j;
        j = max(0LL, j);
        if (j * d2 > i * n2){
            ll g = gcd(i, j);
            n2 = j / g;
            d2 = i / g;
        }

    }
    ll C1 = abs(x * d1 - y * n1);
    ll C2 = y * d1;
    ll C3 = abs(x * d2 - y * n2);
    ll C4 = y * d2;
    if (C1 * C4 >= C2 * C3) swap(n1, n2), swap(d1, d2);
    cout << n1 << " " << d1 << "\n";
    
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



