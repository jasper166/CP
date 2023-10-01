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

ll x, y, z, n;
ll gcd(ll a, ll b){
    while (b) swap(b, a %= b);
    return a;
}
ll lcm(ll a, ll b){ 
    return ((ll) a / gcd(a, b) * b);
}
void run_case(){
    cin >> x >> y >> z >> n;
    ll L1 = lcm(x, y);
    L1 = lcm(L1, z);
    ll down = pow(10, n - 1);
    ll up = pow(10, n);
    ll dd = down / L1, du = up / L1;
    if (du == 0 && dd == 0) {
        cout << "-1\n";
        return;
    }
    if (dd * L1 < down) dd++;
    cout << dd * L1 << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter



