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
const int MAX = 505;

int n;
int c[MAX];
int dp[MAX][MAX];

/*
int f(int l, int r){
    if (dp[l][r] != -1)
        return dp[l][r];
    if (l == r)
        return 1;
    if (l > r)
        return 0;
    int ans = INF;
    ans = min(ans, 1 + f(l + 1, r));
    if (l + 1 <= n && c[l] == c[l + 1])
        ans = min(ans, 1 + f(l + 2, r));
    for (int k = l + 1; k <= r; k++)
        if (c[l] == c[k])
            ans = min(ans, 1 + f(l + 1, k - 1) + f(k, r));
    return dp[l][r] = ans;
}
*/

void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    
    for (int i = n; i >= 1; i--){
        for (int j = i; j <= n; j++){
            // base case
            if (i == j){
                dp[i][j] = 1;
                continue;
            }
            //special case which considering two adjacent element.
            if (i + 1 == j){
                dp[i][j] = (c[i] == c[j])? 1 : 2;
                continue;
            }
            dp[i][j] = INF;
            
            //if panlindrome (possiblely?)
            if (c[i] == c[j])
                dp[i][j] = dp[i + 1][j - 1]; 
            //try to matching with color of c(i)
            for (int k = i + 1; k <= j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k][j]);
        }
    }
    cout << dp[1][n] << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


