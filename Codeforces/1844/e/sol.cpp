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

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 4e3 + 5;

vector <pii> adj[MAX];
int color[MAX];
int n, m, k;
bool ok;

void dfs(int u, int c) {
    if (color[u] != -1) {
        if (color[u] != c)
            ok = 0;
        return;
    }
    color[u] = c;
    for (auto [w, v] : adj[u]) {
        dfs(v, c ^ w);
    }
}

void run_case() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n + m; ++i) {
        adj[i].clear();
        color[i] = -1;
    }
    for (int i = 1; i <= k; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int x = x1;
        int y = min(y1, y2) + n;
        int w = (y1 == y2 - 1);
        adj[x].push_back({w, y});
        adj[y].push_back({w, x});
    }
    ok = 1;
    for (int i = 1; i <= n + m; ++i)
        if (color[i] == -1) dfs(i, 0);
    cout << (ok? "YES\n" : "NO\n"); 

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


