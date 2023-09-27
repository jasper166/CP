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
const int MAX = 1e6 + 5;
const int K = 22;

ll ans;
int lg[MAX];
int f[K][MAX];
int n, a[MAX];
int rhs[MAX], lhs[MAX];

void prepare() {
    lg[1] = 0;
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= n; ++i)
        f[0][i] = i;
    for (int k = 1; k < K; ++k) {
        int step = 1 << k;
        for (int i = 1; i + step <= n + 1; ++i) {
            int l = f[k - 1][i];
            int r = f[k - 1][i + (1 << (k - 1))];
            f[k][i] = (a[r] > a[l])? r : l;
        }
    }
    stack <int> st1;
    for (int i = 1; i <= n; ++i) {
        while (!st1.empty() && a[st1.top()] >= a[i])
            st1.pop();
        lhs[i] = st1.empty()? 0 : st1.top();
        st1.push(i);
    }
    stack <int> st2;
    for (int i = n; i >= 1; --i) {
        while (!st2.empty() && a[st2.top()] >= a[i])
            st2.pop();
        rhs[i] = st2.empty()? n + 1 : st2.top();
        st2.push(i);
    }
//    debug(n);
//    for (int i = 1; i <= n; ++i) {
//        debug(a[i], lhs[i], rhs[i]);
//    }
}

int get(int l, int r) {
    int k = lg[r - l + 1];
    int x = f[k][r - (1 << k) + 1];
    int y = f[k][l];
    return (a[x] > a[y]? x : y);
}

void solve(int l, int r) {
    if (l >= r)
        return;
    int p_max = get(l, r);
//    debug(p_max);
    // to the right
    int m = (l + r) >> 1;
    if (p_max > m) {
        int p_min = p_max;
        for (int i = p_max; i <= r; ++i) {
            if (a[i] < a[p_min])
                p_min = i;
            ans += max(lhs[p_min], l - 1) - l + 1;
        }
    }
    else {
        int p_min = p_max;
        for (int i = p_max - 1; i >= l; --i) {
            if (a[i] < a[p_min])
                p_min = i;
            ans += min(rhs[p_min] - 1, r) - p_max + 1;
        }
    }
    solve(l, p_max - 1);
    solve(p_max + 1, r);
}

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    prepare();
    solve(1, n);
    cout << ans << "\n";
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
