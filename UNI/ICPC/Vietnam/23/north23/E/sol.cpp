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

#define int long long
using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e2 + 5;  
const int L = 8;
const int M = 8 + 7;

int n, m;
int a[M];

bool is_on[M];

// 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 5, 7
const int state = 4e5;
const int STATE = 4e5 + 7;;

int dp[N][STATE];
int b_state[M];
int b[M];

int conver1(){
    int ret = 0;
    for(int i = 1; i <= L; ++i){
        ret = ret * (i + 1) + b[i];
    }
    return ret;
}

void conver2(int id){
    for(int i = L; i >= 1; --i){
        b[i] = id % (i + 1);
        id = id / (i + 1);
    }
    return;
}

void run_case() {
    cin >> n >> m;
    memset(is_on, false, sizeof(is_on));
    for(int i = 1; i <= m; ++i){
        cin >> a[i];
        is_on[i] = true;
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= m; ++i){
        int x = a[i];
        for(int j = 1; j <= L; ++j){
            b[j] = j;
        }
        b[x] = 0;
        int id = conver1();
        dp[1][id]++;
    }
    for(int i = 1; i < n; ++i){
        for(int id = 0; id < state; ++id) 
        if(dp[i][id] > 0){
            conver2(id);
            for(int j = 1; j <= L; ++j)
                b_state[j] = b[j];
            for(int j = 1; j <= m; ++j){
                int x = a[j];
                if(b_state[x] >= x - 1){
                    for(int k = 1; k <= L; ++k)
                        b[k] = min(b_state[k] + 1, k);
                    b[x] = 0;
                    int new_id = conver1();
                    dp[i + 1][new_id] = (dp[i + 1][new_id] + dp[i][id]) % MOD;
                }
            }
        }
    }
    int ans = 0;
    for(int id = 0; id < state; ++id)
        ans = (ans + dp[n][id]) % MOD;
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



