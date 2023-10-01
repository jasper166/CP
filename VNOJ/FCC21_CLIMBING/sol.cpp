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
const int MAX = 1e6 + 5;
const int LOG = 20;

int n, m, c;
int f[LOG][MAX], g[LOG][MAX];
int lg[MAX];

bool get(int l, int r){
    int k = lg[r - l + 1];
    int maxVal = max(f[k][l], f[k][r - (1 << k) + 1]);
    int minVal = min(g[k][l], g[k][r - (1 << k) + 1]);
//    debug(minVal, maxVal);
    return (maxVal - minVal <= c);
}

void run_case(){
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x; 
        f[0][i] = g[0][i] = x;
    }

    lg[1] = 0;
    for (int i = 2; i < MAX; i++) lg[i] = lg[i / 2] + 1;
    
    for (int k = 1; k < LOG; k++)
        for (int i = 1; i + (1 << k) - 1 <= n; i++){
            f[k][i] = max(f[k - 1][i], f[k - 1][i + (1 << (k - 1))]);
            g[k][i] = min(g[k - 1][i], g[k - 1][i + (1 << (k - 1))]);
        }

    bool ok = 0;
    for (int i = 1; i <= n - m + 1; i++)
        if (get(i, i + m - 1)){
            cout << i << "\n";
            ok = 1;
        }
    if (!ok) cout << "NONE\n";
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

