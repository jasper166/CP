#include "bits/stdc++.h"

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
const int MAX = 1e6 + 5;

int n, dp[505][505];
string s;


void run_case(){
    cin >> n >> s;
    s = '$' + s;
    for (int i = 1; i <= n; i++) dp[i][i] = 1;    
    for (int l = n; l >= 1; l--){
        for (int r = l + 1; r <= n; r++){
            dp[l][r] = 1 + dp[l + 1][r];       

            for (int i = l + 1; i <= r; i++){
                if (s[l] == s[i])
                    dp[l][r] = min(dp[l][r], dp[l + 1][i - 1] + dp[i][r]);
            }
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
// Codename : Jasper the Otter



