/**    
* LANG: C++ 
* author: atom 
* created: 05.07.2022 14:37:54
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
constexpr int MAX = 1e6 + 2;
constexpr int INF = INT_MAX;

int a[MAX], n, I;
int cntDis[MAX];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> I;
	FOR(i, 1, n){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	a[0] = -1;
	int cnt = 0;
	FOR(i, 1, n){
		if (a[i] != a[i - 1]) cnt++;
		cntDis[cnt]++;
	}
	FOR(i, 2, cnt) cntDis[i] += cntDis[i - 1];
	// n * log2(K) <= I * 8 break; 
	int K = 20, ans = 20;
	FORD(i, n, 0){
		if (ceil(log2(i)) * n <= 8 * I){
			K = i;
			break;
		}
	}
	if (K >= cnt) ans = 0;
	else {
		ans = INF;
		FOR(i, K, cnt){
			ans = min(ans, n - (cntDis[i] - cntDis[i - K]));
		}
	}
	 cout << ans << '\n';
}
/* problem link: 

*/

