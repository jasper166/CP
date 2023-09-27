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

int n, q, a, b, p[MAX][20], d[MAX];
vector <int> adj[MAX];
  
void dfs(int u, int pa){
    for (auto v : adj[u]){
        if (v == pa) 
            continue;
        p[v][0] = u;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}
int solve(int a, int b){
    int x = d[a], y = d[b], ret = x+y;
    if (x > y){
        swap(a, b);
        swap(x, y);
    }
    y -= x;
    for (int i = 0; i < 20; i++){
        if (y & (1<<i)){
            b = p[b][i];
        }
    }
    if (a == b) 
        return ret-d[a]*2;
    for (int i = 19; i >= 0; i--){
        if (p[a][i] != p[b][i]){
            a = p[a][i];
            b = p[b][i];
        }
    }
    ret -= d[p[a][0]]*2;
    return ret;
}

void run_case(){
    cin >> n;
    for (int i = 0; i <= n; i++){
        adj[i].clear();
        d[i] = 0;
        for (int j = 0; j < 20; j++)
            p[i][j] = 0;
    }
    for (int i = 2; i <= n; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i < 20; i++){
        for (int j = 1; j <= n; j++){
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
    cin >> q;
    while (q--){
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
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


