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
#define debug(...) 42
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 3e2 + 5;

int n, res, x;
vector <pii> adj[MAX];
int d[MAX];
int a[MAX][MAX];

void Prim (int s) {
    priority_queue <pii, vector <pii>, greater <pii>> q;
    d[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        auto [du, u] = q.top();
        q.pop();
        if (du != d[u])
            continue;
        // join u to MST
        res += d[u];
        d[u] = -INF;

        for (auto [w, v] : adj[u]) {
            if (w < d[v]) {
                d[v] = w;
                q.push({d[v], v});
            }
        }
    }

}

void run_case() {
    cin >> n;
    res = 0;
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        d[i] = INF;
    } 

    // obvious that at least a field have a well -> let the well as vertice 0.
    for (int i = 1; i <= n; i++) {
        cin >> x;
        adj[0].push_back({x, i});
        adj[i].push_back({x, 0});
        // debug(0, i, x);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            // debug(i, j, x);            
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {      
            adj[i].push_back({a[i][j], j});
            adj[j].push_back({a[j][i], i});          
        }
    }
    Prim(0);
    cout << res << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

