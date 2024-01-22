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
const int MAX = 2e3 + 5;

int a, n, m;
int w[MAX], dp[MAX];
bool isRain[MAX];

void run_case(){
    cin >> a >> n >> m;
    for (int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        for (int j = l; j < r; j++) isRain[j] = 1;
    }
    for (int i = 0; i <= a; i++) w[i] = -1, dp[i] = INF;
    
    for (int i = 1; i <= m; i++){
        int x, p;
        cin >> x >> p;
     //   debug(x, p);
        w[x] = (w[x] != -1)? min(w[x], p) : p;
    }
    dp[0] = 0;
    for (int i = 1; i <= a; i++){
        if (!isRain[i - 1]) 
            dp[i] = dp[i - 1];
        else
            for (int j = i - 1; j >= 0; j--){
                if (w[j] == -1) continue;
                dp[i] = min(dp[i], dp[j] + w[j] * (i - j)); 
            }
    }
  //  debugArr(isRain, 0, a);
   // debugArr(dp, 0, a);
   // debugArr(w, 0, a);
    cout << (dp[a] == INF? -1 : dp[a]) << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


