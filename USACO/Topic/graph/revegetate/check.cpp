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
constexpr int MAX = 1e6 + 2;
constexpr int INF = INT_MAX;
 

vector <set <int>> adj;
int grass[MAX], cnt_grass[5];
bool vis[MAX], taken[MAX][5];

int ans = INF, cur_ans;
int n, m, x, y;

void dfs(int i){
	if(vis[i]) return;
	vis[i] = true;
	FOR(j, 1, 4){
		int cur;
		bool flag = true;
		for (int k : adj[i]){
			if (j == grass[k]){
				flag  = false;
				break;
			}
			cur = j;
		}
		if (flag) {
			grass[i] = cur;
			break;
		}
	}
	for (int j : adj[i])
		dfs(j);
}


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	// freopen("revegetate.in", "r", stdin);
	// freopen("revegetate.out", "w", stdout);

	cin >> n >> m;
	adj.resize(n + 1);
	FOR(i, 1, m){
		cin >> x >> y;
		adj[x].insert(y);
		adj[y].insert(x);
	}

	FOR(i, 1, n){
		FOR(i, 1, n){
			grass[i] = 0;
			vis[i] = 0;
		}
		cur_ans = 0;
		dfs(i);
		FOR(i, 1, n){
			cur_ans = cur_ans * 10 + grass[i];
		}
		debug(cur_ans);
		ckmin(ans, cur_ans);
	}
	cout << ans << '\n';
		 
}
/* problem link: 

*/

