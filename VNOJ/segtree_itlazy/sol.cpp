#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 166
#define debugArr(...) 166
#endif


const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int n, q;
int a[MAX];

struct SegTree {
    ll *f, *lazy;
    void init(int N) {
        f = new ll[4 * N + 1];
        lazy = new ll[4 * N + 1];
        for (int i = 0; i <= 4 * N; i++) {
            lazy[i] = 0;
            f[i] = 0;
        }
    }

    ll merge(ll l, ll r) {
        return max(l, r);
    }

    void build(int x, int l, int r) {
        if (l == r) {
            f[x] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        f[x] = merge(f[2 * x], f[2 * x + 1]);
    }

    void push(ll x) {
        ll val = lazy[x];
        if (val) {
            f[2 * x] += val;
            f[2 * x + 1] += val; 
            lazy[2 * x] += val;
            lazy[2 * x + 1] += val;
            lazy[x] = 0;
        }
    }

    void update(int x, int l, int r, int u, int v, int val) {
        if (u > r || v < l)
            return;
        if (u <= l && r <= v) {
            f[x] += val;
            lazy[x] += val;
            return;
        }
        int m = (l + r) / 2;
        push(x);
        update(2 * x, l, m, u, v, val);
        update(2 * x + 1, m + 1, r, u, v, val);
        f[x] = merge(f[2 * x], f[2 * x + 1]);
    }

    ll get(int x, int l, int r, int u, int v) {
        if (u > r || v < l)
            return -LINF;
        if (u <= l && r <= v)
            return f[x];
        int m = (l + r) / 2;
        push(x);
        ll sl = get(2 * x, l, m, u, v);
        ll sr = get(2 * x + 1, m + 1, r, u, v);
        return merge(sl, sr);
    }

} st; 

void run_case() {
    cin >> n;
    st.init(n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    st.build(1, 1, n);

    cin >> q;
    while (q--) {
        int cmd, x, y, val;
        cin >> cmd >> x >> y;
        if (cmd == 1) {
            cin >> val;
            st.update(1, 1, n, x, y, val);
        }
        else {
            cout << st.get(1, 1, n, x, y) << "\n";
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
