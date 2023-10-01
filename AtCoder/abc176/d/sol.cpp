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
const int INF = 1e9 + 2;
const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;

int n, m;
char a[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int d[MAX][MAX];

bool isValid (int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m && a[x][y] != '#');
}
void run_case() {
    cin >> n >> m;
    pii st, en;
    cin >> st.fi >> st.se >> en.fi >> en.se;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            d[i][j] = INF;
        }
    }


    deque <pair<int, pii>> q;
    q.push_front({0, st});
    d[st.fi][st.se] = 0;
    while (!q.empty()) {
        auto [dxy, c] = q.front();
        auto [x, y] = c;
        q.pop_front();
        // debug(x, y);
        if (dxy != d[x][y])
            continue;

        // use first magic
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (isValid(nx, ny) && d[x][y] < d[nx][ny]) {
                d[nx][ny] = d[x][y];
                q.push_front({d[nx][ny], {nx, ny}});
            }
        }

        // use second magic
        for (int X = max(1, x - 2); X <= min(n, x + 2); X++) {
            for (int Y = max(1, y - 2); Y <= min(m, y + 2); Y++) {
                if (isValid(X, Y) && d[x][y] + 1 < d[X][Y]) {
                    d[X][Y] = d[x][y] + 1;
                    q.push_back({d[X][Y], {X, Y}});
                }
            }
        }
    }
    // debug(INF);
    if (d[en.fi][en.se] == INF) 
        d[en.fi][en.se] = -1;
    cout << d[en.fi][en.se] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

