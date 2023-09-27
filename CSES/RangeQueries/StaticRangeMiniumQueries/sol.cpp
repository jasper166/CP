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
#define TASK "SRMQ"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
const int LOG = 18;

int lg[MAX], a[MAX];
int n, q;
int f[MAX][LOG];

void prepare(){
    lg[1] = 0;
    for (int i = 2; i < MAX; i++)
        lg[i] = lg[i / 2] + 1;
}

int query(int L, int R){
    int len = R - L + 1;
    int LG = lg[len];
    return min(f[L][LG], f[R - (1 << LG) + 1][LG]);
}

void run_case(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i], f[i][0] = a[i];
    
    for (int j = 1; j < LOG; j++)
        for (int i = 0; i + (1 << j) - 1 <= n; i++)
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    
    for (int i = 1; i <= q; i++){
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << "\n";
    }

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    
    prepare();
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}




