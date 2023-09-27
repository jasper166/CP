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
const int LOG = 22;

int n, q;
vector <int> adj[MAX];
int dep[MAX], st[MAX], tree[MAX << 1];
int pa[MAX];
int timer = 0;

void dfs(int u, int p) {
    tree[++timer] = u;
    st[u] = timer;
    dep[u] = dep[p] + 1;
    pa[u] = p;
    for (int v : adj[u]) {
        if (v ^ p) {
            dfs(v, u);
            tree[++timer] = u;
        }
    }
}

pii up[LOG][MAX << 1];
int lg[MAX << 1];
void buildRMQ() {
    lg[1] = 0;
    for (int i = 2; i <= timer; ++i)
        lg[i] = lg[i / 2] + 1;

    for (int i = 1; i <= timer; ++i)
        up[0][i] = make_pair(dep[tree[i]], tree[i]);

    for (int k = 1; k < LOG; ++k) {
        int step = 1 << (k - 1);
        for (int i = 1; i + step <= timer; ++i)
            up[k][i] = min(up[k - 1][i], up[k - 1][i + step]);
    }
}

int getLCA(int u, int v) {
    int l = st[u], r = st[v];
    if (l > r) swap(l, r);
    int k = lg[r - l + 1];
    pii ans = min(up[k][l], up[k][r - (1 << k) + 1]);
    return ans.se;
}

int f[MAX];
void cal(int u, int p) {
    for (int v : adj[u]) {
        if (v ^ p) {
            cal(v, u);
            f[u] += f[v];
        }
    }
}

void run_case() {
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    buildRMQ();
    while (q--) {
        int u, v;
        cin >> u >> v;
        f[u]++; f[v]++;
        int x = getLCA(u, v);
        f[x]--;
        if (pa[x])
            f[pa[x]]--;
    }
    cal(1, 0);
    for (int i = 1; i <= n; ++i)
        cout << f[i] << " \n"[i == n];
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
