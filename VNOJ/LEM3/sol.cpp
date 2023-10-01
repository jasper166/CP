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
const int MAX = 20;

int n;
int a[MAX][MAX];
int dp[1 << MAX][MAX];

int calc(int cur_mask, int u){
    if (dp[cur_mask][u] != -1)
        return dp[cur_mask][u];
    if (cur_mask == (1 << n) - 1)
        return 0;
    int res = INF;
    for (int v = 0; v < n; v++){
        if (cur_mask & (1 << v))
            continue;
        if (u == v)
            continue;
        int nxt_mask = cur_mask | (1 << v);
        int cost = a[u][v];
//        debug(cur_mask, nxt_mask, cost);
        res = min(calc(nxt_mask, v) + cost, res);
    }
    return dp[cur_mask][u] = res;
}


void run_case(){
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    memset(dp, 0x3f3f3f3f, sizeof dp);
    int res = INF;
    for (int i = 0; i < n; i++)
        dp[1 << i][i] = 0;
    for (int mask = 1; mask < (1 << n); mask++){
        for (int i = 0; i < n; i++){
            if (mask & (1 << i)){
                for (int j = 0; j < n; j++){
                    if (i == j)
                        continue;
                    if (mask & (1 << j))
                        continue;
                    int nxt_mask = mask | (1 << j);
                    dp[nxt_mask][j] = min(dp[nxt_mask][j], dp[mask][i] + a[i][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        res = min(res, dp[(1 << n) - 1][i]);
    cout << res << "\n";
        
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

