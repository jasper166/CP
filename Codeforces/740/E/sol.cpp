#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 3e5 + 5;

struct Data {
    ll suffix, prefix, ans;
    Data(int a = 0, int b = 0, int c = 0): suffix(a), prefix(b), ans(c) {};
};
struct SegmentTree {
    vector <Data> f;
    vector <ll> a; 
    int n;

    int sign(ll val) {
        return (val? ((val > 0)? 1 : -1) : 0);
    }
    SegmentTree(int _n) : f(_n * 4 + 5), a(_n + 5), n(_n) {};

    void merge(int x, int l, int r) {
        int m = (l + r) / 2;
        f[x].ans = max(f[x << 1].ans, f[x << 1 | 1].ans);
        // can merge from left and right if both value are not zero
        f[x].prefix = f[x << 1].prefix;
        f[x].suffix = f[x << 1 | 1].suffix;
        if (a[m] && a[m + 1] && sign(a[m]) >= sign(a[m + 1])) {
            f[x].ans = max(f[x].ans, f[x << 1].suffix + f[x << 1 | 1].prefix);
            // merge prefix and suffix
            if (f[x << 1].prefix == m - l + 1)
                f[x].prefix += f[x << 1 | 1].prefix;     
            if (f[x << 1 | 1].suffix == r - m)
                f[x].suffix += f[x << 1].suffix;  
        }
        f[x].ans = max({f[x].ans, f[x].prefix, f[x].suffix});
    }
    void upd(int x, int l, int r, int pos, ll val) {
        if (pos > r || pos < l) return;
        if (l == r && l == pos) {
            // two adjacent are equal
            if (val == 0) 
                f[x] = {0, 0, 0};
            else 
                f[x] = {1, 1, 1};
            return;
        }
        int m = (l + r) / 2;    
        upd(x << 1, l, m, pos, val);
        upd(x << 1 | 1, m + 1, r, pos, val);
        merge(x, l, r);
    }
    void upd(int pos, int val) { upd(1, 1, n, pos, val); }
    int qry() { return f[1].ans + 1; }
};


int n, q;
int a[N];

void run_case() {
    cin >> n;
    SegmentTree st(n - 1);

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        st.a[i] = a[i + 1] - a[i];
        st.upd(i, st.a[i]);
    }

    
    cin >> q; 
    while (q--) {
        int l, r, d; cin >> l >> r >> d;
        if (l > 1) {
            st.a[l - 1] += d;
            st.upd(l - 1, st.a[l - 1]);
        }
        if (r <= n) {
            st.a[r] -= d;
            st.upd(r, st.a[r]);
        }
        // debug(st.a);
        cout << st.qry() << "\n";
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


