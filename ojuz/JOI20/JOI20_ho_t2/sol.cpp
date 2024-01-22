#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#define fi first
#define se second
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, k;
string s;
deque <int> q[3];
void run_case() {
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'J') q[0].push_back(i);
        if (s[i] == 'O') q[1].push_back(i);
        if (s[i] == 'I') q[2].push_back(i);
    }

    int ans = INF;
    while ((int) q[0].size() >= k) {
        // delete all Os sitting front of k Js
        while ((int) q[1].size() > k && q[1].front() < q[0][k - 1]) 
            q[1].pop_front();
        // delete all Is front of k Os
        while ((int) q[2].size() > k && (int) q[1].size() >= k && q[2].front() < q[1][k - 1])
            q[2].pop_front();
        if (q[0][k - 1] < q[1][0] && q[1][k - 1] < q[2][0]) {
            int l = q[0].front();
            int r = q[2][k - 1];
            // debug(l, r);
            // minimum operation 3
            ans = min(ans, r - l + 1 - 3 * k);
        }
        q[0].pop_front();
    } 

    if (ans == INF) ans = -1;
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


