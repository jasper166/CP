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
#define TASK "TSP_DP"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 15;

int edge[MAX][MAX];
int n;

int dp[(1 << MAX)][MAX];

int solve(int mask, int v){

    if (dp[mask][v] != -1)
        return dp[mask][v];
    if (mask == (1 << n) - 1)
        return edge[v][0];
    int ans = INF;
    for (int u = 0; u < n; u++){
        if (mask & (1 << u)) continue;
        int newmask = mask | (1 << u);
        int newdist = edge[v][u] + solve(newmask, u);
        ans = min(ans, newdist);
    }
    return dp[mask][v] = ans;
}

void run_case(){
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> edge[i][j];

    memset(dp, -1, sizeof(dp));    
    
    cout << solve(1, 0) << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}




