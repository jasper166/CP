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
const int MAX = 2e5+ 5;

int n, k;
char c[32];
bool b[512];
ll dp[MAX];
string s;


// dp(i) : number of substrings till index i
void run_case(){
    cin >> n >> k;
    cin >> s;
    s = '$' + s;
    FOR(i, 1, k) cin >> c[i], b[c[i]] = 1;
    dp[0] = 0LL;
    int ed = 0;
    FOR(i, 1, n){
       if (b[s[i]])
           dp[i] = dp[i - 1] + 1LL * (i - ed);
       else{
           dp[i] = 0LL;
           ed = i;
       }
    }
   ll ans = 0;
   FOR(i, 1, n){
       while (dp[i]) i++;
       ans += 1LL * dp[i - 1];
   }
   cout << ans << "\n";
//   FOR(i, 1, n)  cout << dp[i] << " \n"[i == n];
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



