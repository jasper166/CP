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
constexpr int MAX = 22;
constexpr int INF = 1e9;
 
int n, r, c, ans = -INF;
int a[MAX][MAX];
bool vis[MAX][MAX];
int row[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int col[] = {-2, -1, 1, 2, -2, -1, 1, 2};


bool stop(int x, int y){
	FOR(i, 0, 7){
		if (vis[x + row[i]][y + col[i]]) return false;
	}
	return true;
}


void pathTry(int x, int y, int cur_point){
	if (stop(x, y)){
		ans = max(ans, cur_point);
		return;
	}
	FOR(i, 0, 7){
		if (vis[x + row[i]][y + col[i]]){
			vis[x][y] = false;
			ans = max(ans, cur_point);
			pathTry(x + row[i], y + col[i], cur_point + a[x][y]);
			vis[x][y] = true;
		}
	}
	return;
}


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> r >> c;
	FOR(i, 3, n + 2) FOR(j, 3, n + 2) cin >> a[i][j];
	FOR(i, 3, n + 2) FOR(j, 3, n + 2) vis[i][j] = true;
	// cout << vis[r + 1][c + 1] << '\n';
	// FOR(i, 3, n + 2){
	// 	FOR(j, 3, n + 2) cout << a[i][j] << ' ';
	// 	cout << '\n';
	// }
	// cout << a[r + 2][c + 2] << '\n';
	pathTry(r + 2, c + 2, 0);
	cout << ans << '\n';
}
/* problem link: 

*/

