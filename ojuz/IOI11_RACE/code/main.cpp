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

//#define int long long
using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int n, k;
vector <pii> adj[MAX];

int cnt[MAX * 5];
int sz[MAX];
bool vis[MAX];
int Tsize = 0;

void reSubsize(int u, int p) {
    sz[u] = 1;
    for (auto &[w, v] : adj[u]) {
        if (v != p && !vis[v]) {
            reSubsize(v, u);
            sz[u] += sz[v];
        }
    }
}

int getCentroid(int u, int p) {
    for (auto &[w, v] : adj[u])
        if (v != p && !vis[v] && sz[v] > Tsize / 2)
            return getCentroid(v, u);
    return u;
}

int f[MAX * 5];
// f(i) : Minimum edge to form i length from subtree to current centroid (0 in sub;
int maxW, ans;
int nCur;
vector <pii> subtree;
void process(int u, int p, int eCnt, int W) {
    if (W > k)
        return;
    if (cnt[k - W] == nCur)
        ans = min(ans, eCnt + f[k - W]);
    subtree.push_back({eCnt, W});
    for (auto &[w, v] : adj[u]) {
        if (v != p && !vis[v]) {
            process(v, u, eCnt + 1, W + w);
        }
    }
}

void decompose(int u, int p) {
    reSubsize(u, 0);
    Tsize = sz[u];
    int x = getCentroid(u, 0);

    ++nCur;
    cnt[0] = nCur;
    debug(nCur);
    f[0] = 0;
    vis[x] = 1;
    vector <pii> valid;

    for (auto [w, v] : adj[x]) {
        subtree.clear();
        if (!vis[v]) {
            process(v, x, 1, w);
            valid.push_back({w, v});
        }
        // Solving for each subtree
        for (auto [eCnt, W] : subtree) {
            if (cnt[W] != nCur || (cnt[W] == nCur && f[W] > eCnt))  {
                cnt[W] = nCur;
                f[W] = eCnt;
            }
        }
    }

    for (auto [w, v] : valid) {
        decompose(v, x);
    }

}

void run_case() {
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        ++u, ++v;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    ans = INF;
    for (int i = 0; i <= k; ++i) f[i] = INF;
    decompose(1, 0);
    if (ans == INF) ans = -1;
    cout << ans << "\n";
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
