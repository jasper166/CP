#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
const int BLOCK = 311;

struct Queries {
    int l, r, id;
    bool operator < (const Queries& x) const {
        if (l / BLOCK == x.l / BLOCK)
            return (l / BLOCK & 1)? r > x.r : r < x.r;
        return (l / BLOCK < x.l / BLOCK);
    } 
};

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int p;
    string s;
    cin >> p >> s;

    int n = s.size();
    s = "@" + s;
    vector <int> a(n + 5);
    for (int i = 1; i <= n; ++i) a[i] = s[i] - '0';
    

    int q; cin >> q;
    vector <Queries> queries;
    vector <int> ans(q + 5);

    for (int i = 1; i <= q; ++i) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r, i});
    }

    // Special case : p = 2, p = 5 -> take whole prefix
    if (p == 2 || p == 5) {
        vector <ll> f(n + 5, 0), g(n + 5, 0);
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] + 1ll * i * (a[i] % p == 0);
            g[i] = g[i - 1] + (a[i] % p == 0);
        }
        for (auto [l, r, id] : queries) {
            ll tot = (f[r] - f[l - 1]);
            ll excl = 1ll * (l - 1) * (g[r] - g[l - 1]);
            cout << tot - excl << "\n";
        }
        return 0;
    }

    // other case: counting pair (i, j) (prf(j) - prf(i - 1)) % p == 0 -> counting number of pair = X 
    // Mo's

    for (auto& [l, r, id] : queries) ++r;
    sort(queries.begin(), queries.end());
    vector <int> f(n + 5);
    int pw = 1;
    for (int i = n; i >= 1; --i) {
        f[i] = (f[i + 1] + pw * a[i]) % p;    
        pw = (pw * 10ll) % p;
    }

    // auto get = [&] (int l, int r) -> int {
    //     return f[l] - f[r + 1];
    // };

    vector <int> vals(1, 0);
    for (int i = 1; i <= n; ++i)
        vals.push_back(f[i]);
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    for (int i = 1; i <= n; ++i) {
        f[i] = (int) (lower_bound(vals.begin(), vals.end(), f[i]) - vals.begin());
    }

    vector <int> cnt(1e6, 0);
    ll ret = 0;
    auto add = [&] (int i) {
        int x = f[i];
        ret += cnt[x];
        ++cnt[x];
    };
    auto del = [&] (int i) {
        int x = f[i];
        ret -= (cnt[x] - 1);
        --cnt[x];
    };

    int l = 1, r = 1;
    cnt[f[1]] = 1;
    for (int i = 0; i < q; ++i) {
        auto [L, R, id] = queries[i];
        while (l > L) add(--l);
        while (r < R) add(++r);
        while (l < L) del(l++);
        while (r > R) del(r--);
        // choose two distinct index or one index twice
        ans[id] = ret;
    }

    for (int i = 1; i <= q; ++i) cout << ans[i] << "\n";
}

