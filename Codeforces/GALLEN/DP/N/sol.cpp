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
const int COL = 1e4 + 5;
const int ROW = 16;

int a[ROW][COL];
int n, m;
int cost1[ROW][ROW], cost2[ROW][ROW];
int dp[1 << (ROW)][ROW][ROW];
void run_case(){
    
    cin >> n >> m;
    REP(i, n) REP(j, m) cin >> a[i][j];
    REP(i, n) REP(j, n){
        int worst = INF;
        REP(k, m) ckmin(worst, abs(a[i][k] - a[j][k]));    
        cost1[i][j] = worst;
    }
    REP(i, n) REP(j, n){
        int worst = INF;
        REP(k, m - 1) ckmin(worst, abs(a[i][k] - a[j][k + 1]));
        cost2[i][j] = worst;
    }
    
    REP(i, 1 << ROW) REP(j, ROW) REP(k, ROW) dp[i][j][k] = 0;
    REP(i, n) dp[1 << i][i][i] = INF;
    
    for (int mask = 1; mask < (1 << n); mask++){
        REP(i, n){ // fixed row
            REP(j, n){ // previous row
                int nrows = __builtin_popcount(mask);
                if (nrows == 1 || i != j){
                    if ((mask & (1 << i)) && (mask & (1 << j))){
                        REP(k, n){// next row choosen
                            if (!(mask & (1 << k))){
                                int new_mask = mask | (1 << k);
                                int val = min(dp[mask][i][j], cost1[j][k]);
                                ckmax(dp[new_mask][i][k], val);
                            }
                        }
                    }
                }
            }
        }
    }
//    REP(i, n) REP(j, n) cout << cost1[i][j] << " \n"[j == n - 1];
//    REP(i, n) REP(j, n) cout << cost2[i][j] << " \n"[j == n - 1];

    int ans = 0;
    REP(i, n) REP(j, n)
        ckmax(ans, min(dp[(1 << n) - 1][i][j], cost2[i][j]));
    
    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


