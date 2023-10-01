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
    ll *f;

    ll merge(ll x, ll y) {
        return (x + y);
    }

    void build(int N) {
        f = new ll[2 * N + 1];
        fill(f, f + 2 * N, 0LL);
        // for (int i = n - 1; i; i--)
        //     f[i] = merge(f[i << 1], f[i << 1 | 1]);
    }

    void modify(int x, int val) {
        for (f[x += n] = val; x; x >>= 1)
            f[x >> 1] = merge(f[x], f[x ^ 1]);
    }

    ll get(int l, int r) {
        ll ml = 0, mr = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ml = merge(ml, f[l++]);
            if (r & 1) mr = merge(f[--r], mr);
        }
        return merge(ml, mr);
    }
};

void run_case() {
    cin >> n >> q;
    SegTree st;
    st.build(n);
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

