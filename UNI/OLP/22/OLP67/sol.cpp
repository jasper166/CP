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
#define TASK "OLP67"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 5e2 + 5;

int d[MAX][MAX];
int a[MAX][MAX];
int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool vis[MAX][MAX];

bool isOk(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m && !vis[x][y]);
}

void run_case(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    
    queue <pii> q;
    memset(d, 0x3f3f3f3f, sizeof(d));
    d[1][1] = a[1][1];
    //vis[1][1] = 1;
    q.push({1, 1});
    
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isOk(nx, ny)){
                if (d[x][y] + a[nx][ny] < d[nx][ny]){
                    d[nx][ny] = a[nx][ny] + d[x][y];
                    q.push({nx, ny}); 
                }
            }
        }
    }
   // FOR(i, 1, n) FOR(j, 1, m) cout << d[i][j] << " \n"[j == m];
    cout << d[n][m] << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}




