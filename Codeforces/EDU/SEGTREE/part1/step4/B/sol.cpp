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
// const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

struct Node {
    int f[2][2];
    Node() {
        memset(f, 0, sizeof f);
    };
} a[MAX];

int MOD, n, q;

Node read() {
    Node res;
    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < 2; j++) cin >> res.f[i][j];
    return res;
}

struct SegTree {
    Node *f;
    int n;

    void init(int N) {
        f = new Node[4 * N + 1];
        n = N;
    }

    Node merge(Node x, Node y) {
        Node res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                   res.f[i][j] = (res.f[i][j] + (1LL * x.f[i][k] * y.f[k][j]) % MOD) % MOD;
               }
           }
       }
       return res;
    }

    void modify(int x, int l, int r, int i, Node val) {
        if (i > r || i < l)
            return;
        if (l == r) {
            f[x] = val;
            return;
        }
        int m = (l + r) / 2;
        modify(2 * x, l, m, i, val);
        modify(2 * x + 1, m + 1, r, i, val);
        f[x] = merge(f[2 * x], f[2 * x + 1]);
    }

    Node get(int x, int l, int r, int u, int v) {
        if (u <= l && r <= v)
            return f[x];
        if (r < u || l > v) {
            Node res;
            res.f[0][0] = res.f[1][1] = 1;
            return res;
        }

        int m = (l + r) / 2;
        Node L = get(2 * x, l, m, u, v);
        Node R = get(2 * x + 1, m + 1, r, u, v);
        return (merge(L, R));
    }

 };


void run_case() {
    cin >> MOD >> n >> q;
    SegTree st;
    st.init(n);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        st.modify(1, 1, n, i, a[i]);
    }
    
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        Node res = st.get(1, 1, n, l, r);
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) cout << res.f[x][y] << " \n"[y == 1];
        }
        cout << "\n";
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

