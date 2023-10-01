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

int n, q;
vector <int> roots;
vector <int> adj[MAX];
vector <pii> que[MAX];
int sz[MAX], dep[MAX];

// Binary lifting
int up[18][MAX];
void cal(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v ^ p) {
            dep[v] = dep[u] + 1;
            up[0][v] = u;
            for (int k = 1; k < 18; ++k)
                up[k][v] = up[k - 1][up[k - 1][v]];
            cal(v, u);
            sz[u] += sz[v];
        }
    }
}

int jmp(int u, int k) {
    for (int i = 0; (1 << i) <= k; ++i) 
        if (k & (1 << i))
            u = up[i][u];
    return u;
}

vector <int> sub[MAX];
int ans[MAX];
vector <int> cnt;
// f[u][d] : numbers of v such that dep[u] + d = dep[v];
// DSU on tree merging
void dfs(int u, int p, bool isHeavy) {
    int hvy = 0;
    for (int v : adj[u]) {
        if (v ^ p) {
            if (sz[hvy] < sz[v])
                hvy = v;
        }
    }

    // Take light children info
    for (int v : adj[u])
        if (v ^ p && v != hvy)
            dfs(v, u, 0);

    // Take heavy child info
    if (hvy) {
        dfs(hvy, u, 1);
        swap(sub[hvy], sub[u]);
    }

    sub[u].push_back(u);
    cnt[dep[u]]++;
    for (int v : adj[u]) {
        if (v ^ p && v != hvy) {
            for (int x : sub[v]) {
                cnt[dep[x]]++;
                sub[u].push_back(x);
            }
        }
    }

    // Answer queries
    for (auto [k, id] : que[u]) {
        debug(k, id, u);
        ans[id] = cnt[k + dep[u]];
    }

    if (!isHeavy)
        for (int v : sub[u])
            cnt[dep[v]]--;

}

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        if (x) {
            adj[x].push_back(i);
            adj[i].push_back(x);
        }
        else 
            roots.push_back(i);
    }
    for (int x : roots)
        cal(x, 0);
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int v, k;
        cin >> v >> k;
        int anc = jmp(v, k);
        // debug(anc);
        if (dep[v] >= k) {
            // debug(anc, k, v);
            que[anc].push_back({k, i});
        }
    }
    // debug(roots);
    for (int x : roots) {
        cnt.assign(n + 5, 0);
        dfs(x, 0, 1);
    }

    for (int i = 1; i <= q; ++i) {
        if (ans[i]) ans[i]--;
        cout << ans[i] << " \n"[i == q];
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


