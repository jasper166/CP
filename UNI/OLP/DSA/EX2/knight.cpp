#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

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
#else
#define debug(...) 166
#define debugArr(...) 166
#endif


const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e2 + 5;

int n;
char a[MAX][MAX];
pii st, en;

int dx[2][8] = {{-2, -1, 1, 2, 2, 1, -1, -2}, {0, -1, -1, -1, 0, 1, 1, 1}};
int dy[2][8] = {{-1, -2, -2, -1, 1, 2, 2, 1}, {-1, -1, 0, 1, 1, 1, 0, -1}};
bool vis[MAX][MAX][2];
int d[MAX][MAX][2];

bool isValid(int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= n && a[x][y] != '#');
}

void bfs(int x, int y, int z) {
    queue <pii> q;
    q.push({x, y});
    vis[x][y][z] = 1;
    d[x][y][z] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        REP(k, 8) {
            int nx = x + dx[z][k];
            int ny = y + dy[z][k];
            if (isValid(nx, ny) && !vis[nx][ny][z]) {
                vis[nx][ny][z] = 1;
                d[nx][ny][z] = d[x][y][z] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void run_case() {
    cin >> n;
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> a[i][j];
            if (a[i][j] == 'M')
                st = {i, j};
            if (a[i][j] == 'T')
                en = {i, j};
            d[i][j][0] = d[i][j][1] = INF;
        }
    }
    memset(vis, 0, sizeof vis);
    bfs(st.fi, st.se, 0);
    bfs(en.fi, en.se, 1);
    int ans = INF;
    FOR(i, 1, n)
        FOR(j, 1, n)
            ans = min(ans, max(d[i][j][0], d[i][j][1]));
    if (ans == INF) ans = -1;
    cout << ans << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

