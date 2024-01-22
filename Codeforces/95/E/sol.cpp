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

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int n, m;
vector <int> adj[MAX];
bool vis[MAX];

int dfs(int u) {
    vis[u] = 1;
    int ret = 1;
    for (int v : adj[u]) {
        if (vis[v]) continue;
        ret += dfs(v);
    }
    return ret;
}

bool isLucky(int x) {
    while (x) {
        if (x % 10 != 4 && x % 10 != 7)
            return 0;
        x /= 10;
    }
    return 1;
}

int f[MAX];
int cnt[MAX];
void run_case() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        int sz = dfs(i);
        cnt[sz]++;
    }

    fill(f, f + n + 5, INF);
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int k = 1;
        while (cnt[i]) {
            debug(i, cnt[i], k);
            int p = min(cnt[i], k);
            for (int j = n; j >= i * p; j--)
                f[j] = min(f[j], f[j - i * p] + p);
            cnt[i] -= p;
            k <<= 1;
        }
    }

    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        debug(f[i]);
        if (isLucky(i) && f[i] != INF) {
            ans = min(ans, f[i]);
            // debug(i);
        }
    }
    cout << ((ans == INF)? -1 : ans - 1) << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


