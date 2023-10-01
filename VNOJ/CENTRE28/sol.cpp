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
const int MAX = 1e6 + 5;

int n, m;
vector <pii> adj[MAX];
int d[2][MAX];
int cnt[2][MAX];

inline void dijkstra(int x){
    priority_queue <pii, vector <pii>, greater <pii>> q; 
    int op = (x == n);
    d[op][x] = 0;
    cnt[op][x] = 1;
    q.emplace(0, x);
    while (!q.empty()){
        auto [du, u] = q.top();
        q.pop();
        if (du > d[op][u])
            continue;
        for (auto [w, v] : adj[u]){
            if (d[op][u] + w < d[op][v]){
                d[op][v] = d[op][u] + w;
                q.emplace(d[op][v], v);
                cnt[op][v] = cnt[op][u];
            }
            else if (d[op][u] + w == d[op][v])
                cnt[op][v] += cnt[op][u];
        }
    }

}

void run_case(){
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }
    for (int i = 1; i <= n; i++) 
        d[0][i] = d[1][i] = INF;        
       /*
    for (int i = 1; i <= n; i++){
        debug(i);
        for (auto j : p[i]) cout << j << " ";
        cout << '\n';
    }
    */
    vector <int> res;
    dijkstra(1);
    dijkstra(n);
    for (int i = 1; i <= n; i++){ 
        if (d[0][i] + d[1][i] > d[0][n])
            res.push_back(i);
        else if (cnt[0][i] * cnt[1][i] != cnt[0][n])
            res.push_back(i);
    }
    cout << res.size() << "\n";
    for (auto x : res) cout << x << "\n";
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

