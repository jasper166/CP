#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int p = uid(2, 100);
    int n = uid(1, 10);
    string s;
    for (int i = 0; i < n; ++i) s += (char) (uid(0, 9) + '0');

    cout << p << "\n" << s << "\n";
    int q = uid(1, 5);
    cout << q << "\n";
    for (int i = 0; i < q; ++i) {
        int l = uid(1, n);
        int r = uid(l, n);
        cout << l << " " << r << "\n";
    }
}