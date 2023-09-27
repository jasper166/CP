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
    int n;
    
    void build(int N) {
        f = new int[2 * N + 1];
        n = N;
        for (int i = 0; i <= 2 * N; i++) f[i] = 0;
        for (int i = 1; i <= n; i++) 
            f[i + n] = a[i]; 
        for (int i = n; i >= 1; i--) 
            f[i] = f[i << 1] + f[i << 1 | 1];
    }

    void modify(int x, int val) {
        f[x + n] = val;
        x += n;
        for (; x > 1; x >>= 1) {
            f[x >> 1] = f[x] + f[x ^ 1];
        }
    }

    int get(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res += f[l++];
            if (r & 1)
                res += f[--r];
        }
        return res;
    }
    

} st;


void run_case() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];    
        if (i % 2 == 0) 
            a[i] *= -1;
    }
    st.build(n);
    // cout << st.get(1, 3) << "\n";
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        if (cmd) {
            // in range of [l, r)
            int ans = st.get(x, y + 1);   
            if (x % 2 == 0) ans *= -1;
            cout << ans << "\n";
        }
        else {
            if (x % 2 == 0) y *= -1;
            st.modify(x, y);
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

