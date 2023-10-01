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

#ifdef LOCAL
#include "debug.h"
#define TASK "1311D"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int n, m;
vector <int> adj[MAX];
bool node[MAX];
int num[MAX], low[MAX];
int bridge = 0;
int t = 0;

void dfs(int u, int p){
    num[u] = low[u] = ++t;    
    int child = 0;
    for (auto v : adj[u]){
        if (v == p) continue;
        if (num[v])
            low[u] = min(low[u], num[v]);
        else {
            dfs(v, u);
            child++;
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[v])
                bridge++;
            if (u == p){
                if (child >= 2) 
                    node[u] = 1;
            }
            else {
                if (low[v] >= num[u])
                    node[u] = 1;
            }
        }
    }
}


void run_case(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        if (!num[i])
            dfs(i, i);
    }
    int joint = 0;
    for (int i = 1; i <= n; i++)
        if (node[i])
            joint++;
    cout << joint << " " << bridge << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}




