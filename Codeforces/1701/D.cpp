/**    
* LANG: C++ 
* author: atom 
* created: 08.07.2022 16:59:57
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
constexpr int MAX = 1e6 + 2;
constexpr int INF = INT_MAX;
 
int t, n, m;
int b[MAX], a[MAX];

struct cmp2{
	bool operator()(pair <pii, int> x, pair <pii, int> y){
		if (x.F.F > y.F.F) return true;
		if (x.F.F < y.F.F)  return false;
		if (x.F.S > y.F.S) return true;
		return false;
	}
};

bool cmp1(pair <pii, int> x, pair <pii, int> y){
	if (x.F.S < y.F.S) return true;
	return false;
};

// a[r] = i;
int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n;
		FOR(i, 1, n) cin >> b[i];
		vector <pair <pii, int>>que;
		FOR(i, 1, n){
			if (b[i] == 0){
				que.pb({{n, i + 1}, i});
			}
			else {
				que.pb({{i / b[i], i / (b[i] + 1) + 1}, i});
			}
		}
		sort(all(que), cmp1);
		priority_queue <pair <pii, int>, vector <pair <pii, int>>, cmp2> pque;
		int j = 0;
		FOR(i, 1, n){
			while (j < n && que[j].F.S <= i){
				pque.push(que[j]);
				j++;
			}
			a[pque.top().S] = i;
			pque.pop();
		}
		FOR(i, 1, n) cout << a[i] << ' ';
		cout << '\n';
	}

		 
}
/* problem link: 

*/

