/**    
* LANG: C++ 
* author: atom 
* created: 09.07.2022 08:19:15
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
constexpr int MAX = 9;
constexpr int INF = INT_MAX;

int t;


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);

	vector <string> cows = {"Beatrice", "Belinda", 
					"Bella", "Bessie", "Betsy", 
					"Blue", "Buttercup", "Sue"};
	map <string, int> cows_ind;

	for (int i = 0; i < cows.size(); ++i){
		cows_ind[cows[i]] = i; 
	}
	cin >> t;
	vector <int> adj[cows.size()];
	while (t--){
		vector <string> s(cows.size());
		FOR(i, 1, 6){
			cin >> s[i];
		}
		adj[cows_ind[s[1]]].pb(cows_ind[s[6]]);
		adj[cows_ind[s[6]]].pb(cows_ind[s[1]]);
	}
	vector <bool> vis(cows.size());

	vector <int> ans;
	FOR(i, 0, cows.size() - 1){
		if (!vis[i] && adj[i].size() <= 1){
			vis[i] = true;
			ans.pb(i);
			if (adj[i].size() == 1){
				int pre = i;
				int nb = adj[i][0];
				while (adj[nb].size() == 2){
					vis[nb] = true;
					ans.pb(nb);
					int a = adj[nb][0];
					int b = adj[nb][1];
					pre = nb;
					nb = (a == pre)? b : a;
				}
				vis[nb] = true;
				ans.pb(nb);
			}
		}
	}

	for (int i : ans)
		cout << cows[i] << '\n';
		// cout << i << '\n';
		 
}
/* problem link: 

*/

