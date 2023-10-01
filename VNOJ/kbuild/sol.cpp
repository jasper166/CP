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

int n;
vector <int> adj[MAX];
int up[LOG][MAX];
int dep[MAX], f[MAX];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p)
            continue;
        up[0][v] = u;
        dep[v] = dep[u] + 1;
        for (int i = 1; i < LOG; i++)
            up[i][v] = up[i - 1][up[i - 1][v]];
        dfs(v, u);
    }
}

void process(int u, int v) {
    f[u]++; f[v]++;
    if (dep[u] != dep[v]) {
        if (dep[u] < dep[v])
            swap(u, v);
        int k = dep[u] - dep[v];
        for (int i = 0; (1 << i) <= k; i++) {
            if (k & (1 << i))
                u = up[i][u];
        }
    }
    if (u == v) {
        f[u] -= 2;
        return;
    }
    if (u != v) {
        int k = 0;
        while ((1 << k) <= dep[u]) ++k;
        for (int i = k; i >= 0; i--)
            if (up[i][u] != up[i][v]) {
                u = up[i][u];
                v = up[i][v];
            }
    }
    // debug(u);
    f[up[0][u]] -= 2;
}

void update(int u, int p) {
    debug(u, p);
    for (int v : adj[u]) {
        if (v == p)
            continue;
        update(v, u);
        f[u] += f[v];
    }
}

void run_case() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        process(u, v);
    }
    // for (int i = 1; i <= n; i++) cout << f[i] << " \n"[i == n];
    update(1, 0);
    // for (int i = 1; i <= n; i++) cout << f[i] << " \n"[i == n];
    
    int res = 0;
    for (int i = 2; i <= n; i++) if (f[i] == 0) res++;
    cout << res << "\n";
}
/*
    moi (u, v) voi lca(u, v) = x;
    cap nhat duong di (u, x) va (v, x);
    

    Tai sao lai la -2???
     - mang f[i]: danh dau so lan node i xuat hien
    , neu nhu co canh chua i chua duoc tham thi f[i] = 0;
    neu nhu i la lca cua 2 dinh (u, v) nao do thi ro rang duong di(u, v)   
    ko chua canh noi i voi dinh cha cua i -> minh phai coi f[i] = 0 
    tuc la -2 (1 cua u va 1 cua v khi update);

    Tai sao lai tu 2 -> n???
    Minh co dinh root la 1 va chi co n - 1 la dap an toi da;
    
    con lai cai node nao chua tham thi se tinh vao ket qua
*/
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

