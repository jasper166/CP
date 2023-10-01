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
constexpr int MAX = 2e5 + 2;
constexpr int INF = INT_MAX;

int n, m, k;
vector <int> adj[MAX], a(MAX);
int dis[MAX][3];
bool vis[MAX];
void bfs (int i, int at){
	for (int j = 1; j <= n; j++) vis[j] = false;
	queue <int> q;
	q.push(i);
	vis[i] = true;
	while (!q.empty()){
		int vertex = q.front(); q.pop();
		for (int j : adj[vertex]){
			if (!vis[j]){
				vis[j] = true;
				dis[j][at] = dis[vertex][at] + 1;
				q.push(j);
			}
		}
	}
}



int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) cin >> a[i];
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	// for (int i = 1; i <= n; i++) cout << dis[i][1] << " \n"[i == n];
	// let bfs to calculate the distance from 1 and n to every special node
	// x, y is the dis from 1 and n to i
	// choose two special fields a, b to maximize the min(x[a] + y[b], x[b] + y[a])
	bfs(1, 1);
	bfs(n, 2);
	// -> maximize x(a) + y(b), x[a] - y[a] <= x[b] - y[b] -> sort by (x - y);
	vector <pii> spec;
	for (int i = 1; i <= k; i++){
		spec.push_back({dis[a[i]][1] - dis[a[i]][2], a[i]});
	}
	sort(all(spec));
	debug(spec);
	// iterating to find max x(a) and max y(b)
	int ret = 0, x_a = -INF;
	for (auto i : spec){
		int pos = i.S;
		ckmax(x_a, dis[pos][1]);
		ckmax(ret, x_a + dis[pos][2]);
	}
	// the upper bound of ans is the distance from 1 to n;
	cout << min(ret + 1, dis[n][1]);

}
/* problem link: 

*/

