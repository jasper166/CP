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

    int n; cin >> n;
    vector <pair <int, int>> cows(n);

    vector <int> vals_x, vals_y;
    for (auto& [x, y] : cows) {
        cin >> x >> y;
        vals_x.push_back(x);
        vals_y.push_back(y);
    }

    sort(vals_x.begin(), vals_x.end());
    vals_x.resize(unique(vals_x.begin(), vals_x.end()) - vals_x.begin());

    sort(vals_y.begin(), vals_y.end());
    vals_y.resize(unique(vals_y.begin(), vals_y.end()) - vals_y.begin());

    for(auto& [x, y] : cows) {
        x = (int) (lower_bound(vals_x.begin(), vals_x.end(), x) - vals_x.begin());
        y = (int) (lower_bound(vals_y.begin(), vals_y.end(), y) - vals_y.begin());
    }

    // sort by x
    sort(cows.begin(), cows.end());
    debug(cows);
    vector <vector <int>> lo(n + 5, vector <int> (n + 5)), hi(n + 5, vector <int> (n + 5));
    // lo(x, y) : numbers of cows i having x_i <= x and y_i <= y
    for (int i = 0; i < n; ++i) {
        int y = cows[i].second;
        for (int x = 1; x <= n; ++x) {
            lo[x][y] = lo[x - 1][y] + (cows[x - 1].second <= y);
            hi[x][y] = hi[x - 1][y] + (cows[x - 1].second >= y);
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int lower = min(cows[i].second, cows[j].second);
            int upper = max(cows[i].second, cows[j].second);
            
            int x = lo[j + 1][lower] - lo[i][lower]; // numbers of cows having x_i < x < x_j, y < min;
            int y = hi[j + 1][upper] - hi[i][upper];

            ans += 1LL * x * y; 
        }
    }   
    // a single cow or none 
    ans += n + 1;
    cout << ans << "\n";
    
    return 0;
}

