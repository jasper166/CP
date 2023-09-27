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
const int MAX = 405;

int n;

void run_case(){
    cin >> n;
    int ans = -INF;
    int a[n][n];
    REP(i, n) REP(j, n) cin >> a[i][j];
            
    REP(i, n) REP(j, n){
        int dd = 0, du = 0, k = 0;
        while (k <= i && k <= j && k < n - i && k < n - j){
            du += a[i - k][j - k] + a[i + k][j + k];
            dd += a[i - k][j + k] + a[i + k][j - k];
            ckmax(ans, du - dd);
            ++k;
        }
        dd = du = k = 0;
        while (k <= i && k <= j && k < n - i - 1 && k < n - j - 1){
            du += a[i - k][j - k] + a[i + k + 1][j + k + 1];
            dd += a[i - k][j + k + 1] + a[i + k + 1][j - k];
            ckmax(ans, du - dd);
//            if (du - dd == 26) cout << du << " " << dd << " " << i << " " << j << " " << k << "\n";
            ++k;
        }
    
    }
    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
   // cin >> Test;

    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter



