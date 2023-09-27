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
const int MAX = 1e5 + 5;

int n, m;
vector <int> adj[MAX];
int deg[MAX];

inline void imp() {
    cout << "IMPOSSIBLE\n";
    exit(0);
}

void run_case() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }

    int cnt = 0;
    int st = -1, en = -1;
    for (int i = 1; i <= n; i++) {
        if ((int) adj[i].size() == deg[i] + 1) {
            st = i;
            cnt++;
        }
        if ((int) adj[i].size() + 1 == deg[i]) {
            en = i;
            cnt++;
        }
    }

    if (st != 1 || en != n || cnt != 2) 
       imp();

    debug(st, en, cnt);
    vector <int> curPath, euler;
    curPath.push_back(st);
    while (!curPath.empty()) {
        int u = curPath.back();
        if (adj[u].empty()) {
            euler.push_back(u);
            curPath.pop_back();
        }
        else {
            int v = adj[u].back();
            curPath.push_back(v);
            adj[u].pop_back();
        }
    }
    reverse(all(euler));
    if ((int) euler.size() != m + 1) imp();
    for (int u : euler) cout << u << " ";
    cout << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

