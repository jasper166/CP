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

struct Node {
    int sum;
};

struct SegTree {
    Node *f;
    int n;

    void init (int N) {
        n = N;
        f = new Node[4 * N + 1];
    }

    Node merge (Node x, Node y) {
        return {x.sum + y.sum};
    }

    void update (int x, int l, int r, int i, int val) {
        if (r < i || i < l)
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

    Node get (int x, int l, int r, int u, int v) {
        if (r < u || l > v)
            return {0};
        if (u <= l && r <= v)
            return f[x];

        int m = (l + r) / 2;
        Node L = get(2 * x, l, m, u, v);
        Node R = get(2 * x + 1, m + 1, r, u, v);
        return merge(L, R);
    }
    // find from left to right
    int find (int x, int k, int l, int r) {
        if (r == l)
            return l;
        int m = (l + r) / 2;
        // check left node
        int s = f[2 * x].sum;
        if (k <= s)
            return find(2 * x, k, l, m);
        else
            return find(2 * x + 1, k - s, m + 1, r);
    }

} st;

int n, q;
int a[MAX];
void run_case() {
    cin >> n >> q;
    st.init(n);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        st.update(1, 1, n, i, a[i]);
    }

    for (int i = 1; i <= q; i++) {
        int cmd, x;
        cin >> cmd >> x;
        ++x;
        if (cmd == 1) {
            a[x] = 1 ^ (a[x] == 1);
            st.update(1, 1, n, x, a[x]);
        }
        else 
            cout << (st.find(1, x, 1, n) - 1) << "\n";
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

