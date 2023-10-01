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
const int MAX = 1e6 + 5;

int n, q;

struct SegTree {
    int *f;
    void build(int N) {
        f = new int[2 * N + 1];
        for (int i = 0; i < n; i++)
            f[i + n] = INF;
        for (int x = n - 1; x; x--)
            f[x] = min(f[x >> 1], f[x >> 1 | 1]);
    }

    void modify(int x, int val) {
        f[x + n] = val;
        x += n;
        for (; x > 1; x >>= 1)
            f[x >> 1] = min(f[x], f[x ^ 1]); 
    }

    int query(int l, int r, int p) {
        int sl = INF, sr = INF;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                sl = min(sl, f[l++]);
            if (r & 1)
                sr = min(f[--r], sr);
        }
        return min(sl, sr);
    }

} st;
void run_case() {
    cin >> n >> q;
    st.build(n);
    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int x, y; cin >> x >> y;
            st.modify(x, y);
        }
        else {
            int l, r, p; cin >> l >> r >> p;
            r++;
            int cnt = 0, cur;    
            do {
                cur = st.query(l, r);
            } while (cur)

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

