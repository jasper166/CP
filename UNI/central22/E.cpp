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
#define TASK "E"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e2 + 5;

int R, C, n;
int f[MAX];
int a[MAX][MAX];
int pref[MAX][MAX];
int dp[MAX][MAX][MAX];
// f(i, j, k) : ways to cut cake at row i -> R, column j -> C, for friend k -> n;

int get_sum(int x1, int y1, int x2, int y2){
    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
}

int cake (int r, int c, int k){
//    cout << r << " " << r << " " << k << "\n";
    if (dp[r][c][k] != -1)
        return dp[r][c][k];
    if (k == n)
        return (get_sum(r, c, R, C) <= f[k]);
    int ans = 0;
    // cutting horizontally
    for (int nr = r + 1; nr <= R; ++nr)
        if (get_sum(r, c, nr - 1, C) <= f[k]){
            ans += (cake(nr, c, k + 1) % MOD);
            ans %= MOD;
        }
    //cutting vertically
    for (int nc = c + 1; nc <= C; ++nc)
        if (get_sum(r, c, R, nc - 1) <= f[k]){
            ans += (cake(r, nc, k + 1) % MOD);
            ans %= MOD;
        }
    ans %= MOD;
    dp[r][c][k] = ans;
    return ans;
}

void run_case(){
    cin >> R >> C >> n;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i) cin >> f[i];

    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] + a[i][j] - pref[i - 1][j - 1];

    memset(dp, -1, sizeof(dp));

    cout << cake(1, 1, 1) << "\n";
/*
    FOR(i, 1, R) FOR(j, 1, C) 
        cout << dp[i][j][n] << " \n"[j == C];
        //cout << dp[R][C][n] << "\n";
        */
//    cout << get_sum(1, 1, 2, 2) << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    
    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
   // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
