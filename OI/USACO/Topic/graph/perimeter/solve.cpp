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
constexpr int MAX = 1e3 + 2;
constexpr int INF = INT_MAX;
int n, m;
char a[MAX][MAX];
bool vis[MAX][MAX];
pii tour[] = {{ -1, 0}, {1, 0}, {0, 1}, {0, -1}};

pii bfs(int x, int y) {
	pii ret = {1, 0};
	queue <pii> q;
	q.push({x, y});
	vis[x][y] = true;
	while (!q.empty()) {
		pii c = q.front(); q.pop();
		for (int i = 0; i <= 3; i++) {
			int nx = c.F + tour[i].F, ny = c.S + tour[i].S;
			if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
				if (!vis[nx][ny]){
					if (a[nx][ny] == '#') {
						vis[nx][ny] = true;
						ret.F++;
						q.push({nx, ny});
					}
					else ret.S++;
				}
			}
			else ret.S++;
		}
	}
	return ret;
}

int orz() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);

	cin >> n;
	m = n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
	vector <pii> blob;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; j++)
			if (!vis[i][j] && a[i][j] == '#') {
				blob.push_back(bfs(i, j));
			}
	sort(all(blob), [] (pii x, pii y) {
		if (x.F == y.F) return x.S < y.S;
		return x.F > y.F;
	});
	debug(blob);
	cout << blob[0].F << " " << blob[0].S << "\n";

}
/* problem link:

*/

