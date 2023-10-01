/**    
* LANG: C++ 
* author: atom 
* created: 13.07.2022 06:48:10
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
constexpr int MAX = 1e6 + 2;
constexpr int INF = INT_MAX;

int n, m, x, y;
vector <int> adj[MAX];
int color[MAX];
bool cant = false;

void dfs(int i){
	for (int j : adj[i]){
		if (color[j] == -1){
			color[j] = (!color[i]);
			dfs(j);
		}
		else {
			if (color[j] == color[i]){
				cant = true;
				return;
			}
		}
	}
}


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) color[i] = -1;
	for (int i = 1; i <= m; i++){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1);
	for (int i = 1; i <= n; i++){
		if (color[i] == -1){
			color[i] = 0;
			dfs(i);
		}
	}

	if (cant) cout << "-1";
	else {
		int zero = 0, one = 0;
		for (int i = 1; i <= n; i++){
			if (color[i]) one++; 
		}
		zero = n - one;
		cout << zero << '\n';
		for (int i = 1; i <= n; ++i){
			if (!color[i]) cout << i << " ";
		}
		cout << "\n" <<  one << '\n';
		for (int i = 1; i <= n; ++i){
			if (color[i]) cout << i << " \n"[i == n];
		}
	}	 
}
/* problem link: 

*/

