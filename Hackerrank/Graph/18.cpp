/**    
* LANG: C++ 
* author: atom 
* created: 08.07.2022 10:18:55
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
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
constexpr int INF = INT_MAX;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, m, t, x, y;
vector <set <int>> adj;
vector <vector<int>> component;
vector <int> cur_component;
bool vis[MAX];
int path[MAX];


void dfs(int i, int &p){
	if (vis[i]) return;
	vis[i] = true;
	path[i] = p;
	cur_component.pb(i);
	for (int j : adj[i])
		dfs(j, p);

}


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m;
	adj.resize(n + 1);

	FOR(i, 1, m){
		cin >> x >> y;
		adj[x].insert(y);
		adj[y].insert(x);
	}
	int c = 1;
	FOR(i, 1, n){
		if (!vis[i]) dfs(i, c);
		cur_component.clear();
		c++;
	}
	// FOR(i, 1, n) cout << path[i] << '\n';
	// debug(component);
	cin >> t;
	while (t--){
		 cin >> x >> y;
		 if (path[x] != path[y]) cout << "-1\n";
		 else cout << "1\n";
	}
		 
}
/* problem link: 

*/
