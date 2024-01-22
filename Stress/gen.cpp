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

    int n = rd(1e5, 2e5);
    int m = rd(1e5, 2e5);
    int q = rd(1e5, 2e5);
    cout << n << " " << m << " " << q << "\n";
    Tree t(n);
    cout << t;

    for (int i = 1; i <= m; ++i) cout << rd(1, n) << " \n"[i == m];
    for (int i = 1; i <= q; ++i) {
        int cmd = rd(1, 2);
        cout << cmd << " ";
        if (cmd == 1) {
            int x = rd(1, m);
            int v = rd(1, n);
            cout << x << " " << v << "\n";
        }
        else {
            int x = rd(1, m);
            int y = rd(x, m);
            int u = rd(1, n);
            cout << x << " " << y << " " << u << "\n";
        }
    }
}

