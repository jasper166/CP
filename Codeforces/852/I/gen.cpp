#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

// #ifdef JASPER
// #include "debug.h"
// #else
// #define debug(...) 166
// #endif

#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    int n = uid(1e6, 1e6);
    cout << n << "\n";
    for (int i = 1; i <= n; ++i) {
    	cout << uid(0, 1e9) << "\n";
    }
}

