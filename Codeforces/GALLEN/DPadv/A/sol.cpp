#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using pii = pair < int, int >;

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

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int n;
int a[MAX];
ll f[MAX], pref[MAX];
int lt[MAX], rt[MAX];
/*
    f[0] = 0
    - f[i] = min(f[j] + sum(i, j)) : l(i) <= j <= r(i);
    f[i] = pref[i] + min(f[j] - s[j - 1]);
    - update
*/
struct SegmentTree {
    vector <ll> st;
    int n;
    SegmentTree (int N) {
        n = N;
        st.assign(2 * N + 5, LINF);
    }

    void upd(int x, int val) {
        st[x + n] = val;
        for (x += n; x; x >>= 1)
            st[x >> 1] = min(st[x], st[x ^ 1]); 
    }

    ll qry(int l, int r) {
        ll qL = LINF, qR = LINF;
        // r += n + 1 if close interval;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                qL = min(qL, st[l++]);
            if (r & 1)
                qR = min(st[--r], qR);
        }
        return min(qL, qR);
    }
};

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for (int i = 2; i <= n; i++) {
        cin >> lt[i] >> rt[i];
    }
    SegmentTree st(n); 
    // debug(st.qry(2, 2));
    f[1] = 0ll;
    st.upd(1, 0);
    for (int i = 2; i <= n; i++) {
        f[i] = pref[i] + st.qry(lt[i], rt[i]);
        st.upd(i, f[i] - pref[i - 1]);
    } 
    for (int i = 1; i <= n; i++) cout << f[i] << " \n"[i == n];
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


