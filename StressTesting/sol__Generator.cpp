#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

#define rd(a, b) uniform_int_distribution<int>(a, b)(rnd)
#define rdl(a, b) uniform_int_distribution<ll>(a, b)(rnd)
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());


#include "tree/treegenerator.h"

using namespace std;
using namespace tree_generator_by_ouuan;


ll lcm(ll x, ll y) { return (x / __gcd(x, y) * y); }

signed main() {
    cin.tie(0) -> sync_with_stdio(0); 
    
    #ifdef JASPER
        // freopen("in1", "r", stdin);
        freopen("in2", "w", stdout);
    #endif

    int T = 20;
    // cout << T << "\n";
    while (T--) {
        int a = rd(100000000, 1000000000);
    int n = rd(100000000, 1000000000);
    int m = rd(100000000, 1000000000);
    cout << a << " " << n << " " << m << "\n";
    }

    
}

