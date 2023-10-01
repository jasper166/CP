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
const int MAX = 1e3 + 5;
const ll LINF = 1e18 + 5;

struct vitamin{
    int c;
    string s;
};

int n;
const int states = 3;
vitamin v[MAX];
ll dp[MAX][(1 << states) + 5];

// f(i, mask) : minimum cost to have (mask) of vitamins till index i
// -> mask = ABC = 000 -> 111; -> ans is f(i, (111));
// using OR bitwise between current mask and the string mask;
//  -> dp(i, mask) = min(dp(i, mask), dp(i - 1, mask)
//     dp(i, mask | string mask) = min(dp(i, mask | stringmask), dp(i - 1, mask) + cost);

void run_case(){
    cin >> n;
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j < 1 << 3; j++) 
            dp[i][j] = LINF;
    dp[0][0] = 0LL;
    ll ans = LINF;

    for (int i = 0; i < n; ++i){
        cin >> v[i].c >> v[i].s;
        int string_mask = 0;
        for (int j = 0; j < states; j++){
            char c = (char) ('A' + j);
            bool have = 0;
            for (char x : v[i].s){
                if (x == c){
                    have = 1;
                    break;
                }
            }
            if (have) string_mask += (1 << j);
        }
        for (int mask = 0; mask < (1 << states); mask++){
            dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][mask]);
            dp[i + 1][mask | string_mask] = min(dp[i + 1][mask | string_mask], dp[i][mask] + v[i].c); 
        }
    }
    ans = dp[n][(1 << states) - 1];
    if (ans == LINF) ans = -1;
    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
   // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter




