/**    
* LANG: C++ 
* author: atom 
* created: 09.07.2022 08:19:15
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
 
vector <vector <int>> adj;
vector <int> parent, vis;
// -1 not visited, 0 visting, 1 visited
int n, m, x, y, e, s;

bool isCyclic(int cur){
	bool flag = 0;
	vis[cur] = 0;
	for (int j : adj[cur]){
		if (vis[j] == 1) continue;
		if (vis[j] == 0){
			s = j, e = cur;
			flag = flag | true;
			break;
		}
		parent[j] = cur;
		flag = flag | isCyclic(j);
	}
	return flag;
}

void printCycle(){
	vector <int> path;
	path.pb(s);
	while (e != s){
		path.pb(e);
		e = parent[e];
	}
	path.pb(s);
	reverse(all(path));
	cout << path.size() << '\n';
	for (int i : path) cout << i << ' ';
	cout << '\n';
}


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m;
	adj.resize(n + 1);
	parent.assign(n + 1, -1);
	vis.assign(n + 1, -1);

	FOR(i, 1, m){
		cin >> x >> y;
		adj[x].pb(y);
	}
	bool flag = false;
	s = -1, e = -1;
	FOR(i, 1, n){
		if (vis[i] == -1){
			if (isCyclic(i)){
				flag = true;
				break;
			}
		}
	}
	if (flag){
		cout << "YES\n";
		printCycle();
	}
	else cout << "NO\n";
}
/* problem link: 

*/

