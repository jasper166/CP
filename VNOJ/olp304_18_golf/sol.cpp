#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;
t
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.enduid(a, b) uniform_int_distribution<int>(a, b)(rng)
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
const int MAX = 5e2 + 5;

int n, m;
int a[MAX][MAX];
bool have[MAX][MAX];
bool vis[MAX][MAX];
int sx, sy;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isOk(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m && !vis[x][y]);
}


bool bfs(int d){
    queue <pii> q;
    q.emplace(sx, sy);
    vis[sx][sy] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            vis[i][j] = 0;
     
//    cout << q.size() << "\n";
//    debug(q.size(), d); 
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k <= 3; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
    //        debug(nx, ny);
            if (isOk(nx, ny) && abs(a[nx][ny] - a[x][y]) <= d){
                vis[nx][ny] = 1;
                q.emplace(nx, ny);
            }
        }
    }
   // FOR(i, 1, n) FOR(j, 1, m) cout << vis[i][j] << " \n"[j == m];   
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            if (have[i][j] && !vis[i][j]) 
                return 0;
    return 1;
}

void run_case(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            cin >> a[i][j];
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            cin >> have[i][j];

    for (int i = 1; i <= n; i++){
        bool ok = 1;
        for (int j = 1; j <= m && ok; j++){
            vis[i][j] = 0;
            if (have[i][j]){
                sx = i;
                sy = j;
                ok = 0;
            }
        }
        if (!ok) break;
    }
// FOR(i, 1, n) FOR(j, 1, m) cout << a[i][j] << " \n"[j == m];   
 //FOR(i, 1, n) FOR(j, 1, m) cout << have[i][j] << " \n"[j == m];  
 
    int l = 0, r = 1e9;
    while (l <= r){
        int mid = (l + r) / 2;
        if (bfs(mid)) 
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << r + 1 << "\n";
    
   // cout << bfs(19) << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

//    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    freopen("GOLF.inp", "r", stdin);
//    freopen("GOLF.out", "w", stdout);
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
        
