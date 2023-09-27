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
#define debug(...) 42
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

struct SegTree {
    int *f;
    int n;
    void init (int N) {
        f = new int[4 * N + 1];
        n = N;
    //    for (int i = 0; i <= 4 * N; i++) f[i] = 0;
    }

    void update (int x, int l, int r, int i, int val) {
        if (i < l || i > r)
            return;
        if (l == r) {
            f[x] = val;
            return;
        }

        int m = (l + r) / 2;
        update(2 * x, l, m, i, val);
        update(2 * x + 1, m + 1, r, i, val);
        f[x] = (f[2 * x] + f[2 * x + 1]); 
    }
    // find from right to left
    int find (int x, int k, int l ,int r) {
        if (r == l)
            return r;
        int s = f[2 * x + 1];
        int m = (l + r) / 2;
        if (k <= s)
            return find(2 * x + 1, k, m + 1, r);
        else
            return find(2 * x, k - s, l, m);
    }

} st;


int a[MAX], ans[MAX];
int n;
void run_case() {
    cin >> n;
    st.init(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        st.update(1, 1, n, i, 1);
    }
    for (int i = n; i >= 1; i--) {
        int pos = st.find(1, a[i] + 1, 1, n);
        // debug(pos);
        ans[i] = pos;
        st.update(1, 1, n, ans[i], 0);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

