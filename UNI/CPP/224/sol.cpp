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

#ifndef ONLINE_JUDGE
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
bool vis[MAX][MAX];

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

bool isInside(int x, int y){ return (a[x][y] && !vis[x][y] && 1 <= x && x <= n && 1 <= y && y <= m); }

void bfs(int i, int j){
    queue <pii> q;
    q.push({i, j});
    vis[i][j] = 1;
    while (!q.empty()){
        auto [x, y] = q.front(); q.pop();
  //      cout << x << " " << y << "\n";
        REP(k, 8){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (isInside(nx, ny)){
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
}

void run_case(){
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j], vis[i][j] = 0;
    
    int ans = 0;
    stack <pii> s;
    FOR(i, 1, n) FOR(j, 1, m) if (!vis[i][j] && a[i][j]){
        bfs(i, j), ans++;
        s.push({i, j});
    }
    debug(s);
    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter



