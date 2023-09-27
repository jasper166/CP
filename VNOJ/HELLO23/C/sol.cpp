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

#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int n, k;
int c[MAX], d[MAX], e[MAX];
// dp(i, money, mod);
int f[4][4], dp[4][4], fopt[4][4], predp[4][4];

void run_case(){
    cin >> n >> k;
    FOR(i, 1, n) cin >> c[i];
    FOR(i, 1, n) cin >> d[i];
    FOR(i, 1, n)
        e[i] = i;
    sort(e + 1, e + 1 + n, [] (int x, int y){
            return c[x] < c[y];
            });
    int sum = 0;
    int cnt = 0, smod = 0;
    for (int i = 1; i <= n, sum + c[e[i]] <= k; i++, cnt++){
        sum += c[e[i]];
        (smod += d[e[i]] % 3) %= 3;
    }
    
    memset(f, -1, sizeof f);
    memset(dp, -1, sizeof dp);
    memset(fopt, -1, sizeof fopt);
    memset(predp, -1, sizeof predp);

    f[0][0] = dp[0][0] = 0;
    FOR(i, 1, cnt){
        swap(f, fopt);
        REP(j, 4)
            REP(K, 3){
                if (j)
                    f[j][K] = max(fopt[j][K], fopt[j - 1][(K - (d[e[i]] % 3) + 3) % 3] + c[e[i]]);
                else
                    f[j][K] = fopt[j][K];
            }
    }
     FOR(i, cnt + 1, n){
        swap(dp, predp);
        REP(j, 4)
            REP(K, 3){
                if (j)
                    dp[j][K] = max(predp[j][K], predp[j - 1][(K - (d[e[i]] % 3) + 3) % 3] + c[e[i]]);
                else
                    dp[j][K] = predp[j][K];
            }
    }
/*
    int res = 0;
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            for (int x = 0; x < 3; x++) {
                if (f[i][x] < 0) continue;
                for (int y = 0; y < 3; y++) {
                    if (g[j][y] >= INF) continue;
                    if ((modu + y - x) % 3 == 0) {
                        if (s + g[j][y] - f[i][x] <= k)
                            res = max(res, ans + j - i);
                    }
                }
            }
        }
    }
    */
    int ans = 0;
    REP(i, 4)
        REP(j, 4)
            REP(K, 3){
                if (f[i][K] == -1)
                    continue;
                REP(L, 3) {
                    if (dp[j][L] >= -1)
                        continue;
                    if ((smod + L - K) % 3)
                        continue;
                    if (sum + dp[j][L] - f[i][K] <= k);
                        ans = max(ans, ans + j - i);
                }
            }
    cout << ans << "\n";
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

