/**    
* LANG: C++ 
* author: atom 
* created: 06.07.2022 21:21:08
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
int a[MAX][MAX];
bool v[MAX][MAX], flag[MAX];
int n;

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n;
	FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];
	vector <pii> edge;
	vector <set <int>> adj(n + 1);
	FOR(i, 1, n){
		FOR(j, 1, n){
			if (a[i][j]){
				edge.pb({i, j});
				adj[i].insert(j);
				flag[i] = true;
			}
		}
	}
	for (auto x : edge) cout << x.F << ' ' << x.S << '\n';
	cout << '\n';
	FOR (i, 1, n){
		cout << i << " : ";
		for (int j : adj[i]) cout << j << ' ';
		cout << '\n';
	}
		 
}
/* problem link: 

*/
