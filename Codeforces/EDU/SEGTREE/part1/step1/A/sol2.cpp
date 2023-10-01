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
#define debug(...) 42
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

struct Fenwick {
    ll *f;
    int n;

    void init (int N) {
        f = new ll[N + 1];
        n = N;
        for (int i = 0; i <= N; i++) f[i] = 0;
    }

    void update (int x, int val) {
        for (; x <= n; x += x & -x)
            f[x] += val;
    }
    ll get (int x) {
        ll res = 0;
        for (; x; x -= x & -x)
            res += f[x];
        return res;
    }

    ll getRange (int l, int r) {
        return (get(r) - get(l - 1));
    } 
} bit;

int a[MAX];
int n, q;
void run_case() {
    cin >> n >> q;

    bit.init(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        bit.update(i, a[i]);
    }

    for (int Q = 1; Q <= q; Q++) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        ++x;
        if (cmd == 1) {
            bit.update(x, y - a[x]);
            a[x] = y;
        }
        else 
            cout << bit.getRange(x + 1, y) << "\n";
    } 

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

