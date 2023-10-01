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
const int MAX = 5e5 + 5;

int n;
vector <pii> adj[MAX];
int d[MAX];
int trace[MAX];

void dijkstra(int s, int t) {
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    d[s] = 0;
    priority_queue <pii, vector <pii>, greater <pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        auto [du, u] = q.top();
        q.pop();
        if (du != d[u])
            continue;
        for (auto [w, v] : adj[u]) {
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                trace[v] = u;
                q.push({d[v], v});
            }
        }
    }
}

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w; cin >> w;
            if (w)
                adj[i].push_back({w, j});
        }
    }
    int s, t; 
    cin >> s >> t;
    dijkstra(s, t);
    int res = d[t];
    if (d[t] == INF) {
        cout << "Khong ton tai duong di\n";
        return;
    }
    vector <int> tour;
    while (t) {
        tour.push_back(t);
        t = trace[t];
    }
    // for (auto x : tour) cout << x << " ";
    for (int i = 0; i < (int) tour.size() - 1; i++)
        cout << tour[i] << " <- ";
    cout << tour.back() << "\n";
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

