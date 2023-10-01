/**    
* LANG: C++ 
* author: atom 
* created: 08.07.2022 09:47:11
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
constexpr int MAX = 1002;
constexpr int INF = INT_MAX;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, m, s, e, x, y;
bool vis[MAX];
vector <int> parent;
vector <set <int>> adj;

void dfs(int cur, int p){
	if (vis[cur]) return;
	vis[cur] = true;
	parent[cur] = p;
	for (int neighbour : adj[cur]){
		dfs(neighbour, cur);
	}
}


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m >> s >> e;
	adj.resize(n + 1);
	FOR(i, 1, m){
		cin >> x >> y;
		adj[x].insert(y);
		adj[y].insert(x);
	}
	parent.resize(n + 1);
	dfs(s, 0);

	vector <int> path;
	FOR(i, 1, n) cout << parent[i] << " \n"[i == n];
	while (parent[e] != e){
		path.pb(e);
		e = parent[e];
	}
	debug(path);
	reverse(all(path));
	if (path[0] != s) cout << "-1";
	else 
		for (int j : path) cout << j << ' ';
	cout << '\n';

 }
/* problem link: 

*/
