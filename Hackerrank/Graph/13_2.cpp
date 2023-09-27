/**    
* LANG: C++ 
* author: atom 
* created: 07.07.2022 14:37:33
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
constexpr int MAX = 1002;
constexpr int INF = INT_MAX;
 
int n, m, res = 0;
vector <vector <int>> adj;
vector <int> cur_component;
bool vis[MAX];

void dfs(int x){
	if (vis[x]) return;
	vis[x] = true;
	cur_component.pb(x);
	for (int i : adj[x])
		dfs(i);

}

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	cin >> n >> m;
	adj.resize(n + 1);
	FOR(i, 1, m){
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	FOR(i, 1, n){
		if (!vis[i]) dfs(i);
		debug(cur_component);
		if (!cur_component.empty()) res++;
		cur_component.clear();
	}

	cout << res << '\n';
		 
}
/* problem link: 

*/
