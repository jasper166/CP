// Time complexity: O(N log(N)^2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a[100'000];
ll m, p[100'001];

pair<ll, ll> handshake_and_happiness_count(int min_handshake) {
    ll total_handshake = 0, total_happiness = 0;
    for (int center = 0; center < n; ++center) {
        if (a[center] + a[n-1] < min_handshake) continue;

        int l = center, r = n-1;
        while (l < r) {
            int idx = l + (r-l)/2;
            if (a[center] + a[idx] >= min_handshake) r = idx;
            else l = idx + 1;
        }
        total_handshake += 2 * (n-l); // l to n-1
        if (l == center) total_handshake -= 1;

        total_happiness += 2ll * (n-l) * a[center] + 2 * (p[n] - p[l]);
        if (l == center) total_happiness -= 2 * a[center];
    }
    return {total_handshake, total_happiness};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a+n);
    for (int i = 0; i < n; ++i) p[i+1] = p[i] + a[i];

    int l = 0, r = 2e5;
    while (l < r) {
        int min_handshake  = l + (r - l + 1) / 2;
        auto result = handshake_and_happiness_count(min_handshake);
        if (result.first >= m) l = min_handshake;
        else r = min_handshake - 1;
    }
    auto result = handshake_and_happiness_count(l);

    cout << result.first << "\n";
    for (ll i = result.first; i > m; --i) result.second -= l;
    cout << result.second << '\n';
}