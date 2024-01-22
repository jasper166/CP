#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;

        vector <vector <int>> adj(n + 5, vector <int> (m + 5, 0));
        for (int i = 1; i <= m; ++i) {
            int u, v; cin >> u >> v;
            
        }
        auto dfs = [&] (int u, int p) -> void {

        };
    }    
}

