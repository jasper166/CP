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
#define TASK "in1"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e2 + 5;

int n;
int a[MAX];
bool dp[MAX][MAX][MAX];

void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int sum = accumulate(a + 1, a + 1 + n, 0);

    for (int i = 0; i <= n; i++) dp[i][0][0] = 1;
    //for (int i = 0; i <= for (int j = 0; j < MAX; j++) d[] 
    
    for (int i = 1; i <= n; i++)
        for (int j = 0; j + a[i] < MAX; j++)
            for (int k = 0; k + a[i] < MAX; k++){
                dp[i + 1][j + a[i]][k] = dp[i - 1][j][k];
                dp[i + 1][j][k + a[i]] = dp[i - 1][j][k];
            }
    int res = INF;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++){
            if (dp[n + 1][i][j] == 0) continue;
            int k = sum - i - j;
            debug(i, j, k);
            res = min(max({i, j, k}) - min({i, j, k}), res);
        }                       
    cout << res << "\n";
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

