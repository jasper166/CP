/**
* LANG: C++
* author: atom
* created: 14.07.2022 00:33:23
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
constexpr int MAX = 3002;
constexpr int INF = INT_MAX;

int n, x, y;
int head, tail;
vector <int> adj[MAX];
bool vis[MAX];
int ret[MAX], par[MAX];;
vector <int> cycle;
bool dfs(int c, int p) {
	vis[c] = true;
	par[c] = p;
	for (int j : adj[c]) {
		if (j == p) continue;
		if (vis[j]) {
			//tracing the cycle
			for (int i = 1; i <= n; i++) vis[i] = false;
			for (int i = c; ; i = par[i]) {
				// debug(i);
				vis[i] = true;
				ret[i] = 0;
				cycle.push_back(i);
				if (i == j) break;
			}
			return true;
		}
		if (dfs(j, c)) return true;
	}
	return false;
}


int orz() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	// for (int i = 1; i <= n; i++) par[i] = -1; 
	dfs(1, -1);
	debug(cycle);
	for (int k = 0; k < cycle.size(); ++k) {
		int i = cycle[k];
		for (int j : adj[i]) {
			if (vis[j]) continue;
			vis[j] = true;
			ret[j] = ret[i] + 1;
			cycle.push_back(j);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << ret[i] << " \n"[i == n];
	}
}
/* problem link:

*/

