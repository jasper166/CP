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

struct Node {
    int val;
};

struct SegTree {
    Node *f;
    int n;

    void init (int N) {
        f = new Node[4 * N + 1];
        n = N;
    }

    Node merge (Node x, Node y) {
        return {max(x.val, y.val)};
    }

    void update (int x, int l, int r, int i, int val) {
        if (i < l || i > r)
            return;
        if (i == l && i == r) {
            f[x] = {val};
            return;
        }

        int m = (l + r) / 2;
        update(2 * x, l, m, i, val);
        update(2 * x + 1, m + 1, r, i, val);

        f[x] = merge(f[2 * x], f[2 * x + 1]);
    }

    int find_above2(int x, int k, int j, int l, int r) {
        if (r < j)
            return 0;
        if (f[x].val < k) 
            return 0;
        if (r == l)
            return l;
        int m = (l + r) / 2;
        int pos = find_above2(2 * x, k, j, l, m);
        if (pos == 0)
            pos = find_above2(2 * x + 1, k, j, m + 1, r);
        return pos;
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

    for (int i = 1; i <= q; i++) {
        int cmd, u, v;
        cin >> cmd >> u >> v;
        if (cmd == 1) {
            st.update(1, 1, n, u + 1, v);
        }
        else {
            cout << st.find_above2(1, u, v + 1, 1, n) - 1 << "\n";
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

