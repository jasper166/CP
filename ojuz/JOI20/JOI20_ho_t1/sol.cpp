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
const int N = 1e6 + 5;

void run_case() {
    int n; cin >> n;

    int ans = 1;
    int p5 = 0;
    for (int i = n; i >= 2; --i) {
        int x = i;
        // Xem co bao nhieu so 5 trong x hien tai
        while (x % 5 == 0) {
            ++p5;
            x /= 5;
        }
        // Ghep voi cac thang 2 tuong ung
        while (x % 2 == 0 && p5 > 0) {
            --p5;
            x /= 2;
        }
        ans *= (x % 10);
        ans %= 10;
    }
    cout << ans << "\n";
}
    
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    // cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

