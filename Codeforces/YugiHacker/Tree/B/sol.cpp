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

int n;
vector <int> child[MAX];
vector <int> leaves;
int cnt;
int pa[MAX], vis[MAX];


void dfs(int u, int p) {
    bool isLeaf = 1;
    pa[u] = p;
    vis[u] = 1;
    for (int v : child[u]) {
        if (vis[v])
            continue;
        isLeaf = 0;
        dfs(v, u);
    }
    if (isLeaf) {
        leaves.push_back(u);
        cnt++;
    }
}

void trace(int u) {
    vector <int> path;
    while (u) {
        if (vis[u])
            break;
        path.push_back(u);
        vis[u] = 1;
        u = pa[u];
    }
    cout << path.size() << "\n";
    reverse(path.begin(), path.end());
    for (auto x : path) cout << x << " ";
    cout << "\n";
}

void run_case() {
    cin >> n;

    cnt = 0;
    leaves.clear();
    for (int i = 1; i <= n; i++) {
        child[i].clear();
        pa[i] = 0;
        vis[i] = 0;
    }

    int root = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        child[x].push_back(i);
        if (x == i)
            root = x;
    }

    dfs(root, 0);
    // for (int i = 1; i <= n; i++) cout << pa[i] << " \n"[i == n];
    cout << cnt << "\n";
    fill(vis, vis + n + 1, 0);
    for (int u : leaves) {
        trace(u);
    }
    cout << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

