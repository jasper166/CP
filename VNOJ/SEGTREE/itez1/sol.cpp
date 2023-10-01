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
    void build(int N) {
        f = new int[2 * N + 1];
        for (int i = 0; i <= 2 * n; i++) f[i] = -INF;
        for (int i = 0; i < n; i++)
            f[i + n] = a[i];
        for (int i = n - 1; i; i--)
            f[i] = max(f[i << 1], f[i << 1 | 1]);
    }

    void modify(int x, int val) {
        f[x + n] = val;
        for (x += n; x; x >>= 1)
            f[x >> 1] = max(f[x], f[x ^ 1]);
    }

    int get(int l, int r) {
        int ml = -INF, mr = -INF;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ml = max(ml, f[l++]);
            if (r & 1) mr = max(f[--r], mr);
        }
        return max(ml, mr);
    }
};

void run_case() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    SegTree st;
    st.build(n);
    cin >> q;
    while (q--) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        x--;
        if (cmd == 1) 
            st.modify(x, y);
        else
            cout << st.get(x, y) << "\n";
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
