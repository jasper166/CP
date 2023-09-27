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
constexpr int MAX = 1e6 + 2;
constexpr int INF = INT_MAX;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n;
string s;

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n;
	vector <set <int>> adj(n + 1);
	cin.ignore();
	FOR(i, 1, n){
		getline(cin, s);
		stringstream ss;
		string tmp;
		ss << s;
		int found;

		while (!ss.eof()){
			ss >> tmp;
			if (stringstream(tmp) >> found){
				adj[i].insert(found);
			}
		}
	}
	debug(adj);
	FOR(i, 1, n){
		for (int x : adj[i]) cout << i << " " << x << '\n';
	}
		 
}
/* problem link: 

*/
