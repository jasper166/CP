#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
// const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int n, MOD;
vector <int> adj[MAX];
int f[MAX], g[MAX];
// int pre[MAX], suf[MAX];

void dfs(int u, int p) {
    f[u] = 1;
    int fc = 1; 
    for (int v : adj[u]) {
        if (v ^ p) {
            dfs(v, u);
            fc = (1ll * fc * f[v]) % MOD;
        }
    }
    f[u] = (f[u] + fc) % MOD;
}

void reroot(int u, int p) {
    vector <int> child;
    for (int v : adj[u]) {
        if (v ^ p)
            child.push_back(v);
    }

    int N = child.size();
    vector <int> pre(N), suf(N);
    if (child.empty())
        return;

    // debug(child);
    pre[0] = f[child[0]];
    for (int i = 1; i < N; i++) {
        int v = child[i];
        pre[i] = (1ll * pre[i - 1] * f[v]) % MOD;
    }
    suf[N - 1] = f[child[N - 1]];
    for (int i = N - 2; i >= 0; i--) {
        int v = child[i];
        suf[i] = (1ll * suf[i + 1] * f[v]) % MOD;
    }
    // debug(pre, suf);

    for (int i = 0; i < N; i++) {
        int v = child[i];
        int fnt = (i)? pre[i - 1] : 1;
        int bck = (i + 1 < N)? suf[i + 1] : 1; 
        g[v] = 1 + ((1ll * fnt * bck) % MOD * g[u]) % MOD;
    }

    for (int v : adj[u]) {
        if (v ^ p) {
            // debug(g[v]);
            reroot(v, u);
        }
    }
}

void run_case() {
    cin >> n >> MOD;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }   
    dfs(1, 0);
    g[1] = 1;
    reroot(1, 0);
    // FOR(i, 1, n) {
    //     debug(f[i], g[i]);
    // }
    for (int i = 1; i <= n; i++) {
        int ans = (1ll * (f[i] - 1 + MOD) * g[i]) % MOD;
        cout << ans << "\n";
    }
    // cout << f[1] - 1 << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


