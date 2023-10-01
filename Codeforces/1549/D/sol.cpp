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
const int MAX = 2e5 + 5;
const int LOG = 20;

int n;
int f[LOG][MAX];
int lg[MAX], a[MAX];

int get(int l, int r){
//    cout << l << " " << r << "\n";
    int k = log2(r - l + 1);
    return __gcd(f[k][l], f[k][r - (1 << k) + 1]);
}

bool ok(int x){
    for (int i = 1; i <= n - x + 1; i++)
        if (get(i, i + x - 1) >= 2) return 1;
    return 0;
}

void run_case(){
    cin >> n;
//    memset(f, 0, sizeof(f));
    REP(i, MAX) REP(j, LOG) f[j][i] = 0;  
    for (int i = 1; i <= n; i++) cin >> a[i];    
    for (int i = 1; i < n; i++) f[0][i] = abs(a[i] - a[i + 1]);
    
    --n;
    for (int k = 1; (1 << k) <= n; k++)
        for (int i = 1; i + (1 << k) - 1 <= n; i++)
            f[k][i] = __gcd(f[k - 1][i], f[k - 1][i + (1 << (k - 1))]);


    int l = 1, r = n + 1;
    while (l <= r){
        int m = (l + r) >> 1;
        if (ok(m))
            l = m + 1;
        else 
            r = m - 1;
    }
    cout << l << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


