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
const int MAX = 5e2 + 5;

vector <pii> adj[MAX];
int n, m, p;
vector <int> favor;
int d[MAX][MAX];

void dijkstra(int s){
    for (int i = 1; i <= n; i++)
        d[s][i] = INF;
    d[s][s] = 0;
    priority_queue < pii, vector <pii>, greater <pii> > q;
    q.emplace(0, s);
    while (!q.empty()){
        auto [du, u] = q.top();
        q.pop();
        if (du > d[s][u])
            continue;
        for (auto [w, v] : adj[u]){
            if (d[s][u] + w < d[s][v]){
                d[s][v] = d[s][u] + w;
                q.emplace(d[s][v], v);
            }
        }
    } 
}


void run_case(){
    cin >> n >> p >> m;
    for (int i = 1; i <= p; i++){
        int x; cin >> x;
        favor.push_back(x);
    }
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }
    for (auto u : favor)
        dijkstra(u);
    
    pii res = make_pair(INF, 0);
    for (int i = 1; i <= n; i++){
        int cur = 0;
        for (auto v : favor)
            cur += d[v][i];
//        debug(i, cur);
        if (cur < res.fi){
            res.fi = cur;
            res.se = i;
        }
    }
    
    cout << res.se << "\n";
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

