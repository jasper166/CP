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
const int MAX = 2e5 + 5;

int n;
int c[MAX];
int timer = 0;
int st[MAX], en[MAX << 1];
vector <int> adj[MAX];
vector <int> tour;

struct BIT {
    int *f;
    int n;
    void init(int N) {
        n = N;
        f = new int[n + 2];
        fill (f, f + n + 1,  0);
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
        // debug(l, r);
        if (l > r)
            return 0;
        return get(r) - get(l - 1);
    }

} bit;



void dfs(int u, int p) {

    st[u] = ++timer;
    // euler.push_back(u);
    for (int v : adj[u]) {
        if (v == p)
            continue;
        dfs(v, u);
    }
    en[u] = timer;
    tour.push_back(u);
}


void run_case() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    bit.init(n);
    //  store the rightmost pos as it's only relevent
    map <int, int> last;
    int N = tour.size();
    vector <int> ans(n + 2);
    debug(tour);
    
    for (int i = 0; i < N; i++) {
        int u = tour[i];
        if (last.count(c[u]))
            bit.update(last[c[u]], -1);
        last[c[u]] = en[u];
        bit.update(last[c[u]], 1);
        // debug(u);
        ans[u] = bit.query(st[u], en[u]);
    }
    
    for (int i = 1; i <= n; i++) 
        cout << ans[i] << " \n"[i == n];
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

