#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

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
#define TASK "INP"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif
#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e4 + 5;

int n, m, k, s, t;
int ds[MAX], dt[MAX];
vector <pii> adj[MAX];
vector <pii> radj[MAX];

void dijkstra(int s, int d[], vector <pii> edge[MAX]){
    priority_queue <pii, vector <pii>, greater <pii>> q;
    d[s] = 0;
    q.emplace(0, s);
    
    while (!q.empty()){
        auto [du, u] = q.top();
        q.pop();
        if (du > d[u])
            continue;
        for (auto [w, v] : edge[u]){
            if (d[u] + w < d[v]){
                d[v] = d[u] + w;
                q.emplace(d[v], v);
            }
        }
    }
}

void run_case(){
    cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= n; i++){
        ds[i] = dt[i] = INF;
        adj[i].clear();
        radj[i].clear();
    }

    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
        radj[v].emplace_back(w, u);
    }
    dijkstra(s, ds, adj);
    dijkstra(t, dt, radj);   
    int res = ds[t];

    for (int i = 1; i <= k; i++){
        int u, v, w;
        cin >> u >> v >> w;
        int cur = min(ds[u] + dt[v] + w, dt[u] + ds[v] + w);
        res = min(res, cur);
    }
    if (res == INF) res = -1;
    cout << res << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

