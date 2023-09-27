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

int n, k;
vector <int> adj[MAX];
int d[2][MAX];
vector <int> fr;
queue <int> q;

void bfs(int x) {
    for (int i = 1; i <= n; i++)
        d[x][i] = INF;
    if (x == 0) {
        q.push(1);
        d[x][1] = 0;
    }
    else {
        for (int i = 1; i <= k; i++) {
            q.push(fr[i]);
            d[x][fr[i]] = 0;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (d[x][v] == INF) {
                d[x][v] = d[x][u] + 1;
                q.push(v);
            }
        }
    }
}

void run_case() {   
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        d[0][i] = d[1][i] = 0;
    }

    fr.resize(k + 1);
    for (int i = 1; i <= k; i++)
        cin >> fr[i];
    
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bfs(0);
    bfs(1);
    for (int i = 2; i <= n; i++) {
        if (adj[i].size() == 1) {
            // debug(i, d[0][i], d[1][i]);  
            if (d[0][i] < d[1][i]) {
                cout << "YES\n";
                return;
            }
        }
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

