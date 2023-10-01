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
    ll *f;
    int n;

    void init (int N) {
        f = new ll[4 * N + 1];
        n = N;
    }

    void update (int root, int l, int r, int i, int val) {
        if (r < i || i < l)
            return;
        if (i == r && i == l) {
            f[root] = val;
            return;
        }
        int m = (l + r) / 2;
        update(2 * root, l, m, i, val);
        update(2 * root + 1, m + 1, r, i, val);
        f[root] = f[2 * root] + f[2 * root + 1];
    };

    ll get (int root, int l, int r, int u, int v) {
        if (l > v || r < u)
            return 0;
        if (u <= l && r <= v) 
            return f[root];
        int m = (l + r) / 2;
        ll sumL = get(2 * root, l, m, u, v);
        ll sumR = get(2 * root + 1, m + 1, r, u, v);
        return (sumL + sumR);
    }
} st;

int n, q;
void run_case() {
    cin >> n;
    st.init(n);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        cout << st.get(1, 1, n, x, n) << " \n"[i == n];
        st.update(1, 1, n, x, 1);
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

