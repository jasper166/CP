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

#ifdef LOCAL
#include "debug.h"
#define TASK "1311D"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 5e2 + 5;
// DP DnC optimization by RR:
int n, k;
int a[MAX][MAX];
int pref[MAX];
int pre[MAX], cur[MAX];
int opt[MAX];

void run_case(){
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
    
    for (int i = n - 1; i >= 0; i--){
        for (int j = i + 1; j <= n; j++)
            pref[j] = pref[j - 1] + a[i][j - 1];
        for (int j = i + 1; j <= n; j++)
            a[i][j] = pref[j] + a[i + 1][j];
    }
    FOR(i, 0, n - 1) {
        FOR(j, 0, n - 1)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    memset(pre, 0x3f3f3f3f, sizeof(pre));
    for (int i = 0; i <= n; i++) opt[i] = n;
    pre[n] = 0;

    for (int K = 1; K <= k; ++K){
        memset(cur, 0x3f3f3f3f, sizeof(cur));
        for (int i = 0; i <= n ; i++){
            int next_opt = -1;
            for (int j = (i)? opt[i - 1] : 0; j <= opt[i]; j++){
//                debug(ii);
                if (cur[i] > a[i][j] + pre[j]){
                    cur[i] = a[i][j] + pre[j];
                    next_opt = j;
                }
            }
            opt[i] = next_opt;
        }
        swap(cur, pre);
    }
    cout << pre[0] << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}




