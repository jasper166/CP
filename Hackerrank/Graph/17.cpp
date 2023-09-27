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

int x, y, n, m, s, e;
vector <set <int>> adj;
vector <int> parent, path;
bool vis[MAX];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m >> s >> e;
	adj.resize(n + 1);
	parent.resize(n + 1);

	FOR(i, 1, m){
		cin >> x >> y;
		adj[x].insert(y);
	}

	queue <int> q;
	q.push(s);
	vis[s] = true;
	parent[s] = s;
	while (!q.empty()){
		int vertex = q.front();
		q.pop();
		for (int j : adj[vertex]){
			if (!vis[j]){
				q.push(j);
				vis[j] = true;
				parent[j] = vertex;
			}
		}
	}

	while (parent[e] != e){
		path.pb(e);
		e = parent[e];
	}
	path.pb(e);
	
	debug(path);
	reverse(all(path));
	if (path[0] != s) cout << "-1";
	else 
		for (int j : path) cout << j << ' ';
	cout << '\n';
}
/* problem link: 

*/
