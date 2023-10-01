/**
* LANG: C++
* author: atom
* created: 15.07.2022 00:41:27
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << "{"; __print(x.first); cerr << ", "; __print(x.second); cerr << "}\n";}
template<typename T>
void __print(const T &x) {
	int f = 0;
	cerr << '{'; for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";
}

void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T const& t, V const& ... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef LOCAL
#define debug(x...) cout << "#L" <<__LINE__<< ":" <<" [" << #x << "]=\n" <<"["; _print(x); cout << '\n';
#else
#define debug(...) 42
#endif

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 102;
constexpr int INF = INT_MAX;

int t, n, m;
char a[MAX][MAX];
int dis[MAX][MAX];
pii tour[] = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};

int orz() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dis[i][j] = -1;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
				if (a[i][j] == 'B') {
					for (int k = 0; k <= 3; k++) {
						int nx = i + tour[k].F, ny = j + tour[k].S;
						if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
							if (a[nx][ny] == '.') a[nx][ny] = '#';
						}
					}
				}
			}
		// for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		// 		cout << a[i][j] << " \n"[j == m];
		bool cant = false;
		queue <pii> q;
		if (a[n][m] != '#' && a[n][m] != 'B'){
			q.push({n, m});
			dis[n][m] = 0;
		}
		while (!q.empty()) {
			pii c = q.front(); q.pop();
			for (int k = 0; k <= 3; k++) {
				int nx = c.F + tour[k].F, ny = c.S + tour[k].S;
				if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
					if (a[nx][ny] != '#' && dis[nx][ny] == -1){
						// debug(nx, ny);
						dis[nx][ny] = dis[c.F][c.S] + 1;
						q.push({nx, ny});
					}
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				// cout << dis[i][j] << " \n"[j == m];
				if (a[i][j] == 'G') {
					if (dis[i][j] == -1) {
						cant = true;
						break;
					}
				}
				else if (a[i][j] == 'B' && dis[i][j] != -1){
					cant = true;
					break;
				}
			}
			if (cant) break;
		}
		cout << (cant ? "No" : "Yes");
		cout << "\n";
	}

}
/* problem link:

*/

