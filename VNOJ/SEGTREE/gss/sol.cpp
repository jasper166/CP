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
const int MAX = 5e4 + 5;

int n, q;
int a[MAX];

struct Node {
    int suf, pre, sum, ans;
    Node () {
        suf = pre = sum = ans = 0;
    } 
} NEUTRAL;

struct SegTree {
    Node *f;
    void init(int N) {
        f = new Node[4 * N + 1];
        NEUTRAL.suf = NEUTRAL.pre = NEUTRAL.ans = -INF;
    }

    Node single(int val) {
        Node z;
        z.suf = z.pre = z.sum = z.ans = val;
        return z;
    } 


    Node merge(Node l, Node r) {
        Node z;
        z.sum = l.sum + r.sum;
        z.suf = max(r.suf, l.suf + r.sum);
        z.pre = max(l.pre, l.sum + r.pre);
        z.ans = max({l.ans, r.ans, l.suf + r.pre});
        return z;
    } 

    void build(int x, int l, int r) {
        if (l == r) {
            f[x] = single(a[l]);
            return;
        }
        int m = (l + r) / 2;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        f[x] = merge(f[2 * x], f[2 * x + 1]);
    }

    Node query(int x, int l, int r, int u, int v) {
        if (l > v || r < u)
            return NEUTRAL;
        if (u <= l && r <= v) 
            return f[x];
        int m = (l + r) / 2;
        Node sl = query(2 * x, l, m, u, v);
        Node sr = query(2 * x + 1, m + 1, r, u, v);
        return merge(sl, sr);
    }

} st;


void run_case() {
    cin >> n;
    st.init(n);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> q;
    st.build(1, 1, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(1, 1, n, l, r).ans << "\n";
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

