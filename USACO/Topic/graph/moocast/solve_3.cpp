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
void __print(const pair<T, V> &x) {cerr << "{"; __print(x.F); cerr << ", "; __print(x.S); cerr << "}\n";}
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
constexpr double eps = 1e-6;

int n;
bool flag = true;
vector<pii> adj[MAX], component[MAX];
vector<int> vis;
vector <double> ans;

void dfs(int i) {
    vis.pb(i);
    for(auto j : adj[i]) {
        component[j.F].pb({-component[i][0].F, j.S - component[i][0].S});
        if (component[j.F].size() == 1)
        	dfs(j.F);
    }
}

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false); 
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        adj[x].pb({y, z});
        adj[y].pb({x, z});
    }
 
 	ans.resize(n);
    for(int i = 0; i < n; i++) {
        if (component[i].size() >= 1) continue;
        component[i].pb({1, 0});
        
        dfs(i);
        double a = INF;

 	
 		auto ok = [] (double x, double y) {
		    return abs(x - y) < eps;
		};

		auto cur_pii = [] (pii a, pii b){
			if (a.F == b.F) {
        		if (a.S != b.S) flag = false;
    		    return INF;
   			 }
   			 return (double) (b.S - a.S) / (a.F - b.F);
		};



        for(int i : vis) {
            pii x = component[i][0];
            for(pii y : component[i]) {
                double temp = cur_pii(x, y);
                debug(x, y);
                if (temp != INF) {
                    if (!ok(a, INF) && !ok(a, temp)) flag = false;
                    a = temp;
                }
            }
        }

      	debug(a);
 		debug(ans);
        vector<int> cur_net;
        for(int i : vis) cur_net.pb(-component[i][0].F * component[i][0].S);
 
        sort(all(cur_net));
 
        if (ok(a, INF)) a = cur_net[cur_net.size() / 2];
 
        for(int i : vis) {
        	debug(i + 1);
            ans[i] = a * component[i][0].F + component[i][0].S;
        }
        vis.clear();
    }
    if (!flag) cout << "NO" << "\n";
    else {
        cout << "YES" << "\n";
        for(double i : ans) cout << i << " ";
    }
}

/* problem link: 
	https://codeforces.com/contest/1387/problem/A
*/

