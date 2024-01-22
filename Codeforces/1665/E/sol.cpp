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
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int B = 31;

int n, q;
int a[N], ans[N];
vector <pii> qs[N];
multiset <int> st[N];
// 
int func(multiset <int> &l, multiset <int> &r) {
    int ret = INF;
    vector <int> c;
    for (auto x : l) c.push_back(x);
    for (auto x : r) c.push_back(x);
    sort(c.begin(), c.end());
    // debug(c);
    int sz = min((int) c.size(), B);
    for (int i = 0; i < sz; ++i)
        for (int j = i + 1; j < sz; ++j)
            ret = min(ret, c[i] | c[j]);
    return ret;
}
 
 
void dnc(int l, int r, vector <vector <int>> &queries) {
    if (l > r || queries.empty())
        return;
 
    int m = (l + r) / 2;
    vector <vector <int>> lhs, rhs;
    for (auto x : queries) {
        // l, r, id;
        if (l <= x[0] && x[1] <= m) {
            lhs.push_back(x);
            continue;
        }
        if (m + 1 <= x[0] && x[1] <= r) {
            rhs.push_back(x);
            continue;
        }
        if (x[0] <= m && m <= x[1]) {
        	qs[x[0]].push_back({x[1], x[2]});
        	continue;
        }
    }
    // Take min elements from right, maintain max size <= 31 
    multiset <int> S;
    for (int i = m + 1; i <= r; ++i) {
        S.insert(a[i]);
        if (S.size() > B) S.erase(--(S.end()));
        st[i] = S;
    }   
    // Take min elements from left and solve queries
    S.clear();
    for (int i = m; i >= l; --i) {
        S.insert(a[i]);
        if (S.size() > B) S.erase(--(S.end()));
        // S : (l, m), st[rx] : (m + 1, rx);
        for (auto [rx, id] : qs[i]) {
            ans[id] = func(S, st[rx]);
            // debug(S, st[rx]);
            // debug(ans[id], id, l, r, i, rx);
        }
    }
 
    for (int i = l; i <= r; ++i) {
        st[i].clear();
        qs[i].clear();
    }
 
    dnc(l, m, lhs);
    dnc(m + 1, r, rhs);
}
 
void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> q;
    vector <vector <int>> todo;
    for (int i = 1; i <= q; ++i) {
        int l, r; 
        cin >> l >> r;
        todo.push_back({l, r, i});
    }
 
    dnc(1, n, todo);
    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << "\n";
        ans[i]= 0;
    }
 
}
/*
    Minimize a(i) | a(j) ? -> answer will lies in range of at most 31 minimum elements
    001100
    010000
    111000
    Apply DnC to solve:
        for each query in vector queries
        if (l < r < m) -> on the left
        if (m < l < r) -> save for solving on the right
        (l < m < r) -> we can solve this at current step
 
    O((n + q) * logn * (31 ^ 2));
*/

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
