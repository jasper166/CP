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
#define TASK "olp16"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e4 + 5;
const int nRow = 4;

int nCol;
int a[nRow + 1][MAX];
int f[1 << (nRow + 1)][MAX];
bool valid[1 << nRow];

int getSum(int mask, int col){
    int ans = 0;
    for (int i = 0; i < nRow; i++)
        if (mask & (1 << i)) ans += a[i][col];
    return ans;
}
void run_case(){
    for (int i = 1; i <= 8; i *= 2) valid[i] = 1;
    valid[0] = valid[5] = valid[9] = valid[10] = 1;

    cin >> nCol;
    
    for (int i = 0; i < nRow; i++)
        for (int j = 0; j < nCol; j++) 
            cin >> a[i][j];
    
    for (int mask = 0; mask < (1 << nRow); mask++)
        for (int col = 0; col < nCol; col++)
            f[mask][col] = (!col)? 0 : -INF;
        
    
    for (int mask = 0; mask < (1 << nRow); mask++){
       for (int row = 0; row < nRow; row++){
           if (!valid[mask]){
               f[mask][0] = -INF;
               continue;
           }
           if (mask & (1 << row))
              f[mask][0] +=  a[row][0];
        }
    }
    /*
    for (int mask = 0; mask < (1 << nRow); mask++)
        cout << f[mask][0]<< "\n";
    */

    int ans = -INF;

    for (int col = 1; col < nCol; col++){
        for (int mask_pr = 0; mask_pr < (1 << nRow); mask_pr++){
            if (!valid[mask_pr]) continue;
            for (int mask_cr = 0; mask_cr < (1 << nRow); mask_cr++){
                if (!valid[mask_cr]) continue;
                bool ok = 1;
                for (int j = 0; j < nRow && ok; j++){
                    if (mask_pr & (1 << j) && mask_cr & (1 << j))
                        ok = 0;
                }
                if (ok){ 
                    int val = getSum(mask_cr, col);

                    f[mask_cr][col] = max(f[mask_cr][col], f[mask_pr][col - 1] + val);
                    ans = max(ans, f[mask_cr][col]);
//                    if (ans == 41)
  //                      debug(col, mask_pr, mask_cr, val);
                      
                }
            }
        }
    }
    
    for (int mask = 0; mask < (1 << nRow); mask++)
        ans = max(ans, f[mask][nCol - 1]);
    
    cout << ans << "\n";
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

