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
const int MAX = 1e3 + 5;

int n;
int a[MAX][MAX];
int vis[MAX][MAX];
int type = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0 ,-1, 1};


bool isOk(int x, int y, int w){
    return (1 <= x && x <= n && 1 <= y && y <= n && vis[x][y] != w);
}
/*
 3
1 2 1
1 1 2
1 2 1
*/
using T = tuple <int, int, int>;

int bfs(int i, int j){
    int ret = 1;
    for (int u = 0; u < 4; u++){
        int res = 1;
        
        queue <T> q;
        int ni = i + dx[u];
        int nj = j + dy[u];
        if (ni < 1 || ni > n || nj < 1 || nj > n) continue;
        
        q.emplace(ni, nj, abs(a[ni][nj] - a[i][j]));        
        vis[ni][nj] = type;
        
        while (!q.empty()){
            auto [x, y, w] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (isOk(nx, ny, type) && abs(a[nx][ny] - a[x][y]) == w){
                    q.emplace(nx, ny, w);
                    vis[nx][ny] = type;
                    res++;
                }
            }
        }
        ret = max(ret, res); 
        ++type;
    }
    return ret;
}

void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            cin >> a[i][j];
    int ans = 0;
    //debug(bfs(1, 1));
    for (int i = 1; i <=n ; i++) for (int j = 1; j <= n; j++) vis[i][j] = -1;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (vis[i][j] == -1){
                ans = max(ans, bfs(i, j));
            }
            
    cout << ans << "\n";
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

