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

int n, m, L;
char a[MAX][MAX];
bool vis[MAX][MAX];
int dist[MAX][MAX];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'S', 'N', 'W', 'E'};
string s;

bool ok(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m && !vis[x][y] && a[x][y] == '.');
}

bool ok2(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m && dist[x][y] == INF && a[x][y] == '.');
}
void bfs(int i, int j){
    queue <pii> q;
    q.emplace(i, j);
    dist[i][j] = 0;
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (ok2(nx, ny)){
                q.emplace(nx, ny);
//                vis[nx][ny] = 1;
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
}


void bfs2(int i, int j){
    using T = tuple <int, int, int, char>;
    queue <T> q;
    q.emplace(i, j, 0, s[1]);
    vis[i][j] = 1;

    while (!q.empty()){
        auto [x, y, cnt, c] = q.front();
        q.pop();
       // debug(x, y, cnt, c);
        if (cnt == L) break;
        for (int k = 0; k <= 3; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
     //       debug(nx, ny);
            if (ok(nx, ny)){
                if (dist[nx][ny] != cnt + 1) continue;
                if (dir[k] == s[cnt + 1]) continue;
                if (cnt + 1 == L){
                        a[nx][ny] = '!';
                }
                q.emplace(nx, ny, cnt + 1, s[cnt + 1]);
                vis[nx][ny] = 1;
            }
        }
    }
}

void run_case(){
//    cin >> n >> m;
    cin >> m >> n;
    int Sx, Sy;

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++){
            dist[i][j] = INF;
            cin >> a[i][j];
            if (a[i][j] == 'S') Sx = i, Sy = j;
        }
    cin >> s;
    L = s.size();
   // debug(L);
    s = '$' + s;
    bfs(Sx, Sy);
    bfs2(Sx, Sy);    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) cout << a[i][j];
        cout << "\n";
    }

  //  FOR(i, 1, n) FOR(j, 1, m) cout << dist[i][j] << " \n"[j == m];
   // FOR(i, 1, n) FOR(j, 1, m) cout << a[i][j] << " \n"[j == m];
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

