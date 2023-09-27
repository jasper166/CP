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
    ll inv;
    int cnt[42];
    Node () {
        inv = 0;
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
        Node res = Node();
        res.inv = l.inv + r.inv;
        for (int x = 1; x <= 40; x++) {
            res.cnt[x] += (l.cnt[x] + r.cnt[x]);
        }
        for (int x = 1, s = 0; x <= 40; x++) {
            res.inv += 1LL * l.cnt[x] * s;
            s += r.cnt[x];
        }
        return res;
    }

    void build(int x, int l, int r) {
        if (l == r) {
           f[x].inv = 0;
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
            Node c;
            f[x] = c;
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
            Node res;
            return res;
        }
        int m = (l + r) / 2;
        Node invL = get(2 * x, l, m, u, v);
        Node invR = get(2 * x + 1, m + 1, r, u, v);
        return merge(invL, invR);
    }
};


void run_case() {
    cin >> n >> q;
    SegTree st;
    st.init(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    st.build(1, 1, n);
    while (q--) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        if (cmd == 1) {
            Node res = st.get(1, 1, n, x, y);
            cout << res.inv << "\n"; 
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

