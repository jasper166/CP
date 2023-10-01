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

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;

int n, q;
vector <pii> adj[MAX];
int d[MAX][MAX];

inline void dijkstra(int u){
    
    d[u][u] = 0;
    priority_queue <pii, vector <pii>, greater <pii>> q;
    q.emplace(0, u);

    while (!q.empty()){
        auto [c_w, cur] = q.top();
        q.pop();
        if (d[cur][u] > INF)
            continue;
        for (auto [w, nxt] : adj[cur]){
            if (d[cur][u] + w < d[nxt][u]){
                d[nxt][u] = w + d[cur][u];
                q.emplace(d[nxt][u], nxt);
            }
        }
    }

}

void run_case(){
    cin >> n >> q;
    for (int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }
    //FOR(i, 1, n) 
    debug(adj[1]);
     debug(adj[2]);
      debug(adj[3]);
       debug(adj[4]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = INF;
    //memset(d, 0x3f3f3f3f, sizeof d);
    for (int i = 1; i <= n; i++)
        dijkstra(i);
    
    for (int i = 1; i <= q; i++){
        int u, v;
        cin >> u >> v;
        cout << d[u][v] << "\n";
    }
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

