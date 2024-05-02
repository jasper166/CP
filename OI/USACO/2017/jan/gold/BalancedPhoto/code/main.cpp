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

struct BIT {
    vector <int> f;
    int N;
    BIT(int _N): N(_N), f(_N + 5) {};

    void add(int x, int val) {
        for (; x > 0; x -= x & -x)
            f[x] += val;
    }

    int qry(int x) {
        int ans = 0;
        for (; x <= N; x += x & -x)
            ans += f[x];
        return ans;
    }
};

int n, a[MAX];
int lf[MAX], rt[MAX];

void run_case() {
    cin >> n;
    vector <int> b;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());

    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;

    BIT bit1(n);
    for (int i = 1; i <= n; ++i) {
        lf[i] = bit1.qry(a[i] + 1);
//        debug(lf[i]);
        bit1.add(a[i], 1);
    }

    BIT bit2(n);
    for (int i = n; i >= 1; --i) {
        rt[i] = bit2.qry(a[i] + 1);
        bit2.add(a[i], 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
//        debug(lf[i], rt[i]);
        int X = max(lf[i], rt[i]);
        int Y = min(lf[i], rt[i]);
        if (X > 2 * Y)
            ans++;
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

//    freopen("haircut.in", "r", stdin);
//    freopen("haircut.out", "w", stdout);

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
