#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define           fi    first
#define           se    second
#define           f     first
#define           s     second
#define           pb    push_back
#define           ep    emplace
#define           eb    emplace_back
#define           lb    lower_bound
#define           ub    upper_bound
#define       all(x)    x.begin(), x.end()
#define      rall(x)    x.rbegin(), x.rend()
#define   uniquev(v)    sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define     mem(f,x)    memset(f , x , sizeof(f))
#define        sz(x)    (int)(x).size()
#define  __lcm(a, b)    (1ll * ((a) / __gcd((a), (b))) * (b))
#define          mxx    *max_element
#define          mnn    *min_element
#define    cntbit(x)    __builtin_popcountll(x)

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e2 + 5;  
const int M = 20;
const int L = 8;
const int STATE = 4e5 + 7;
// 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 5, 7 = ~~ 4e5
int n, m;
int a[M];
int dp[N][STATE];
int n_b[M], b[M];

int getVal(){
    int ret = 0;
    for (int i = 1; i <= L; ++i)
        ret = ret * (i + 1) + b[i];
    return ret;
}

void getKey(int x){
    for (int i = L; i >= 1; --i) {
        b[i] = x % (i + 1);
        x /= (i + 1);
    }
}

void run_case() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> a[i];

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; ++i){
        int val = a[i];
        for (int j = 1; j <= L; ++j)
            b[j] = j;
        b[val] = 0;
        int x = getVal();
        dp[1][x]++;
    }
    for (int i = 1; i < n; ++i){
        for (int x = 0; x < STATE; ++x) {
            if(dp[i][x] > 0) {
                getKey(x);
                for (int j = 1; j <= L; ++j)
                    n_b[j] = b[j];
                for (int j = 1; j <= m; ++j) {
                    int val = a[j];
                    if (val <= n_b[val] + 1){
                        for (int k = 1; k <= L; ++k)
                            b[k] = min(k, n_b[k] + 1);
                        b[val] = 0;
                        int n_x = getVal();
                        dp[i + 1][n_x] = (dp[i + 1][n_x] + dp[i][x]) % MOD;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int x = 0; x < STATE; ++x)
        ans = (ans + dp[n][x]) % MOD;
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
