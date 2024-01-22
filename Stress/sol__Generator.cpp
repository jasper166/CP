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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#include "tree/treegenerator.h"

using namespace std;
using namespace tree_generator_by_ouuan;


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    // #ifdef JASPER
    //     freopen("in1", "r", stdin);
    // #endif

    int n = rd(1e4, 1e5);
    int q = rd(2, 5);
    int k = rd(1, 20);
    debug(pow(1e5, 2.0 / 3.0));
    cout << n << " " << q << " " << k << "\n";
    for (int i = 1; i <= n; ++i)
        cout << rd(1, 20) << " \n"[i == n];
    for (int i = 1; i <= q; ++i) {
        int cmd, u, v;
        cmd = rd(1, 2);
        cout << cmd << " ";
        if (cmd == 1) {
            int id = rd(1, n);
            int x = rd(1, 20);
            cout << id << " " << x << "\n";
        }
        else {
            int l = rd(1, n);
            int r = rd(l, n);
            cout << l << " " << r << "\n";
        }
    }
}

