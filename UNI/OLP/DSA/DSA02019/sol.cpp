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
const int MAX = 25;

int best = -INF;
int n, m;
bool edge[MAX][MAX];

void dfs (int u, int d) {
    best = max(best, d);
    for (int v = 1; v <= n; v++) {
        if (edge[u][v] && edge[v][u]) {
            edge[u][v] = edge[v][u] = 0;
            dfs(v, d + 1);
            edge[u][v] = edge[v][u] = 1;
        }
    }
}

void run_case(){
    cin >> n >> m;
    best = -INF;
    memset(edge, 0, sizeof edge);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u++, v++;
        edge[u][v] = edge[v][u] = 1;
    }
   
    for (int u = 1; u <= n; u++) {
        dfs(u, 0);
    }
    cout << best << "\n";

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

