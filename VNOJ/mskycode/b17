#include "bits/stdc++.h"
using namespace std;
using ll = long long;
// B17
const int MAX = 1e6 + 5;
int a[MAX];
int n;
void run_case() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);

    ll x1 = (1ll * a[1] * a[2] * a[n]);
    ll x2 = (1ll * a[n - 2] * a[n - 1] * a[n]);
    ll x3 = (1ll * a[1] * a[2]);
    ll x4 = (1ll * a[n - 1] * a[n]);
    // n = 3, -1 4 5
    cout << max({x1, x2, x3, x4}) << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
