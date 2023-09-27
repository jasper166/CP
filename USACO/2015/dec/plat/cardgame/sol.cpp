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
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 5e4 + 5;

int n;
int a[N];
int prf[N], suf[N];

void run_case() {
    cin >> n;
    vector <bool> used(2 * n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        used[a[i]] = 1;
    }
    set <int> lb, rb;
    for (int i = 1; i <= 2 * n; ++i) {
        if (!used[i]) {
            lb.insert(i);
            rb.insert(i);
        }
    }

    // Use minimum possible card, which is greater than a(i);
    for (int i = 1; i <= n; ++i) {
        auto x = lb.lower_bound(a[i]);
        int add = 0;
        if (x != lb.end()) {
            lb.erase(x);
            add = 1;
        }
        prf[i] = prf[i - 1] + add;
    }

    // Use maximum possible card, which is lesser than a(i);
    for (int i = n; i >= 1; --i) {
        auto x = rb.lower_bound(a[i]);
        int add = 0;
        if (x != rb.begin()) {
            rb.erase(prev(x));
            add = 1;
        }
        suf[i] = suf[i + 1] + add;
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i)
        ans = max(ans, prf[i] + suf[i + 1]);
    cout << ans << "\n";
}

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    setIO("cardgame");
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
