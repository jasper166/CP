#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 998244353;
const int MAX = 1e6 + 5;

ll n, cnt[MAX], sum[MAX];

using Matrix = vector <vector <ll>>;

Matrix Mmult(Matrix a, Matrix b){
    
   
    int N = a.size();
    int M = a[0].size();
    int P = b[0].size();
    assert(a[0].size() == b.size());
    Matrix ans (N, vector <ll> (N, 0));
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < P; k++){
                ans[i][j] += (a[i][k] % MOD * b[k][j] % MOD) % MOD;
                ans[i][j] %= MOD;
            }
            
    return ans;
                
}

Matrix Mpw(Matrix a, ll x){
//    Matrix ans;
    int N = a.size();
    int M = a[0].size();
    Matrix ans(N, vector <ll> (M, 0));
    for (int i = 0; i < N; i++) ans[i][i] = 1;
    while (x){
        if (x & 1) ans = Mmult(ans, a);
        a = Mmult(a, a);
        x >>= 1;
    }
    return ans;
}

void run_case(){
    cin >> n;
   /* 
//    sum[2] = 12;
    cnt[0] = cnt[1] = 1;
    cnt[2] = 5; 
    sum[2] = 12; 
    for (int i = 3; i <= n; i++){
        cnt[i] = (cnt[i - 1] + 4 * cnt[i - 2] + 2 * cnt[i - 3]) % MOD;
        sum[i] = (sum[i - 1] + 4 * sum[i - 2] % MOD + (4 * 3 * cnt[i - 2]) % MOD 
                + (2 * sum[i - 3]) % MOD + (2 * 6 * cnt[i - 3] % MOD)) % MOD;
    }
    cout << sum[n] << '\n';
    */
//    Matrix base = {{2, 0, 0, 0, 0, 0 }};
    Matrix base = {{1},
                   {0},
                   {0},
                   {0},
                   {0},
                   {0},
    };
    Matrix a = {{1, 4, 2, 0, 0, 0},
                {1, 0, 0, 0, 0, 0},
                {0, 1, 0, 0, 0, 0},
                {0, 12, 12, 1, 4, 2},
                {0, 0, 0, 1, 0, 0},
                {0, 0, 0, 0, 1, 0}
    };
     // base = Mmult(base, test);
//    base = Mpw(base, n); 
  //  cout << base[0][0] << "\n";
    a = Mpw(a, n);
    Matrix ans = Mmult(a, base);
    cout << ans[3][0] << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

