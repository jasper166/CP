/**    
* LANG: C++ 
* author: atom 
* created: 17.07.2022 09:52:28
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
constexpr int MAX = 1e5 + 2;
constexpr ll INF = 1e18;

ll n, s, f;
ll 	a[MAX];
ll l[4], c[4], dp[MAX];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	FOR(i, 1, 3) cin >> l[i];
	FOR(i, 1, 3) cin >> c[i];
	cin >> n >> s >> f;
	if (s > f) swap(s, f);
	FOR(i, 2, n) cin >> a[i];
	FOR(i, s, n + 1) dp[i] = LLONG_MAX - 2 * INF;
	dp[s] = 0;
	for (int i = s + 1; i <= f; i++){
		for (int j = 1; j <= 3; j++){
			int p = lower_bound(a + 1, a + n + 1, a[i] - l[j]) - a;
			debug(a[i] - l[j], p);
			ckmin(dp[i], dp[p] + c[j]);
			debug(dp[i], i );
		}
		
	}
	cout << dp[f] << "\n";
		 
}
/* problem link: 

*/

