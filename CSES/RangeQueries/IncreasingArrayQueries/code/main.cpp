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
const int MAX = 2e5 + 5;
const int LOG = 22;
int n, q;
int a[MAX];
ll prf[MAX];
ll sum[LOG][MAX];
int jmp[LOG][MAX];

void run_case() {
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prf[i] = prf[i - 1] + a[i];
    }

    stack <int> st;
    for (int i = n; i >= 1; --i) {
        while (!st.empty() && (a[st.top()] <= a[i]))
            st.pop();
        int x = (st.empty()? n + 1 : st.top());
        jmp[0][i] = x;
        sum[0][i] = 1ll * (x - i) * a[i];
        st.push(i);
    }

//    // up[k][u] = up[k - 1][up[k - 1][u]]
// w2 ^
    jmp[0][n + 1] = n + 1;
    for (int k = 1; k < LOG; ++k) {
        for (int i = 1; i <= n + 1; ++i) {
            sum[k][i] = sum[k - 1][i] + sum[k - 1][jmp[k - 1][i]];
            jmp[k][i] = jmp[k - 1][jmp[k - 1][i]];
        }
    }
    for (int k = 0; k < LOG; ++k) {
        debug(jmp[k][1]);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        debug(jmp[0][l]);
//        debug(l, r);
        ll sub = prf[r] - prf[l - 1];
        ll ans = 0;
        for (int k = LOG - 1; k >= 0; --k) {
            if (jmp[k][l] <= r) {
                ans += sum[k][l];
                l = jmp[k][l];
                debug(l);
            }
        }
        debug(ans, sub);
        ans += 1ll * (r - l + 1) * a[l];
        cout << ans - sub << "\n";

    }

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
