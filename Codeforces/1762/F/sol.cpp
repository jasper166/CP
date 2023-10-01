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
const int N = 5e5 + 5;

struct Fenwick {
    int n;
    vector <ll> f;
    Fenwick(int _n) : n(_n), f(_n + 5, 0) {};
    void add(int x, int val) {
        for (; x <= n; x += x & -x) f[x] += val;
    }
    ll qry(int x) {
        ll ans = 0;
        for (; x; x -= x & -x)
            ans += f[x];
        return ans;
    }
    ll qry(int l, int r) {
        if (l > r) return 0;
        return qry(r) - qry(l - 1);
    }
};

struct SegmentTree {
    int n;
    vector <int> f;
    SegmentTree(int _n) : n(_n), f(_n * 2 + 5, INF) {};
    int merge(int l, int r) { return min(l, r); }
    void upd(int x, int val) {
        f[x += n] = val;
        for (; x; x >>= 1)
            f[x >> 1] = merge(f[x], f[x ^ 1]);
    }
    int qry(int l, int r) {
        int ql = INF, qr = INF;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                ql = merge(ql, f[l++]);
            if (r & 1)
                qr = merge(f[--r], qr);
        }
        return merge(ql, qr);
    }
};

int n, k;
int a[N];
Fenwick bit(N);
SegmentTree st(N);
ll cal() {    
    vector <ll> dp(n + 5, 0);
    ll ans = 0; 
    for (int i = n; i >= 1; --i) {
        int j = st.qry(a[i] + 1, a[i] + k);
        // debug(j);
        if (i < j && j <= n)
            dp[i] = dp[j] + bit.qry(a[i] + 1, a[j]);   
        bit.add(a[i], 1);
        st.upd(a[i], i);
        ans += dp[i];
    }
    for (int i = 1; i <= n; ++i) {
        bit.add(a[i], -1);
        st.upd(a[i], INF);
    }
    return ans;
}
int cnt[N];
void run_case() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    // case 1: -k <= a(i) - a(j) <= -1;
    ll ans = 0;
    ans += cal();
    // case 2 : a(i) == a(j)
    for (int i = 1; i <= n; ++i) {
        cnt[a[i]]++;
        ans += cnt[a[i]];
    }
    // case 3 : 1 <= a(i) - a(j) <= k;
    reverse(a + 1, a + 1 + n);
    ans += cal();
    cout << ans << "\n";
    for (int i = 1; i <= n; ++i) cnt[a[i]] = 0;
}

/*
    1. ai(j) - ai(j + 1) <= k
    If we have sequence (l, ix, .. r);
    - Two adjacent element differ at most k.
    - In this case, a(l) < ..a(ix).. < a(r).
    if j is the next index such a(j) lies in range(ai + 1, ai + k) and j > i;
        dp(i) = dp(j) + f(ai + 1, aj);
    f(l, r) : counting index j > i which l <= a(j) <= r. 
*/

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}