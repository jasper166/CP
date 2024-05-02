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

    int n;
    ll m;
    cin >> n >> m;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a.begin() + 1, a.end());

    vector <ll> prf(n + 1);
    for (int i = 1; i <= n; ++i) prf[i] = prf[i - 1] + a[i];

    int l = 0, r = 2e5;
    int x = 0; // minimum score gain after a handshake

    auto func = [&] (int k) {
        ll cnt = 0, sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] + a[n] < k) continue;
            int j = (int) (lower_bound(a.begin() + i, a.end(), k - a[i]) - a.begin()); // find j's such a(j) + a(i) >= x
            cnt += 2LL * (n - j + 1) - (j == i);
            sum += 2LL * (n - j + 1) * a[i] + 2LL * (prf[n] - prf[j - 1]) - 2LL * (j == i) * a[i];
        }
        return make_pair(cnt, sum);
    };

    while (l <= r) {
        int mid = (l + r) / 2;
        if (func(mid).first >= m) {
            l = mid + 1;
            x = mid;
        }
        else 
            r = mid - 1;
    }

    auto [cnt, happiness] = func(x);
    happiness -= 1LL * (cnt - m) * x; // subtract invalid
    // debug(cnt, m, x, cnt - m, d);
    cout << happiness << "\n";

    return 0;
}
