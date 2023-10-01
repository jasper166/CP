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
const int MAX = 1e6 + 5;

int n, m;
int nRow, nCol;

bool check(int x, int mask){
    for (int i = 0; i < nRow - 1; i++){
        int f = (mask & (1 << i)) != 0;
        int s = (mask & (1 << (i + 1))) != 0;
    //    debug(x, mask, f + s);
        if (x == 1 && (f + s == 2)){
       //     cout << "1\n";
            return 1;
        }
        if (x == 0 && (f + s == 0)){
      //      debug("1\n");
            return 1;
        }
    }
    return 0;
}


void run_case(){
    cin >> n >> m;
    nRow = min(n, m);
    nCol = max(n, m);
    vector <vector <ll>> dp(1 << nRow, vector <ll> (1 + nCol, 0));
    for (int i = 0; i < (1 << nRow); i++)
        dp[i][1] = 1;
    
    for (int col = 2; col <= nCol; col++){
        for (int c_mask = 0; c_mask < (1 << nRow); c_mask++){
            for (int p_mask = 0; p_mask < (1 << nRow); p_mask++){
                if (check(0,c_mask | p_mask))
                    continue;
                if (check(1, c_mask & p_mask))
                    continue;
   //             debug(c_mask, p_mask);
                dp[c_mask][col] += dp[p_mask][col - 1];
            }
        }
    }
    
//    debug(check(1, (2 & 3)), check(0, 2 | 3));
    ll res = 0;
    for (int i = 0; i < (1 << nRow); i++)
        res += dp[i][nCol];
    cout << res << "\n";
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

