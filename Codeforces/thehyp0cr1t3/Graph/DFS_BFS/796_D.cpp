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
constexpr int MAX = 1e6 + 2;
constexpr int INF = INT_MAX;

int n, k, d;

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> k >> d;
	vector <bool> vis(n + 1, false);
	vector <pii> adj[n + 1];
	queue <pii> q;

	for (int i = 1; i <= k; i++){
		int x;
		cin >> x;
		q.push({x, -1});
	}
	for (int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y, i);
		adj[y].emplace_back(x, i);
	}

	vector <int> ret;
	while (!q.empty()){
		pii cur = q.front(); q.pop();
		if (vis[cur.F]) continue;
		vis[cur.F] = true;
		for (auto j : adj[cur.F]){
			if (j.F != cur.S){
				if (!vis[j.F]) q.push({j.F, cur.F});
				else
					ret.push_back(j.S);
			}
		}
	}
	cout << ret.size() << "\n";
	for (int i : ret) cout << i << " ";
	cout << "\n";	 
}
/* problem link: 

*/

