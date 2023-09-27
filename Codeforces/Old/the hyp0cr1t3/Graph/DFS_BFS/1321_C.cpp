/**
* LANG: C++
* author: atom
* created: 14.07.2022 14:28:14
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
constexpr int MAX = 2e5 + 2;
constexpr int INF = INT_MAX;

int n, m, x, y, k;
vector <int> adj[MAX], rev_adj[MAX];
int p[MAX], dis[MAX];
bool vis[MAX];
int orz() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y;
		adj[x].push_back(y);
		rev_adj[y].push_back(x);
		// adj[y].push_back(x);
	}
	cin >> k;
	for (int i = 1; i <= k; ++i) cin >> p[i];
	for (int i = 1; i <= n; ++i) dis[i] = -1;
	queue <int> q;
	q.push(p[k]);
	dis[p[k]] = 0;
	while (!q.empty()) {
		int vertex = q.front();
		q.pop();
		for (int j : rev_adj[vertex]) {
			if (dis[j] == -1) {
				dis[j] = dis[vertex] + 1;
				q.push(j);
			}
		}
	}
	// debug(adj);
	// tracing the shortest path
	int ret_min = 0, ret_max = 0;
	for (int i = 1; i < k; i++) {
	// if (p(i) to p(i + 1) is a shortest path from s to t then)
	// p[i + 1] = p[i] - 1;
	// using transpose graph
		if (dis[p[i + 1]] > dis[p[i]] - 1){
			ret_max++;
			ret_min++;
		}
		else {
			// check if there exists another shortest path
			// if there exists more than 1 then we have another shorter path: ret++
			int cnt = 0;
			for (int j : adj[p[i]]){
				if (dis[j] == dis[p[i]] - 1) cnt++;
			}
			if (cnt > 1) ret_max++;
		}
	}
	// for (int i = 1; i <= n; i++) cout << dis[i] << " \n"[i == n];
	// for (int i = 1; i <= n; i++) cout << sus[i] << " \n"[i == n];
	cout << ret_min << " " << ret_max << "\n";
}
/* problem link:

*/

