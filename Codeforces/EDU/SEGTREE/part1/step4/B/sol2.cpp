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

int MOD, n, q;

struct Node {
    int x[2][2];
    Node() : x{{1, 0}, {0, 1}} {};
} a[MAX];

Node Multiply(const Node& a, const Node& b) {
    Node c;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            c.x[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                c.x[i][j] += (1LL * a.x[i][k] * b.x[k][j]) % MOD;
                c.x[i][j] %= MOD;
            }
        }
    return c;
}

struct SegTree {
    Node *f;
    int n;
    void build(int N) {
        f = new Node[2 * N + 1];
        n = N;
        for (int i = 0; i < n; i++)
            f[i + n] = a[i];
        for (int i = n - 1; i >= 1; i--) 
            f[i] = Multiply(f[i << 1], f[i << 1 | 1]);   
    }

    void modify(int x, Node val) {
        f[x + n] = val;
        x += n;
        for (; x > 1; x >>= 1)
            f[x >> 1] = Multiply(f[x], f[x ^ 1]); 
    }

    Node get(int l, int r) {
        Node sL, sR;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) sL = Multiply(sL, f[l++]);
            if (r & 1) sR = Multiply(f[--r], sR); 
        }
        return Multiply(sL, sR);
    }
};

void run_case() {
    cin >> MOD >> n >> q;
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < 2; x++)
            for (int y = 0; y < 2; y++)
                cin >> a[i].x[x][y];
    }

    // for (int i = 0; i < n; i++) {
    //     for (int x = 0; x < 2; x++)
    //         for (int y = 0; y < 2; y++)
    //             cout << a[i].x[x][y] << " \n"[y == 1];
    //     cout << "\n";
    // }

    SegTree st;
    st.build(n);
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        l--;
        // taking value of [l, r)
        Node res = st.get(l, r);
        for (int x = 0; x < 2; x++)
            for (int y = 0; y < 2; y++)
                cout << res.x[x][y] << " \n"[y == 1];
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

