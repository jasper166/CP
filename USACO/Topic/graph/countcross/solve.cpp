/**
* LANG: C++
* author: atom
* created: 15.07.2022 14:33:30
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

int n, k, r, nCows;
int cows[MAX][MAX];
pii t[] = {{ -1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool vis[MAX][MAX];

map < tuple <int, int, int, int>, bool > adj;
int orz() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);

	cin >> n >> k >> r;
	for (int i = 1; i <= r; i++) {
		pii x, y;
		cin >> x.F >> x.S >> y.F >> y.S;
		tuple <int, int, int, int> push1 = tie(x.F, x.S, y.F, y.S);
		tuple <int, int, int, int> push2 = tie(y.F, y.S, x.F, x.S);
		adj[push1] = true;
		adj[push2] = true;
	}
	// for (auto it : adj){
	// 	auto [i, j, k, l] = it.F; 
	// 	cout << it.S << "\n";
	// 	cout << i << " " << j << " " << k << " " << l << "\n";
	// }
	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		cows[x][y]++;
	}
	vector <int> allCows;

	auto bfs = [] (int x1, int y1, int x2, int y2){
		queue < pair <pii, pii > > q;
		q.push({{x1, y1}, {x2, y2}});
		while (!q.empty()){
			pair <pii, pii> c = q.front(); q.pop();
			if (1 > c.F.F || c.F.F > n || 1 > c.F.S || c.F.S > n 
				|| adj[{c.F.F, c.F.S, c.S.F, c.S.S}])
				continue;
			if (vis[c.F.F][c.F.S]) continue;
			vis[c.F.F][c.F.S] = true;
			nCows += cows[c.F.F][c.F.S];
			for (int i = 0; i <= 3; i++){
				int nx = c.F.F + t[i].F, ny = c.F.S + t[i].S;
				q.push({{nx, ny}, {c.F.F, c.F.S}});
			}
		} 
	};


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (vis[i][j]) continue;
			nCows = 0;
			bfs(i, j, 0, 0);
			if (nCows) allCows.push_back(nCows);
		}
	}

	debug(allCows);
	int ret = 0;
	for (int i = 0; i < (int) allCows.size(); i++)
		for (int j = i + 1; j < (int) allCows.size(); j++)
			ret +=  allCows[i] * allCows[j];

	cout << ret << "\n";
}
/* problem link:

*/

