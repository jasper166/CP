/**    
* LANG: C++ 
* author: atom 
* created: 14.07.2022 14:28:14
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
constexpr int MAX = 255;
constexpr int INF = INT_MAX;

int n, m, cur;
int a[MAX][MAX];
bool vis[MAX][MAX];
map <int, int> mp;
pii tour[] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};


void bfs(int x, int y){
	queue <pii> q;
	q.push({x, y});
	vis[x][y] = true;
	while (!q.empty()){
		pii c = q.front(); q.pop();
		for (int i = 0; i <= 3; i++){
			pii nx = make_pair(c.F + tour[i].F, c.S + tour[i].S);
			if (a[nx.F][nx.S] && !vis[nx.F][nx.S]){
				vis[nx.F][nx.S] = true;
				cur++;
				q.push({nx.F, nx.S});
			}
		}
	}
}


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	while (cin >> n >> m){
		if (n == 0 and m == 0) break;
		mp.clear();
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
			cin >> a[i][j];
			vis[i][j] = false;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (a[i][j] && !vis[i][j]){
					cur = 1;
					bfs(i, j);
					mp[cur]++;
				}
		int ret = 0;
		for (auto i : mp) ret += i.S;
		cout << ret << "\n";
		for (auto i : mp) cout << i.F << " " << i.S << "\n";
	}
		 
}
/* problem link: 
	https://www.spoj.com/problems/UCV2013H/
*/

