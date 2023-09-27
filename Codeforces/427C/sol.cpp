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
const int MAX = 1e6 + 5;

int n, m;
int cost[MAX];
vector <int> adj[MAX];
int low[MAX], num[MAX];
bool vis[MAX];
int tarjan;
ll ans = 0, cnt = 1;
stack <int> store;

void dfs(int u){
    low[u] = num[u] = ++tarjan;
    store.push(u);
    
    for (int v : adj[u]){
        if (!vis[v]){
            if (num[v]) 
                low[u] = min(low[u], num[v]);
            else{
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (num[u] == low[u]){
       // vector <int> tmp;
        int cnt_min = 0, v = -1, cost_min = 2 * INF;
        do {
            v = store.top();
            store.pop();
      //      tmp.push_back(v);
            if (cost[v] < cost_min){
                cost_min = cost[v];
                cnt_min = 1;
            }
            else if (cost[v] == cost_min) ++cnt_min;
            vis[v] = 1;
        }
        while (u != v);
        ans += cost_min;
        cnt = (cnt * cnt_min) % MOD;
    //    if (ans == 3) debug(tmp);    
    }

}

void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> cost[i];
    cin >> m;
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) 
        if (!vis[i]) 
            dfs(i);
    cout << ans << " " << cnt << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


