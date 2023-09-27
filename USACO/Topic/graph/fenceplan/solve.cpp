/**    
* LANG: C++ 
* author: atom 
* created: {command:date +"%d.%m.%Y %H:%M:%S"}
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
void __print(const T &x) {int f = 0; 
	cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
 
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T const& t, V const& ... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
 
#ifdef LOCAL
#define debug(x...) cout << "#L" <<__LINE__<< ":" <<" [" << #x << "]=\n" <<"["; _print(x); cout << '\n';
#else
#define debug(...) 42
#endif

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e5 + 2;
constexpr int INF = INT_MAX;
 
int n, m;
struct cows{
	int x, y;
};

bool vis[MAX];
vector <cows> a;
vector <int> cur_net;
vector <vector<int>> adj, network;

void dfs(int i){
	vis[i] = true;
	cur_net.push_back(i);
	for (int j : adj[i])
		if (!vis[j]) dfs(j);
}


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);

	cin >> n >> m;
	a.resize(n + 1);
	adj.resize(n + 1);

	FOR(i, 1, n){
		cin >> a[i].x >> a[i].y;
	}
	FOR(i, 1, m){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	FOR(i, 1, n){
		if (!vis[i]){
			cur_net.clear();
			dfs(i);
			network.push_back(cur_net);
		}
	}
	// debug(network);
	int ans = INF;
	for (auto net : network){
		pii x = {-INF, INF}, y = {-INF, INF};
		for (int node : net){
			ckmax(x.F, a[node].x);
			ckmin(x.S, a[node].x);
			ckmax(y.F, a[node].y);
			ckmin(y.S, a[node].y);
		}
		int cur_ans = 2 * (x.F - x.S + y.F - y.S);
		ckmin(ans, cur_ans);
	}	 
	cout << ans << '\n';
}
/* problem link: 

*/

