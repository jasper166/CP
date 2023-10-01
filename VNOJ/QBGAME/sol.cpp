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
const int MAX = 1e4 + 5;

int n;
ll dp[1 << 8][MAX];
int a[8][MAX];
bool choose[1 << 8];
int rowSum (int mask, int col){
    int sum = 0;
    for (int j = 0; j < 8; j++)
        if (mask & (1 << j))
            sum += a[j][col];
    return sum;
}

bool isValid(int x){
    for (int i = 0; i < 7; i++){
        int f = (x & (1 << i)) != 0;
        int s = (x & (1 << (i + 1))) != 0;
   //     debug(f, s);
        if (f + s == 2)
            return 0;
    }
    return 1;
}

bool isValid(int x, int y){
    for (int i = 0; i < 8; i++){
        int f = (x & (1 << i)) != 0;
        int s = (y & (1 << i)) != 0;
        if (f + s == 2)
            return 0;
    }
    return 1;
}


void run_case(){
    cin >> n;
    ll res = -LINF;
    for (int j = 0; j < 8; j++)
        for (int i = 1; i <= n; i++){
            cin >> a[j][i];
            res = max(res, 1LL * a[j][i]);
    }
    if (res < 0){
        cout << res << "\n";
        return;
    }

    for (int i = 0; i < (1 << 8); i++){
        if (!isValid(i))
            continue;
        choose[i] = 1;
        dp[i][1] = rowSum(i, 1);    
    }
    
    for (int col = 2; col <= n; col++){
        for (int cur_mask = 0; cur_mask < (1 << 8); cur_mask++){
            if (!choose[cur_mask])
                continue;
            for (int pre_mask = 0; pre_mask < (1 << 8); pre_mask++){
                if (!choose[pre_mask])
                    continue;
                if (isValid(cur_mask, pre_mask))
                    dp[cur_mask][col] = max(dp[cur_mask][col], dp[pre_mask][col - 1] + rowSum(cur_mask, col));
                
            }
        }
    }
    for (int i = 0; i < (1 << 8); i++){
  //      cout << dp[i][1] << "\n";
        res = max(res, dp[i][n]);
    }
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

