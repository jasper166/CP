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
const int LOG = 20;

int n, q;
vector <int> child[MAX];
int up[LOG][MAX];

void dfs(int u, int p) {
    for (int v : child[u]) {
        if (v == p)
            continue;
        up[0][v] = u;
        for (int i = 1; i < LOG; i++)
            up[i][v] = up[i - 1][up[i - 1][v]];
        dfs(v, u);
    }
}

int query(int u, int k) {
    for (int i = 0; (1 << i) <= k; i++) {
        if (k & (1 << i))
            u = up[i][u];
    }
    return u;
}

void run_case() {
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        child[x].push_back(i);
    }
    dfs(1, 0);
    while (q--) {
        int u, k;
        cin >> u >> k;
        int res = query(u, k);

        cout << (res? res : -1) << "\n";
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

