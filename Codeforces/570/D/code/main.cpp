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
const int MAX = 5e5 + 5;

vector <int> adj[MAX], sub[MAX];
vector <pii> que[MAX];
string s;
int sz[MAX], dep[MAX], ans[MAX];
ll val[MAX];

void cal(int u, int p) {
    sz[u] = 1;
    dep[u] = dep[p] + 1;
    for (int v : adj[u]) {
        if (v ^ p) {
            cal(v, u);
            sz[u] += sz[v];
        }
    }
}

void dfs(int u, int p, bool isHeavy) {
    int nxt = 0;
    for (int v : adj[u]) {
        if (v ^ p) {
            if (sz[nxt] < sz[v]) {
                nxt = v;
            }
        }
    }
    // Light children
    for (int v : adj[u]) {
        if (v ^ p && v != nxt) {
            dfs(v, u, 0);
        }
    }
    // Heavy child
    if (nxt) {
        dfs(nxt, u, 1);
        swap(sub[nxt], sub[u]);
    }

    sub[u].push_back(u);
    val[dep[u]] ^= (1ll << (s[u] - 'a'));
//    debug(sub[u], u, s[u], val[dep[u]]);
    for (int v : adj[u]) {
        if (v ^ p && v != nxt) {
            for (auto x : sub[v]) {
                sub[u].push_back(x);
                val[dep[x]] ^= (1ll << (s[x] - 'a'));
            }
        }
    }
//    debug(sub[u]);
    // Answer queries. Palindrome can be formed if and only if odd entries appear no more than 1
    for (const auto &[h, id] : que[u]) {
        ans[id] = __builtin_popcountll(val[h]);
    }

    // Remove info
    if (!isHeavy) {
        for (int v : sub[u]) {
            val[dep[v]] ^= (1ll << (s[v] - 'a'));
        }
    }
}

int n, q;
void run_case() {
    cin >> n >> q;
    for (int i = 2; i <= n; ++i) {
        int x; cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    cin >> s;
    for (int i = 1; i <= q; ++i) {
        int v, h;
        cin >> v >> h;
        que[v].push_back({h, i});
    }
    s = "@" + s;
    cal(1, 0);
    dfs(1, 0, 1);

    for (int i = 1; i <= q; ++i) {
//        debug(ans[i]);
//        debug(sub[i]);
        cout << (ans[i] <= 1? "Yes\n" : "No\n");
    }
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
