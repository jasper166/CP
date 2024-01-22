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
const int MAX = 1e2 + 5;

int n, m;
int a[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
bool vis[MAX][MAX];


bool isIn(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m);
}


bool isGood (int x, int y){
    for (int k = 0; k < 4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (!isIn(nx, ny)) continue;
        if (a[nx][ny] == a[x][y]) 
            return 0;
    }
    return 1;
}


void run_case(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j], vis[i][j] = 0;
    
    queue <pii> q;
   
    while (true){
        pii pos = {-1, -1};
        for (int i = 1; i <= n; i++){
            bool need_exit = 0;
            for (int j = 1; j <= m; j++)
                if (!vis[i][j]){
                    pos = make_pair(i, j);
                    need_exit = 1;
                    break;
                }
            if (need_exit) break;
        }
        
        if (pos == make_pair(-1, -1)) break;
        
        q.push(pos);
       // debug(pos);
        a[pos.fi][pos.se]++;
        vis[pos.fi][pos.se] = 1;
       
       // FOR(i, 1, n) FOR(j, 1, m) cout << vis[i][j] << " \n"[j == m];
        while (!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (!isIn(nx, ny) || vis[nx][ny]) continue;
                if (a[nx][ny] == a[x][y]){
                    a[nx][ny]++;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
                else if (a[nx][ny] == a[x][y] - 1){
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cout << a[i][j] << " \n"[j == m];
                //+ ((a[i][j] & 1) != ((i + j) & 1)) << " \n"[j == m];
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
