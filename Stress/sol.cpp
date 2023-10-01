#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MAX = 5e2 + 5;
const int INF = 1e9;

#define fi first
#define se second
using T = tuple <int, int, int>;
using pii = pair <int, int>;

int n, m;
pii st, en;
char a[MAX][MAX];
int d[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};


bool isValid(int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m && d[x][y] == -1 && a[x][y] != '*'); 
}

void run_case() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S')
                st = {i, j};
            if (a[i][j] == 'T')
                en = {i, j};
        }
    }

    // cout << st.fi << " " << st.se << "\n";

    memset(d, -1, sizeof d);
    queue <T> q;
    for (int k = 0; k < 4; k++) {
        auto [x, y] = st;
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (isValid(nx, ny)) {
            q.push({nx, ny, k});
            d[nx][ny] = 0;
            // cout << nx << " " << ny << "\n";  
        }
    }

    while (!q.empty()) {
        auto [x, y, pre] = q.front();
        q.pop();
        // cout << x << " " << y << "\n";
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (isValid(nx, ny)) {
                q.push({nx, ny, k});
                d[nx][ny] = d[x][y] + (k != pre);
            }
        }
    }
    auto [x, y] = en;
    // cout << d[x][y] << "\n";
    cout << ((0 <= d[x][y] && d[x][y] <= 2)? "YES\n" : "NO\n");
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

