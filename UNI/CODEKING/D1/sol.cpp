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
const int MAX = 1e2 + 5;

int a, b, n;
string s;
int dp[MAX][MAX];

// a * (R - L + 1) + b;

int memoi(int L, int R){
    if (L > R) return 0;
    if (L == R) return a + b;
    if (dp[L][R] != -1) return dp[L][R];
    int ans = memoi(L + 1, R) + (a + b);

    FOR(i, L + 1, R)
        if (s[L] == s[i]) 
            ans = max(ans, memoi(L + 1, i - 1) + memoi(i, R));
    return dp[L][R] = ans;
}


void run_case(){
    cin >> a >> b >> s;
    n = s.size();
   // memset(dp, -1, sizeof(dp));
   // int ans = memoi(0, n - 1);
    //REP(i, n) REP(j, n) cout << dp[i][j] << " \n"[j == n - 1];
    
    int rm = 1;
    FOR(i, 1, n - 1) if (s[i - 1] != s[i]) rm++;
    int ans = n * a + b * (b < 0? (rm / 2 + 1) : n);
    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter



