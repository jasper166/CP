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

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e3 + 5;


int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int a[N][N];
int d[N][N][4][2];
int n, m;

using state = tuple <int, int, int, bool>;
bool isValid(int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= m && a[x][y] != 0);
}

bool able_move(state cell, int k) {
	auto [x, y, dir, smell] = cell;
	int nx = x + dx[k];
	int ny = y + dy[k];
	if (!isValid(nx, ny)) return 0;
	if (a[nx][ny] == 3) return (smell == 1);
	return 1;
}

bool able_add(state cell, int dis) {
	auto [x, y, dir, smell] = cell;
	// debug(x, y, dir, smell);
	if (d[x][y][dir][smell] == -1) {
		d[x][y][dir][smell] = dis + 1;
		return 1;
	}
	return 0;
}

state next_cell(state cell, int k) {
	auto [x, y, dir, smell] = cell;
	int nx = x + dx[k];
	int ny = y + dy[k];
	bool next_smell = smell;
	if (a[nx][ny] == 2) next_smell = 1;
	if (a[nx][ny] == 4) next_smell = 0;
	return {nx, ny, k, next_smell};
}

void run_case() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	/*
	 0 -> cant
	 1 -> movable 
	 2 -> movable, next smell = 2 
	 3 -> movable if last cell is 2
	 4 -> remove smell, have to move to next cell in that direction if possible
	*/

	memset(d, -1, sizeof d);
	// cell(x, y, last, dir, smell);
	queue <state> q;
	q.push({1, 1, 0, 0});
	d[1][1][0][0] = 0;

	while (!q.empty()) {
		state c = q.front(); q.pop();
		auto [x, y, dir, smell] = c;

		// debug(x, y, dir, smell);
		if (x == n && y == m) {
			cout << d[x][y][dir][smell] << "\n";
			return;
		}
		// Slide 4-cells
		if (a[x][y] == 4) {
			if (able_move(c, dir)) {
				state n_c = next_cell(c, dir);
				if (able_add(n_c, d[x][y][dir][smell]))
					q.push(n_c);
				continue;
			}
		}

		for (int k = 0; k < 4; ++k) {
			if (able_move(c, k)) {
				state n_c = next_cell(c, k);
				if (able_add(n_c, d[x][y][dir][smell]))
					q.push(n_c);
			}
		}
	}
	cout << "-1\n";
}

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    setIO("dream");
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
