/**    
* LANG: C++ 
* author: atom 
* created: 04.07.2022 01:03:36
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
constexpr int MAX = 1002;
constexpr int INF = 999999999;
 
int c, ox, ni, m;
struct scuba{
	int o, n, w;
};
scuba a[MAX];
// int dp[MAX][MAX / 2][MAX / 2];
// dp : minimum weight from 1 to i to have j oxigen and k nitrogen
int pre[22][82], cur[22][82];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> c;
	while (c--){
		cin >> ox >> ni >> m;
		for (int i = 1; i <= m; ++i){
			cin >> a[i].o >> a[i].n >> a[i].w;
		}
		for (int j = 0; j <= ox; j++)
			for (int k = 0; k <= ni; ++k) pre[j][k] = MOD;
		
		pre[0][0] = 0;
		for (int i = 1; i <= m; i++){
			for (int j = 0; j <= ox; ++j)
				for (int k = 0; k <= ni; k++){
					cur[j][k] = min(pre[j][k], pre[max(j - a[i].o, 0)][max(k - a[i].n, 0)] + a[i].w);
				}
			swap(pre, cur);
		}
		cout << pre[ox][ni] << '\n';
	}
		 
}
/* problem link: 
	https://www.spoj.com/problems/SCUBADIV/
*/

