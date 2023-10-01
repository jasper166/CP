#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 998244353;
const int MAX = 1e5 + 5;

int n,k;
void run_case(){
    cin >> n >> k;
    vector< vector < vector <int> > > dp;
    dp.resize(n + 1);
    int sz = (n / k) + 1;
    //cerr<<sz<<'\n';
    FOR(i, 0, n){
        dp[i].resize(sz);
        REP(j, sz)
            dp[i][j].resize(k + 1);
    }
    dp[0][0][0] = 1;
    FOR(i, 1, k) {
        dp[0][0][i] = (dp[0][0][i - 1] + dp[0][0][i]) % MOD;
        dp[0][0][i] %= MOD;
    }

    FOR(i, 1, n){
        REP(j, sz){
            REP(l, k){
                if (dp[i - 1][j][l]) {
                    if (l)
                        dp[i][j][l + 1]
                            = (1ll * dp[i][j][l + 1] + 1ll * (dp[i - 1][j][l] - dp[i - 1][j][l - 1]) * (k - l) % MOD) % MOD;
                    else 
                        dp[i][j][l + 1]
                            = (1ll * dp[i][j][l + 1] % MOD + 1ll * dp[i - 1][j][l] * (k - l) % MOD) % MOD;
                        
                    }
            }
            FOR(l, 1, k)
                dp[i][j][l] = (dp[i][j][l] + dp[i - 1][j][k] - dp[i - 1][j][l - 1]) % MOD;
            if (dp[i][j][k] and j <= (n / k) - 1){
                dp[i][j + 1][0] = (dp[i][j + 1][0] + dp[i][j][k]) % MOD;
                dp[i][j][k] = 0;
            }
            FOR(l, 1, k)
                dp[i][j][l] = (dp[i][j][l - 1] + dp[i][j][l]) % MOD;
        }
    }
    ll ans = 0;
    FOR(i, 1, (n / k)){
        ans += (1ll * i * dp[n][i][k]) % MOD;
        ans %= MOD;
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    // cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
