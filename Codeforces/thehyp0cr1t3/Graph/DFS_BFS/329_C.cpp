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
constexpr int MAX = 1002;
constexpr int INF = INT_MAX;
 
int n, m;
vector <pii> b;
pii s, e, tour[] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int dist[MAX][MAX];
bool vis[MAX][MAX];
char a[MAX][MAX];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
		cin >> a[i][j];
		if (a[i][j] == 'S'){
			s.F = i;
			s.S = j;
		}
		else if (a[i][j] == 'E'){
			e.F = i;
			e.S = j;
		}
		else if (a[i][j] != 'T' && a[i][j] != '0'){
			 b.push_back({i, j});
		}
	}
	int ret = 0;
	queue <pii> q;
	pii player = {e.F, e.S};
	q.push(player);
	vis[e.F][e.S] = true;
	while (!q.empty()){
		pii go = q.front();
		q.pop();
		for (int k = 0; k <= 3; k++){
			int new_x = go.F + tour[k].F;
			int new_y = go.S + tour[k].S;
			if (1 <= new_x && new_x <= n && 1 <= new_y && new_y <= m){
				if (!vis[new_x][new_y] && a[new_x][new_y] != 'T'){
					dist[new_x][new_y] = dist[go.F][go.S] + 1;
					player = {new_x, new_y};
					vis[new_x][new_y] = true;
					q.push(player);
				}
			}
		}
	}	
	for (pii p : b){
		if (vis[p.F][p.S] && dist[p.F][p.S] <= dist[s.F][s.S])
			ret += (a[p.F][p.S] - '0');
	}
	cout << ret << '\n';
		 
}
/* problem link: 

*/

