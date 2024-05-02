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
constexpr int MAX = 1e5 + 2;
constexpr double INF = 1e18;
constexpr double esp = 1e-6;
 

bool flag = true;
int n, m;
vector <pii> adj[MAX], net[MAX];
vector <int> vis, ans;

void dfs(int i){
	vis.push_back(i);
	for (auto j : adj[i]){
		net[j.F].push_back({-net[i][0].F, j.S - net[i][0].S});
		if (net[j.F].size() == 1) 
			dfs(j.F);
	}
}

bool ok(double a, double b){
	return abs(a - b) < esp;
}

double ok2(pii a, pii b){
	if (a.F == b.F){
		if (a.S == b.S) flag = false;
		return INF;
	}
	return (double) (a.S - b.S) / (a.F - b.F);
}



int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m;
	ans.resize(n);
	for (int i = 0; i < m; ++i){
		int x, y, z;
		cin >> x >> y >> z;
		--x, --y;
		adj[x].push_back({y, z});
		adj[y].push_back({x, z});
	}

	for (int i = 0; i < n; ++i){
		if (net[i].size() >= 1) continue;
		net[i].push_back({1, 0});
		dfs(i);
		double a = INF;
        for(int i : vis) {
            pii v = net[i][0];
            for(pii to : net[i]) {
                double temp = ok2(v, to);
                if (temp != INF) {
                    if (!ok(a, INF) && !ok(a, temp)) flag = false;
                    a = temp;
                }
            }
        }
 
        vector<int> ver;
        for(int i : vis) ver.push_back(-net[i][0].F * net[i][0].S);
 
        sort(all(ver));
 
        if (ok(a, INF)) a = ver[ver.size() / 2];
 
        for(int i : vis) 
            ans[i] = a * net[i][0].F + net[i][0].S;
        vis.clear();
	}
	if (flag){
		cout << "YES";
		for (auto i : ans) cout << i << ' ';
	}
	else cout << "NO";
	cout << '\n';
		 
}
/* problem link: 

*/

