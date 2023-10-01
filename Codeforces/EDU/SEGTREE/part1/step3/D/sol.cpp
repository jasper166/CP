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
const int MAX = 1e6 + 5;

struct SegTree {
    int *f;
    void init (int N) {
        f = new int[4 * N + 1];
        for (int i = 0; i <= 4 * N; i++) f[i] = 0;
    }
    
    void update (int x, int l, int r, int i, int val) {
        if (i < l || i > r)
            return;
        if (r == l) {
            f[x] = val;
            return;
        }
        int m = (l + r) / 2;
        update(2 * x, l, m, i, val);
        update(2 * x + 1, m + 1, r, i, val);
        f[x] = f[2 * x] + f[2 * x + 1]; 
    }

    int get (int x, int l, int r, int u, int v) {
        if (r < u || l > v)
            return 0;
        if (u <= l && r <= v)
            return f[x];
        int m = (l + r) / 2;
        int sumL = get(2 * x, l, m, u, v);
        int sumR = get(2 * x + 1, m + 1, r, u, v);
        return (sumL + sumR);
    }
    
} st;

int n;
void run_case() {
    cin >> n;
    st.init(2 * n);
    // x .. y .. x .. y
    vector <int> ans(n + 1, 0), pos(n + 1, -1), a(2 * n + 1);

    for (int i = 1; i <= 2 * n; i++) cin >> a[i];

    for (int i = 1; i <= 2 * n; i++) {
        if (pos[a[i]] == -1) {
            pos[a[i]] = i;
            st.update(1, 1, 2 * n, pos[a[i]], 1);
        }
        else {
            st.update(1, 1, 2 * n, pos[a[i]], 0);
            ans[a[i]] += st.get(1, 1, 2 * n, pos[a[i]], i);
        }
    }
    //y ... x ... y...x
    st.init(2 * n);
    pos.assign(n + 1, -1);
    for (int i = 2 * n; i >= 1; i--) {
        if (pos[a[i]] == -1) {
            pos[a[i]] = i;
            st.update(1, 1, 2 * n, pos[a[i]], 1);
        }
        else {
            st.update(1, 1, 2 * n, pos[a[i]], 0);
            ans[a[i]] += st.get(1, 1, 2 * n, i, pos[a[i]]);
        }
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

