#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 166
#define debugArr(...) 166
#endif


const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int n;
int a[MAX];
int f[MAX];

struct BIT {
    int f[MAX];
    void update(int x, int val) {
        for (; x < MAX; x += x & -x)
            f[x] = max(f[x], val);
    }

    int get(int x) {
        int ans = 1;
        for (; x; x -= x & -x)
            ans = max(ans, f[x]);
        return ans;
    }

} bit;

void run_case() {
    cin >> n;
    vector <int> b;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for (int i = 1; i <= n; i++)
        a[i] = (lower_bound(b.begin(), b.end(), a[i]) - b.begin()) + 1;

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int q = bit.get(a[i] - 1);
        f[i] = max(f[i], q);
        bit.update(a[i], f[i] + 1);
        ans = max(ans, f[i]);
    }
    cout << ans << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

