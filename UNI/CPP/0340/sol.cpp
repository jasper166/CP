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
const int MAX = 105;

int n, m;
string s;
int dp[MAX][MAX];

int memoi(int i, int rem){
//    cout << i << " " << rem << "\n";
    if (i == m + 1)
        return (rem == 0);
    if (dp[i][rem] != -1)
        return dp[i][rem];
    int ans = 0;
    // include current digit
    ans += memoi(i + 1, (rem * 10 + (s[i] - '0')) % n);
    // not include 
    ans += memoi(i + 1, rem);
    dp[i][rem] = ans;
    return ans;
}


void run_case(){
    cin >> m >> n;
    FOR(j, 0, m) FOR(i, 0, n) dp[i][j] = -1;
    cin >> s;
    s = '$' + s;
    cout << memoi(1, 0) - 1 << "\n";
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



