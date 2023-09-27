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

struct SegTree {
    int *f;
    void init(int N) {
        f = new int[4 * N + 1];
        for (int i = 1; i <= 4 * N; i++) f[i] = INF;
    }

    int merge(int x, int y) {
        return min(x, y);
    }

    void update(int x, int l, int r, int i, int val) {
        if (i > r || i < l)
            return;
        if (l == r) {
            f[x] = val;
            return;
        }
        int m = (l + r) / 2;
        update(2 * x, l, m, i, val);
        update(2 * x + 1, m + 1, r, i, val);
        f[x] = merge(f[2 * x], f[2 * x + 1]);
    }

    int query(int x, int l, int r, int u, int v, int p) {
        if (l > v || r < u || f[x] > p)
            return 0;
        if (l == r) {
            update(1, 1, n, l, INF);
            return 1;
        }
        int m = (l + r) / 2;
        int sl = query(2 * x, l, m, u, v, p);
        int sr = query(2 * x + 1, m + 1, r, u, v, p);
        return (sl + sr); 
    }

};


void run_case() {
    cin >> n >> q;
    SegTree st;
    st.init(n);
    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int i, x;
            cin >> i >> x;
            st.update(1, 1, n, i + 1, x);
        }
        else {
            int l, r, p;
            cin >> l >> r >> p;
            cout << st.query(1, 1, n, l + 1, r, p) << "\n";
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

