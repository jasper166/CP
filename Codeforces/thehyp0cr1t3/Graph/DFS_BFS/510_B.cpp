/**    
* LANG: C++ 
* author: atom 
* created: 12.07.2022 12:00:06
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
constexpr int MAX = 52;
constexpr int INF = INT_MAX;

char a[MAX][MAX];
pii tour[] ={{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

vector <pii> mp[MAX];
int n, m;
bool vis[MAX][MAX];
bool found = false;
void dfs(int x, int y, int prev_x, int prev_y, char prev_color){
	if (a[x][y] != prev_color) return;
	if (vis[x][y]){
		found = true;
		return;
	}
	debug(prev_x, prev_y, x, y);
	vis[x][y] = true;
	for (int k = 0; k <= 3; k++){
		int new_x = x + tour[k].F;
		int new_y = y + tour[k].S;
		if (1 <= new_x && new_x <= n && 1 <= new_y && new_y <= m){		
			if (new_x == prev_x && new_y == prev_y) continue;
			dfs(new_x, new_y, x, y, prev_color);
		}
	}
}

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j];
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j)
		if (!vis[i][j])
			dfs(i, j, 0, 0, a[i][j]);
	
	cout << (found? "Yes" : "No") << '\n';

}
/* problem link: 

*/

