#include <bits/stdc++.h>
using namespace std;
// #define int long long
using ll = long long;
using ii = pair <int, int>;

const int MOD = 1e9 + 7;
const int LIM = 4444444444;
const int MAX = 1e3 + 5;

// B29
int n;
int a[MAX][MAX];
bool vis[MAX][MAX];
int d[MAX][MAX];

int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};

int s, t, u, v;

bool isValid (int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= n && a[x][y] && d[x][y] == -1);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n;
	cin >> s >> t >> u >> v;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j]; 
		}
	}


	memset(d, -1, sizeof d);
	queue <ii> q;
	q.push({s, t});
	d[s][t] = 0;

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		// cout << x << " " << y << "\n";
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (isValid(nx, ny)) {
				d[nx][ny] = d[x][y] + 1;
				q.push({nx, ny}); 
			}
		}
	}

	cout << d[u][v] << "\n";
	
    return 0;
}
