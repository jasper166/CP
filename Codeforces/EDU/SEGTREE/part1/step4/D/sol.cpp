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
const int MAX = 1e5 + 5;

int n, q;
int a[MAX];

struct Node {
    int cnt[42];
    int diff;
    Node () {
        diff = 0;
        memset(cnt, 0, sizeof cnt);
    }
};

struct SegTree {
    Node *f;
    int n;
    void init(int N) {
        f = new Node[4 * N + 1];
        n = N;
    }

    Node merge(Node l, Node r) {
        Node z = Node();
        for (int i = 1; i <= 40; i++) {
            z.cnt[i] += l.cnt[i] + r.cnt[i];
            z.diff += (l.cnt[i] || r.cnt[i]);
        }
        return z;
    }

    void build(int x, int l, int r) {
        if (l == r) {
            // f[x] = Node();
            f[x].diff = 1;
            f[x].cnt[a[l]] = 1;
            return;
        }
        int m = (l + r) / 2;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        f[x] = merge(f[2 * x], f[2 * x + 1]);
    }

    void update(int x, int l, int r, int i, int val) {
        if (i > r || i < l)
            return;
        if (l == r) {
            f[x] = Node();
            f[x].diff = 1;
            f[x].cnt[val] = 1;
            return;
        }
        int m = (l + r) / 2;
        update(2 * x, l, m, i, val);
        update(2 * x + 1, m + 1, r, i, val);
        f[x] = merge(f[2 * x], f[2 * x + 1]);
    }

    Node get(int x, int l, int r, int u, int v) {
        if (u <= l && r <= v)
            return f[x];
        if (l > v || r < u) {
            return Node();
        }
        int m = (l + r) / 2;
        Node sL = get(2 * x, l, m, u, v);
        Node sR = get(2 * x + 1, m + 1, r, u, v);
        return merge(sL, sR);
    }
} st;


void run_case() {
    cin >> n >> q;
    st.init(n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    st.build(1, 1, n);
    
    while (q--) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        if (cmd == 1) {
            cout << st.get(1, 1, n, x, y).diff << "\n";
        }
        else {
            a[x] = y;
            st.update(1, 1, n, x, a[x]);
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

