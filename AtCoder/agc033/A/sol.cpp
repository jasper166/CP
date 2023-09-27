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
const int MAX = 1e3 + 5;

int n, m;
char a[MAX][MAX];
int d[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
bool vis[MAX][MAX];

bool isValid(int x, int y) { return (1 <= x && x <= n && 1 <= y && y <= m && a[x][y] == '.' && !vis[x][y]); };

void run_case() {
    cin >> n >> m;
    queue <pii> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }
    // cout << q.size() << "\n";
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        // debug(x, y);
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (isValid(nx, ny)) {
                vis[nx][ny] = 1;
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            res = max(res, d[i][j]);
            // cout << d[i][j] << " \n"[j == m];
        }
    }
    cout << res << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

