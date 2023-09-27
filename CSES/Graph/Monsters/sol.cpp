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
pii s, e;
char a[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char dir[] = {'L', 'R', 'U', 'D'};



using T = tuple <int, int, int>;
T d[MAX][MAX];
bool vis[MAX][MAX];
int dd[MAX][MAX];


bool isOk(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m && a[x][y] == '.' && !vis[x][y]);
}

void run_case(){
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m){
        cin >> a[i][j];
        if (a[i][j] == 'A') s = {i, j}, a[i][j] = '.';
        d[i][j] = make_tuple(INF, INF, 9);
      }
    queue <pii> q;
    q.push(s);
    vis[s.fi][s.se] = 1;
    dd[s.fi][s.se] = 1;


    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        REP(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isOk(nx, ny)){
                d[nx][ny] = make_tuple(x, y, i);
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    e = {INF, INF};
    FOR(i, 1, n) FOR(j, 1, m) {
        if (i == n || i == 1 || j == m || j == 1)
            if (a[i][j] == '.' && vis[i][j]){
                    e = {i, j};
                    break;
                }
            }

    if (e.fi == INF && e.se == INF){
        cout << "NO\n";
        exit(0);    
    }
    /*
    FOR(i, 1, n) FOR(j, 1, m){
        auto [x, y, z] = d[i][j];
        cout << z << " \n"[j == m];
    }
    
    cout << s.fi << " " << s.se << " " << e.fi << " " << e.se << "\n";
    */
    string ret = "";
    while (e != s){
        auto [nx, ny, i] = d[e.fi][e.se];
        e.fi = nx;
        e.se = ny;
        ret += dir[i];
    }
    reverse(all(ret));
    cout << "YES\n" << (int) ret.size() << "\n" << ret;
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
  //  cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter



