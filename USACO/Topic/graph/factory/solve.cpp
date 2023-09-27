/**    
* LANG: C++ 
* author: atom 
* created: 08.07.2022 16:59:57
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
constexpr int MAX = 1002;
constexpr int INF = INT_MAX;
 
int n, x, y;
vector <vector <int>> adj;
bool vis[MAX];



void dfs(int i){
	if (vis[i]) return;
	vis[i] = true;

	for (int j : adj[i])
		dfs(j);
}


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);
	
	cin >> n;
	adj.resize(n + 1);

	FOR(i, 1, n - 1){
		cin >> x >> y;
		adj[y].pb(x);
	}

	auto ok = [] () -> bool {
		FOR(i, 1, n)
			if (!vis[i]) return false;
		return true;
	};

	int ans = -1;
	FOR(i, 1, n){
		dfs(i);
		if (ok()){
			ans = i;
			break;
		}
		memset(vis, 0, sizeof(vis));
	}
	cout << ans << '\n';	 
}
/* problem link: 

*/

