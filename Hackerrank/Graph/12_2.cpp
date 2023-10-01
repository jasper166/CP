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

int n, m, x, y;
vector <vector <int>> adj, component;
vector <int> cur_component;
bool vis[MAX];


void bfs(int i){
	if (vis[i]) return;
	vis[i] = true;
	queue <int> q;
	q.push(i);
	cur_component.pb(i);
	while (!q.empty()){
		int vertex = q.front();
		q.pop();
		for (int j : adj[vertex]){
			if (!vis[j]){
				q.push(j);
				cur_component.pb(j);
				vis[j] = true;
			}
		}
	}
}

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> m;
	adj.resize(n + 1);
	FOR(i, 1, m){
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	FOR(i, 1, n){
		if (!vis[i]) bfs(i);
		if (!cur_component.empty())
			component.pb(cur_component);
		cur_component.clear();
	}
	debug(component);
	cout << component.size() << '\n';
	for (auto i : component){
		cout << i.size() << ' ';
		for (int j : i) cout << j << ' ';
		cout << '\n';
	} 
}
/* problem link: 

*/
