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

struct BIT {
    int f[MAX];
    void upd(int x, int val) {
        for (; x < MAX; x += x & -x)
            f[x] = (f[x] + val) % MOD;
    }
    int qry(int x) {
        int ans = 0;
        for (; x; x -= x & -x)
            ans = (ans + f[x]) % MOD;
        return ans;
    }
} bit;

int n;
int a[MAX], f[MAX];
void run_case() {
    cin >> n;
    vector <int> b;
    b.push_back(0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        debug(a[i]);
        f[i] = (1 + bit.qry(a[i] - 1)) % MOD;
        bit.upd(a[i], f[i]);
        ans = (ans + f[i]) % MOD;
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
//    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
