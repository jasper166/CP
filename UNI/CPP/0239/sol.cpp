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
const int MAX = 25;
const double EPS = 1e-9;

int n, m;
int getRank(){
    vector <bool> row_used(n + 1, 0);
    int ans = 0;
    FOR(j, 1, m){
        int i;
        for (i = 1; i <= n; i++){
            if (!row_used[i] && abs(a[i][j]) > EPS) break;
        }
        
        if (i != n + 1){
            ans++;
          //  cout << "i : " <<  i << "\n";
            row_used[i] = 1;
            for (int p = j + 1; p <= m; ++p){
                a[i][p] /= a[i][j];
            }
            FOR(k, 1, n){
                if (k != i && abs(a[k][j]) > EPS){
                    for (int p = j + 1; p <= m; ++p)
                        a[k][p] -= (a[i][p] * a[k][j]);
                }
            }
        }
    }
    return ans;
}


void run_case(){
    cin >> n >> m;
    double a[n + 1][m + 1];
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
    cout << getRank(a) << "\n";
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



