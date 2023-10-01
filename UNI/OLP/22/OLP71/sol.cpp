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
#define TASK "OLP71"
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
int num[MAX], low[MAX];
vector <int> adj[MAX];

int cnt, ans;
stack <int> st;

void dfs(int u){
    num[u] = low[u] = ++cnt;
    
    for (int v : adj[u]){
        if (num[v])
            low[u] = min(low[u], num[v]);
        else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    
    if (num[u] == low[u]){
        ans++;
        int v;
        
        do {
//            if (st.empty()) break;
            v = st.top();
            st.pop();
            num[v] = low[v] = INF;
        }
        while (v != u);
        
    }
}

void run_case(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        adj[i].clear();
        num[i] = low[i] = 0;
    }
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    ans = cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!num[i]) dfs(i);
            
    cout << ans << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
/*
    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
  */  
    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
