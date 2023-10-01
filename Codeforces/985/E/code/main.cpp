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
const int MAX = 5e5 + 5;

struct Fenwick {
    vector <int> f;
    int n;
    Fenwick (int N) : n(N), f(N + 5) {};
    void upd(int x, int val) {
        for (; x <= n; x += x & -x)
            f[x] += val;
    }
    int qry(int x) {
        int ans = 0;
        for (; x; x -= x & -x) ans += f[x];
        return ans;
    }
    int qry(int l, int r) {
        if (l > r) return 0;
        return qry(r) - qry(l - 1);
    }
};

int n, k, d;
int a[MAX];
bool dp[MAX];
// [1...i] is valid?
void run_case() {
    cin >> n >> k >> d;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    Fenwick bit(n);

    int pos = 1;
    for (int i = 1; i <= n; ++i) {
        if (i >= k && a[i] - a[1] <= d) {
            dp[i] = 1;
            bit.upd(i, 1);
            continue;
        }
        while (a[i] - a[pos + 1] > d) ++pos;
        dp[i] = (bit.qry(pos, i - k) > 0);
        bit.upd(i, dp[i]);
    }

    cout << (dp[n]? "YES\n" : "NO\n");
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
