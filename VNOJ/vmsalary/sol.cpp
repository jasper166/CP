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
const int MAX = 1e5 + 5;


vector <int> child[MAX];
int a[MAX];
int n, timer = 0;
vector <int> tour;
int st[MAX], en[MAX];
int dep[MAX];

struct Fenwick {
    int *f;
    int n;
    void init (int N) {
        n = N;
        f = new int[n + 2];
        fill(f, f + n + 2, 0);
    }
    int get(int x) {
        int ans = 0;
        for (; x; x -= x & -x)
            ans += f[x];
        return ans;
    }

    void update(int x, int val) {
        for (; x <= n; x += x & -x)
            f[x] += val;
    }

    int query(int l, int r) {
        return get(r) - get(l - 1);
    }
} bit;

void dfs(int u, int p) {

    st[u] = ++timer;
    for (int v : child[u]) {
        if (v == p)
            continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
    en[u] = timer;
    tour.push_back(u);
}


void run_case() {
    cin >> n >> a[1];
    for (int i = 2; i <= n; i++) {
        int x; cin >> x >> a[i];
        child[x].push_back(i);
    }

    dfs(1, 0);
    bit.init(n);
    sort(tour.begin(), tour.end(), [] (const int x, const int y) {
        if (a[x] != a[y])
            return a[x] < a[y];
        return dep[x] > dep[y];
    });
    
    debug(tour);
    ll ans = 0;
    int i = 0;
    for (int u : tour) {
        for (; a[tour[i]] < a[u]; i++)
            bit.update(st[tour[i]], 1);
        int x = bit.query(st[u], en[u]);
        // debug(u, x);
        ans += 1ll * (x) * (x - 1) / 2;
        
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

