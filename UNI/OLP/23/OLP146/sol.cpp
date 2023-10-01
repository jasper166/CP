#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
using pii = pair < int, int >;
const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e2 + 5;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int a[N][N];
int d[N][N][3];
int n, t;

bool isValid(int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= n);
}

void run_case() {
	cin >> n >> t;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 0; k < 3; ++k)
				d[i][j][k] = INF;

	using data = tuple <int, int, int, int>;
	// (dis, x, y, rem);
	priority_queue <data, vector <data>, greater <data>> q;
	q.push({0, 1, 1, 0});
	d[1][1][0] = 0;
	while (!q.empty()) {
		auto [dis, x, y, move] = q.top(); q.pop();
		if (dis > d[x][y][move])
			continue;

		// debug(dis, x, y, move);
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			int n_move = (move + 1) % 3;
			if (!isValid(nx, ny)) continue;
			int add = t + (n_move == 0? a[nx][ny] : 0);

			if (d[nx][ny][n_move] > d[x][y][move] + add) {
				d[nx][ny][n_move] = d[x][y][move] + add;
				q.push({d[nx][ny][n_move], nx, ny, n_move});
			}
		}
	}

	int ans = INF;
	for (int k = 0; k < 3; ++k) 
		ans = min(ans, d[n][n][k]);
	cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
