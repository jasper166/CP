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

ll f[MAX], inv[MAX];
int n, a[MAX];

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    BIT bit(n);
//    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        inv[a[i] + 1] += bit.qry(a[i] + 1);
        bit.add(a[i], 1);
    }

    for (int i = 0; i < n; ++i) {
        f[i] = f[i - 1] + inv[i];
        cout << f[i] << "\n";
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
