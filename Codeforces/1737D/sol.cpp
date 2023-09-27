#include "bits/stdc++.h"
// @Jasper


using namespace std;
using ll = long long;
using pii = pair < int, int >;
using pll = pair < ll, ll >;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#define debugArr(...) 42
#endif

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;
const ll LINF = 1e18 + 5;
int n, m;
int d[MAX][MAX];
vector <pii> adj[MAX];

void run_case(){
    cin >> n >> m;
    for (int i = 0; i < MAX; i++){
        adj[i].clear();
        for (int j = 0; j < MAX; j++)
            d[i][j] = INF;
    }
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        d[u][v] = d[v][u] = 1;
    }
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    // floyd
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
   
    ll ans = LINF;
    for (int u = 1; u <= n; u++){
        for (auto [v, w] : adj[u]){
            // case that using wire connecting (u, v) - > cost = d(1, u) + d(u, v) + d(v, n);
            ans = min(ans, 1LL * (d[1][u] + d[n][v] + d[u][v]) * w); 
            for (int x = 1; x <= n; x++){
                ans = min(ans, 1LL * (d[1][x] + d[n][x] + d[v][x] + 2 * d[u][v]) * w);
                ans = min(ans, 1LL * (d[1][x] + d[n][x] + d[u][x] + 2 * d[u][v]) * w);
            }
                // case that : 1 -> x -> u -> v -> n
                // d(1, x), d(x, u), d(u, v) then using wire connecting (u, v) to connect (v, x) -> d(v, x) = d(u, v) = 1, then d(v, n);
                // cost = d(1, x) + d(x, u) + 2 * d(u, v) + d(v, n);
        }
    }
    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


