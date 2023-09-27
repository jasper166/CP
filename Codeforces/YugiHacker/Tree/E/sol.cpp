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

#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int n, k, x, cnt;
vector <int> adj[MAX];
int a[MAX], f[MAX];

void dfs(int u, int p) {
    f[u] = a[u];
    // debug(u, p);
    for (int v : adj[u]) {
        if (v ^ p) {
            dfs(v, u);
            f[u] ^= f[v];
        }
    }
    if (f[u] == x) {
        cnt++;
        f[u] = 0;
    }
}

void run_case() {
    cin >> n >> k;
    cnt = x = 0;
    for (int i = 1 ; i <= n; i++) {
        adj[i].clear();
        a[i] = f[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        x ^= a[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    if (x == 0) {
        cout << "YES\n";
        return;
    } 
    dfs(1, 0);
    // debug(x, cnt);
    if (k > 2 && cnt >= 3) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

