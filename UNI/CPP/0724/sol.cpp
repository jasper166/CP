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
const int MAX = 205;

int n, m;
int a[MAX][MAX];
int row[MAX];

int kadane(){
    int cur = 0, ans = -INF;
    FOR(i, 1, n){
        cur = max(cur + row[i], row[i]);
        if (cur < 0) cur = 0;
        ckmax(ans, cur);
    }
    return ans;
}


void run_case(){
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];

    int ans = -INF;
    FOR(L, 1, m){
        FOR(i, 1, n) row[i] = 0;
        FOR(R, L, m){
            FOR(i, 1, n)
                row[i] += a[i][R];
            // if (L == 1) FOR(i, 1, n) cout << row[i] << " \n"[i == n];
            int cur = kadane();
            ckmax(ans, cur); 
        }
    }

    cout << ans << "\n";
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




