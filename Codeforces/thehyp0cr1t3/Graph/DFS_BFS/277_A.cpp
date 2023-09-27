/**    
* LANG: C++ 
* author: atom 
* created: 11.07.2022 16:06:57
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
constexpr int MAX = 102;
constexpr int INF = INT_MAX;
int n, m;
vector <vector<int>> adj(MAX), net;
vector <int> cur;
bool vis[2 * MAX];

void dfs(int i){
	vis[i] = true;
	cur.push_back(i);
	for (int j : adj[i])
		if (!vis[j]) dfs(j);
}

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m;
	set <int> nodes;
	adj.resize(2 * (n + 1));
	int special = 0;
	for (int i = 1; i <= n; i++){
		nodes.insert(n + i);
		int y;
		cin >> y;
		for (int j = 1; j <= y; j++){
			int x;
			cin >> x;
			nodes.insert(x);
			adj[n + i].push_back(x);
			adj[x].push_back(n + i);
		}
		special += y;
	}
	for (int i : nodes){
		if (vis[i]) continue;
		dfs(i);
		net.push_back(cur);
		cur.clear();

	}
	debug(adj);
	debug(net);
	int ans = nodes.size() - 1;
	for (auto x : net)
		ans -= (x.size() - 1);

	if (!special) ans = n;
	cout << ans << '\n';
		 
}
/* problem link: 

*/

