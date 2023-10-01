#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#define TASK "INP"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e3 + 5;

int n;
int a[MAX];
ll dp[MAX][1 << 10];
// maximum elements kept till index i with state of j
void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, -1, sizeof dp);
    sort(a + 1, a + 1 + n);

    dp[1][0] = 0;
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++){
        for (int mask = 0; mask < (1 << 10); mask++){
            if (dp[i - 1][mask] == -1)
                continue;
            int d = a[i] - a[i - 1];
            int nxt_mask;
            if (d > 9){
                nxt_mask = 0;
                dp[i][nxt_mask] = max(dp[i][nxt_mask], dp[i - 1][mask]);
                dp[i][nxt_mask | 1] = max(dp[i][nxt_mask | 1], dp[i - 1][mask] + 1);
            }
            else {
                nxt_mask = (mask << d) & ((1 << 10) - 1);
                dp[i][nxt_mask] = max(dp[i][nxt_mask], dp[i - 1][mask]);
                if ((nxt_mask & ((1 << 1) | (1 << 8) | (1 << 9))) == 0)
                    dp[i][nxt_mask | 1] = max(dp[i][nxt_mask | 1], dp[i - 1][mask] + 1);
            }
        }
    }
    // elements needed to remove = n - the ones that last
    ll last = 0LL;
    for (int i = 0; i < (1 << 10); i++)
        last = max(last, dp[n][i]);
    cout << n - last << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

