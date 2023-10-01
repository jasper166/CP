#include <bits/stdc++.h>
using namespace std;
// #define int long long
using ll = long long;
using ii = pair <int, int>;

const int MOD = 1e9 + 7;
const int LIM = 4444444444;
const int MAX = 1e3 + 2;

// B26
int n, m;
bool vis[MAX][MAX];
char a[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isValid(int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m && !vis[x][y] && a[x][y] != '#');
}

void bfs(int i, int j) {
    queue <ii> q;
    q.push({i, j});
    vis[i][j] = 1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (isValid(nx, ny)) {
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            cin >> a[i][j];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (isValid(i, j)) {
                ans++;
                bfs(i, j);
            }
        }
    }
    cout << ans << "\n";


    return 0;
}
