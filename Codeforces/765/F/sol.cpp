#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

template <typename T>
struct SegmentTree {
    T neutral;
    vector <T> f;
    int n, t;
    SegmentTree(int _n, bool _t, T _neutral) {
        init(_n, _t, _neutral);
    } 
    void init(int _n, bool _t, T _neutral) {
        n = _n;
        t = _t;
        neutral = _neutral;
        f.assign((_n << 1) + 5, _neutral);
    }
    T merge(T x, T y) {
        return (t? max(x, y) : min(x, y));
    }
    void upd(int i, T val) {
        i += n;
        f[i] = merge(f[i], val);
        for (; i >>= 1; ) {
            f[i] = merge(f[i << 1], f[i << 1 | 1]);
        }
    }
    T qry(int l, int r) {
        l += n;
        r += n;
        T ans = neutral;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = merge(ans, f[l++]);
            if (r & 1) ans = merge(ans, f[--r]);
        }
        return ans;
    }
};

const int N = 1e5 + 5;
const int INF = 1e9 + 5;
int n, q;
int a[N];
int ans[N * 3];
vector <pair <int, int>> qs[N];

void solve() {
    vector <int> vals;
    for (int i = 0; i < n; ++i) vals.push_back(a[i]);
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());

    SegmentTree <int> pos(vals.size(), 1, -INF);
    // find nearest j such a(j) >= a(i);
    SegmentTree <int> st(n, 0, INF);

    auto get = [&] (int x) -> int {
        return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    };
    auto qry = [&] (int l, int r) -> int {
        l = get(l); r = get(r);
        return pos.qry(l, r);
    };

    for (int i = 0; i < n; ++i) {
        int j = qry(a[i], 1e9);
        while (j >= 0) {
            st.upd(j, a[j] - a[i]);
            if (a[j] == a[i]) break;
            j = qry(a[i], a[i] + (a[j] - a[i]) / 2 + 1);
        }
        // (6, (6 + (9 - 6) / 2))
        pos.upd(get(a[i]), i);
        for (auto& [l, id] : qs[i])
            ans[id] = min(ans[id], st.qry(l, i + 1));
    }

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i], a[i]--;

    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        qs[r - 1].emplace_back(l - 1, i);
    }

    for (int i = 0; i < n; ++i) ans[i] = INF;
    solve();
    for (int i = 0; i < n; ++i) a[i] = 1e9 - a[i] - 1;
    solve();
    for (int i = 0; i < q; ++i)
        cout << ans[i] << "\n";
}


