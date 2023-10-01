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
const int MAX = 1e5 + 5;

struct SegTree {
    int *f;
    int n;

    void init (int N) {
        f = new int[4 * N + 1];
        n = N;
    }

    void update (int x, int l, int r, int i, int val) {
        if (r < i || l > i)
            return;
        if (i == l && i == r) {
            f[x] = val;
            return;
        }
        int m = (l + r) / 2;
        update(2 * x, l, m, i, val);
        update(2 * x + 1, m + 1, r, i, val);
        f[x] = min(f[2 * x], f[2 * x + 1]);
    }

    int get (int x, int l, int r, int u, int v) {
        if (l > v || r < u)
            return INF;
        if (u <= l && r <= v)
            return f[x];
        int m = (l + r) / 2;
        int minL = get(2 * x, l, m, u, v);
        int minR = get(2 * x + 1, m + 1, r, u, v);
        return min(minL, minR);
    }   

} st;


int n, q;
void run_case() {
    cin >> n >> q;
    st.init(n);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        st.update(1, 1, n, i, x);
    }

    for (int Q = 1; Q <= q; Q++) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        if (cmd == 1) 
            st.update(1, 1, n, x + 1, y);
        else
            cout << st.get(1, 1, n, x + 1, y) << "\n";
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

