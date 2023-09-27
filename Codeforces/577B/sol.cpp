#include "bits/stdc++.h"
// @Jasper


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
const int MAXM = 1e3 + 5;
const int MAXN = 1e6 + 5;
int n, m;
int pre[MAXM], cur[MAXM];
int a[MAXN];

void run_case(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
   // for (int j = 0; j < m; j++) dp[0][j] = 1;
    if (n >= m){
        cout << "YES\n";
        exit(0);
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < m; j++){
            if (pre[j]){
                cur[j] = 1;
                cur[(j + a[i]) % m] = 1;
            }
        }
        cur[a[i] % m] = 1;
        swap(pre, cur);
    }
    cout << (pre[0]? "YES\n" : "NO\n");
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


