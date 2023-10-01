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

int n;
ll a[MAX][MAX];
ll down[2 * MAX], up[2 * MAX];

void run_case(){
    
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            down[i + j] += a[i][j];
            up[i - j + n] += a[i][j];
        }
        
    ll odd = -1, even = -1;
    pii b1, b2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            ll val = down[i + j] + up[i - j + n] - a[i][j];
            debug(i, j, val);
            if ((i + j) & 1 && val > odd){
                odd = val;
                b1 = make_pair(i, j);
            }
            if (((i + j) % 2 == 0) && val > even){
                even = val;
                b2 = make_pair(i, j);
            }
        }
    cout << odd + even << "\n";
    cout << b1.fi << " " << b1.se << " " << b2.fi << " " << b2.se << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


