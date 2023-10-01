#include "bits/stdc++.h"
// @Jasper


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

ll l, r;

ll lux(ll n){
    if(n < 4)
        return n;
    ll nn = sqrt(n);
    ll x = (nn * nn - 1) / (nn - 1);
    ll y = x - 3;
    ll X = (3 + x) * (x - 3 + 1) / 2;
    ll Y = (0 + y) * (y - 0 + 1) / 2;
    ll res = X - Y +  (n / nn - (nn * nn - 1) / nn);
    return res;
}


void run_case(){
    cin >> l >> r;
    cout << lux(r) - lux(l - 1) << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

