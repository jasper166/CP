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
const int MAX = 5e2 + 5;
const int n = 8;

int ans;
int a[MAX][MAX];
bool col[MAX], diag1[MAX], diag2[MAX];

void func (int y, int cur){
    for (int x = 0; x < n; x++){
        if (y == n){
            ans = max(ans, cur);
            return;
        }
        if (col[x] || diag1[x + y] || diag2[x - y + n - 1])
            continue;
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
        func (y + 1, cur + a[x][y]);
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;        
    }
}


void run_case(){
    ans = -1;
    memset(col, 0, sizeof col);
    memset(diag1, 0, sizeof diag1);
    memset(diag2, 0, sizeof diag2);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            cin >> a[i][j];
    func(0, 0);

    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){
        cout << "Test " << i << ": ";
        run_case();
    }
}
