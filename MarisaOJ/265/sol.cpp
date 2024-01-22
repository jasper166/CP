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
struct Fenwick {
    vector <T> f;
    T n;
    Fenwick(T _n = 0) { init(_n); }
    void init(T _n) {
        n = _n;
        f.assign(n + 5, 0);
    }
    void upd(T x, T val) {
        for (; x <= n; x += x & -x)
            f[x] += val;
    }
    T qry(T x) {
        T ans = 0;
        for (; x > 0; x -= x & -x)
            ans += f[x];
        return ans;
    }
    T qry(T l, T r) {
        if (l > r) return 0;
        return qry(r) - qry(l - 1);
    }
};

const int N = 1e5 + 5;
const int BLOCK = 331;
// int BLOCK;
// const int M = 331;
int n, q;
int a[N];

Fenwick <int> fen[BLOCK];

// qry for upper
int qry(int l, int r, int x) {
    int L = l / BLOCK; int R = r / BLOCK;
    // debug(L, R);
    int ans = 0;
    if (L == R) {
        for (int i = l; i <= r; ++i)
            ans += (a[i] > x);
    }
    else {
        for (int i = l; i < (L + 1) * BLOCK; ++i)
        ans += (a[i] > x);
        for (int i = R * BLOCK; i <= r; ++i)
            ans += (a[i] > x);
        for (int i = L + 1; i < R; ++i)
            ans += fen[i].qry(x + 1, n);
    }
    return ans;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) a[i] = i;

    for (int i = 0; i <= n / BLOCK; ++i)
        fen[i].init(n);
    for (int i = 1; i <= n; ++i)
        fen[i / BLOCK].upd(a[i], 1);

    ll ans = 0;
    for (int i = 1; i <= q; ++i) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        if (x == y) {
            cout << ans << "\n";
            continue;
        }
        // numbers of value > a(y) in [x + 1, y - 1];
        if (x + 1 <= y - 1) {
            int cnt = qry(x + 1, y - 1, a[y]);
            int tot = y - x - 1;
            ans += 1LL * (tot - 2 * cnt);
        }
        // numbers of value < a(x) in [x + 1, y - 1];
        if (x + 1 <= y - 1) {
            int cnt = qry(x + 1, y - 1, 0) - qry(x + 1, y - 1, a[x] - 1);
            int tot = y - x - 1;
            ans += 1LL * (tot - 2 * cnt);
        }
        ans -= 1LL * (a[y] < a[x]);
        ans += 1LL * (a[y] > a[x]);

        cout << ans << "\n";

        int X = x / BLOCK;
        int Y = y / BLOCK;
        fen[X].upd(a[x], -1);
        fen[Y].upd(a[y], -1);
        swap(a[x], a[y]);
        fen[X].upd(a[x], 1);
        fen[Y].upd(a[y], 1);
    }
}