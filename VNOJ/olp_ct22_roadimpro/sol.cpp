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
const int MAX = 2e3 + 5;

vector <pii> adj[MAX];
int n, m, Q;
int d[MAX][2];

void dijkstra (int s) {
    for (int i = 1; i <= n; i++) {
        d[i][0] = d[i][1] = INF;
    }
    using T = tuple <int, int, int>;
    priority_queue <T, vector <T>, greater <T>> q;
    q.push({0, s, 0});
    d[s][0] = d[s][1] = 0;
    
    while (!q.empty()) {
        auto [du, u, state] = q.top();
        q.pop();
        if (du != d[u][state])
            continue;
        for (auto [w, v] : adj[u]) {
            if (!state) {
                if (d[u][state] < d[v][1]) {
                    d[v][1] = d[u][state];
                    q.push({d[v][1], v, 1});
                }
            }
            if (d[u][state] + w < d[v][state]) {
                d[v][state] = d[u][state] + w;
                q.push({d[v][state], v, state});
            }
        }
    }
}

void run_case() {
    cin >> n >> m >> Q;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }   
    dijkstra(1);
    for (int i = 1; i <= Q; i++) {
        int s, t; cin >> s >> t;
        cout << min(d[s][0], d[s][1] + t) << "\n";
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
