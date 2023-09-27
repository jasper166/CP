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
#define debug(...) 42
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;


struct SegTree {
    ll *f;

    void init (int N) {
        f = new ll[4 * N + 1];
        for (int i = 1; i <= 4 * N; i++) f[i] = 0LL;
    }

    void build (int x, int l, int r, int i, int val) {
        if (i > r || i < l)
            return;
        if (r == l) {
            f[x] = val;
            return;
        }
        int m = (l + r) / 2;
        update(2 * x, l, m, i, val);
        update(2 * x + 1, m + 1, r, i, val);
        f[x] = f[2 * x] + f[2 * x + 1];
    }
    
    void update (int x, int l, int r, int i, int val) {
        if (i > r || i < l)
            return;
        if (r == l) {
            f[x] += 1LL * val;
            return;
        }
        int m = (l + r) / 2;
        update(2 * x, l, m, i, val);
        update(2 * x + 1, m + 1, r, i, val);
        f[x] = f[2 * x] + f[2 * x + 1];
    }

    ll get (int x, int l, int r, int u, int v) {
        if (l > v || r < u)
            return 0LL;
        if (u <= l && r <= v)
            return f[x];
        int m = (l + r) / 2;
        ll sumL = get(2 * x, l, m, u, v);
        ll sumR = get(2 * x + 1, m + 1, r, u, v);
        return (sumL + sumR);
    }
} st;

int n, q;

void run_case() {
    cin >> n >> q;
    st.init(n);
    vector <int> a(n + 1, 0), pref(n + 1, 0);
    for (int Q = 1; Q <= q; Q++) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            st.update(1, 1, n, l + 1, val);
            st.update(1, 1, n, r + 1, -val);
        }
        else {
            int x; cin >> x;
            cout << (st.get(1, 1, n, 1, x + 1) - pref[x]) << "\n";
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

