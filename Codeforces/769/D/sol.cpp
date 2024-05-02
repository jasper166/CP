#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 1e4 + 5;
const int K = 14;
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int n, k;
    cin >> n >> k;

    vector <int> cnt(N, 0);
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector <int> candidates;
    for (int i = 0; i < (1 << K); ++i)
        if (__builtin_popcount(i) == k)
            candidates.push_back(i);

    ll ans = 0;
    int mx = *max_element(a.begin(), a.end());
    for (int x = 0; x <= mx; ++x) {
        if (cnt[x] == 0) continue;
        for (int i : candidates) {
            int y = x ^ i;
            if (y > x) continue;
            if (x != y) ans += 1LL * cnt[x] * cnt[y];
            else ans += (1LL * cnt[x] * (cnt[y] - 1)) / 2;
        }
    }
    cout << ans << "\n";
}