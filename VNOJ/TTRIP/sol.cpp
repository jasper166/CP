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
const int MAX = 1e2 + 5;

int d[MAX][MAX];
int n;
bool vis[MAX];

void run_case(){
    memset(d, 0x3f3f3f3f, sizeof d);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            cin >> d[i][j];
            if (i != j && d[i][j] == 0) d[i][j] = INF;
        }
    
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int cur = 1;
    vis[cur] = 1;
    ll res = 0;
//    FOR(i, 1, n) FOR(j, 1, n) cout << d[i][j] << " \n"[j == n]; 
    do {
        int nxt = -1;
        for (int v = 1; v < n; v++){
            if (!vis[v]){
                if (nxt == -1)
                    nxt = v;
                else if (d[cur][v] < d[cur][nxt])
                    nxt = v;
            }
        }
  //      debug(nxt);
        if (nxt == -1){
            res += d[cur][n];
            break;
        }
        res += 1LL * d[cur][nxt];
        cur = nxt;
        vis[nxt] = 1;
    } while (true);
    
    cout << res << "\n";
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

