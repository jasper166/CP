#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

vector <int> ans;
struct SegmentTree {
    vector <int> f, a;
    SegmentTree(int N) : f(N * 4 + 5), a(N + 5) {};

    void build(int x, int l, int r) {
        if (l == r) {
            f[x] = 1;
            return;
        }
        int m = (l + r) >> 1;
        build(x << 1, l, m);
        build(x << 1 | 1, m + 1, r);
        f[x] = f[x << 1] + f[x << 1 | 1];
    }

    void qry(int x, int l, int r, int k) {
        if (l == r) {
            ans.push_back(a[l]);
            f[x]--;
            return;
        }
        if (k > f[x])
            return;
        int m = (l + r) >> 1;
        if (f[x << 1] >= k)
            qry(x << 1, l, m, k);
        else
            qry(x << 1 | 1, m + 1, r, k - f[x << 1]);
        f[x] = f[x << 1] + f[x << 1 | 1];
    }

};

int n;
void run_case() {
    cin >> n;
    SegmentTree st(n);
    for (int i = 1; i <= n; ++i) cin >> st.a[i];
    st.build(1, 1, n);
    //st.qry(1, 1, n, 3);
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        st.qry(1, 1, n, x);
    }
    for (auto x : ans) cout << x << " ";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
