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

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char a[MAX][MAX];
int d[MAX][MAX][4];
bool vis[MAX][MAX][4];
bool vis2[MAX][MAX][4];
int n, m, k;
pii s, e;

using T = tuple <int, int, int, int>;

bool isInside(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m && a[x][y] != '#');
}


void run_case(){
    cin >> n >> m >> k;
    FOR(i, 1, n) FOR(j, 1, m){
        cin >> a[i][j];
        REP(l, 4)
            d[i][j][l] = INF;
    }
    cin >> s.fi >> s.se >> e.fi >> e.se;

    deque <T> q;
    REP(l, 4){
        q.push_front({l, 0, s.fi, s.se});
        d[s.fi][s.se][l] = 1;
        vis[s.fi][s.se][l] = 1;
    }

    while (!q.empty()){
        auto [last, dis, x, y] = q.front();
        q.pop_front();
    
        if(vis2[x][y][last])
            continue;
        vis2[x][y][last] = 1;

        REP(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int now = i;
            if (isInside(nx, ny)){
//                cout << now << " " << last << " " << nx << " " << ny << "\n";
                int w = (now != last || dis >= k);
                if (d[x][y][last] + w < d[nx][ny][now]){
                    vis[nx][ny][now] = 1;
                    ckmin(d[nx][ny][now], d[x][y][last] + w);
                    if (w == 1)
                        q.push_back({now, 1, nx, ny});
                    else
                        q.push_front({now, dis + 1, nx, ny});
                }
            }
        }
    }
     /* 
    FOR(i, 1, n) FOR(j, 1, m){
       int cur = INF;
       REP(l, 4) ckmin(cur, d[i][j][l]);
       cout << cur  << " \n"[j == m];
    }
    */
    int ans = INF;
    REP(l, 4) ckmin(ans, d[e.fi][e.se][l]);
    if (ans == INF) ans = -1;
    if (s == e) ans = 0;
    cout << ans << "\n";
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




