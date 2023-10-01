/**    
* LANG: C++ 
* author: atom 
* created: 11.07.2022 15:13:56
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
constexpr int MAX = 3002;
constexpr int INF = INT_MAX;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, m, x, y;
bool vis[MAX];
vector <int> adj[MAX], ord(MAX);

void dfs(int i){
	vis[i] = true;
	for (int j : adj[i])
		if (!vis[j]) dfs(j);
}

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);

	cin >> n >> m;
	FOR(i, 1, m){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	FOR(i, 1, n){
		cin >> ord[i];
	}
	dfs(1);
	bool flag = true;
	FOR(i, 1, n){
		if (!vis[i]){
			flag = false;
			break;
		}
	}
	cout << (flag? "YES" : "NO") << '\n';
	vector <int> untouch;
	FOR(i, 2, n){
		untouch.push_back(ord[i - 1]);
		FOR(i, 1, n) vis[i] = false;
		for (int j : untouch) vis[j] = true;
		dfs(ord[i]);
		bool flag = true;
		FOR(i, 1, n){
			if (!vis[i]){
				flag = false;
				break;
			}
		}
		cout << (flag? "YES" : "NO") << '\n';
	}

		 
}
/* problem link: 

*/
