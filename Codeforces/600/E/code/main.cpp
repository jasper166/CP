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
const int MAX = 1e5 + 5;

int c[MAX];
vector <int> adj[MAX];
map <int, int> cnt[MAX];
// counting color c in u's subtree
ll ans[MAX];
int sz[MAX];
// dominating color
void dfs(int u, int p) {
    cnt[u][c[u]]++;
    ans[u] += c[u];
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v ^ p) {
            dfs(v, u);
            // small to large
            if (cnt[u].size() < cnt[v].size()) {
                sz[u] = sz[v];
                ans[u] = ans[v];
                cnt[u].swap(cnt[v]);
            }

            for (const auto &[x, c] : cnt[v]) {
                cnt[u][x] += c;
                if (cnt[u][x] > sz[u]) {
                    sz[u] = cnt[u][x];
                    ans[u] = x;
                }
                else if (cnt[u][x] == sz[u]) {
                    ans[u] += x;
                }
            }
        }
    }
}
int n;
void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
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
