#include "bits/stdc++.h"

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
const int MAX = 1e3 + 5;

int n, m;
queue <pii> q;
char a[MAX][MAX];
int da[MAX][MAX], dm[MAX][MAX];
bool vis[MAX][MAX];
pii from[MAX][MAX];
pii A, start;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
string ret = "";


void getDir(pii fr, pii to){
   if (fr == A) return;
   REP(i, 4){
       int nx = fr.fi + dx[i];
       int ny = fr.se + dy[i];
       if (nx == to.fi && ny == to.se){
           ret.push_back(dir[i]);
           getDir(to, from[to.fi][to.se]);
       }
   }
}


void bfs(bool player){
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        REP(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m && !vis[nx][ny] && a[nx][ny] == '.'){
                vis[nx][ny] = 1;
                if (player){
                    from[nx][ny] = {x, y};
                    da[nx][ny] = da[x][y] + 1;
                }
                else 
                    dm[nx][ny] = dm[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}


void run_case(){
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
    
    FOR(i, 1, n) FOR(j, 1, m){
        da[i][j] = dm[i][j] = INF;
        if (a[i][j] == 'M') q.push({i, j}), dm[i][j] = 0;
        if (a[i][j] == 'A') A = {i, j};
    }
    // bfs monsters;
    bfs(0);
    memset(vis, false, sizeof(vis));
    
    q.push(A);
    da[A.fi][A.se] = 0;
    bfs(1);

   // FOR(i, 1, n) FOR(j, 1, m) cout << dm[i][j] << " \n"[j == m];
   // FOR(i, 1, n) FOR(j, 1, m) cout << da[i][j] << " \n"[j == m];
    bool possible = 0;
    FOR(i, 1, n) FOR(j, 1, m){
        if (i == 1 || i == n || j == 1 || j == m){
            if (dm[i][j] > da[i][j] && da[i][j] != INF){
                start = {i, j};
                possible = 1;
                break;
            }
        }
    }
    if (!possible){
        cout << "NO\n";
        exit(0);
    }

    cout << "YES\n";
    getDir(start, from[start.fi][start.se]);
    reverse(all(ret));
    cout << (int) ret.size() << "\n" << ret << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter







