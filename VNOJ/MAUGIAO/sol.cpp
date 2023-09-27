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
const int MAX = 22;

int n;
int a[MAX][MAX];
ll dp[1 << MAX];
ll cnt[1 << MAX];

void run_case(){
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++){
        dp[1 << i] = a[0][i];
        cnt[1 << i] = 1LL;
    }

    for (int mask = 0; mask < (1 << n); mask++){
        int boys = __builtin_popcount(mask);
        for (int girls = 0; girls < n; girls++){
            if (mask & (1 << girls))
                continue;
            int nxt_mask = mask | (1 << girls);
            if (dp[nxt_mask] < dp[mask] + a[boys][girls]){
                cnt[nxt_mask] = cnt[mask];
                dp[nxt_mask] = dp[mask] + a[boys][girls];
            }
            else if (dp[nxt_mask] == dp[mask] + a[boys][girls])
                cnt[nxt_mask] += cnt[mask];
        }
    } 
    cout << dp[(1 << n) - 1] << " " << cnt[(1 << n) - 1] << "\n";
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

