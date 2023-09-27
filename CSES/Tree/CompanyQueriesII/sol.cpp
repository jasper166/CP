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

// LCA by euler tour
// trong doan st(u) toi st[v] tk nao co dep[] nho nhat la lca(u, v);
int n, q;
vector <int> child[MAX];
int dep[MAX], st[MAX];
int up[20][MAX << 1 | 1];
// node u co st[u] thuoc doan i, i + 2 ^ j sao cho dep[u] nho nhat 
int lg[MAX << 1 | 1];
int euler[MAX << 1 | 1];
int timer = 0;

void dfs(int u, int p) {
    dep[u] = dep[p] + 1;
    euler[++timer] = u;
    st[u] = timer;
    for (int v : child[u]) {
        if (v == p)
            continue;
        dfs(v, u);
        euler[++timer] = u;
    }
}


void build() {
    lg[1] = 0;
    for (int i = 2; i <= timer; i++) lg[i] = lg[i / 2] + 1;

    for (int i = 1; i <= timer; i++)
        up[0][i] = euler[i];
    for (int k = 1; (1 << k) <= timer; k++) 
        for (int i = 1; i + (1 << k) - 1 <= timer; i++) {
            up[k][i] 
                = (dep[up[k - 1][i]] < dep[up[k - 1][i  + (1 << (k - 1))]])? 
                    up[k - 1][i] : up[k - 1][i + (1 << (k - 1))];
        }
}
int getLCA(int u, int v) {
    int l = st[u], r = st[v];
    if (l > r) swap(l, r);
    int k = lg[r - l + 1];
    return (dep[up[k][l]] < dep[up[k][r - (1 << k) + 1]])? 
            up[k][l] : up[k][r - (1 << k) + 1];
}

void run_case() {
    cin >> n >> q;

    

    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        child[x].push_back(i);
    }
    dfs(1, 0);
    build();

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << getLCA(u, v) << "\n";
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

