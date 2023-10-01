/**    
* LANG: C++ 
* author: atom 
* created: 12.07.2022 22:06:49
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
constexpr int MAX = 102;
constexpr int INF = INT_MAX;
int n, t;
string s;
int a[MAX][MAX], ii[4], jj[4];
bool ok[MAX][MAX];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n;
		FOR(i, 0, n) FOR(j, 0, n) ok[i][j] = true;
		FOR(i, 0, n - 1){
			cin >> s;
			FOR(j, 0, n - 1){
				a[i][j] = (s[j] - '0');
			}
		}
		int ret = 0;
		FOR(i, 0, n - 1){
			FOR(j, 0, n - 1){
				jj[0] = j;
				ii[0] = i; 
				FOR(i, 1, 3){
					ii[i] = jj[i - 1];
					jj[i] = n - 1 - ii[i - 1];
				}
				if (ok[i][j] && ok[ii[1]][jj[1]] && ok[ii[2]][jj[2]] && ok[ii[3]][jj[3]]){
					int junk = a[i][j] + a[ii[2]][jj[2]] + a[ii[3]][jj[3]] + a[ii[1]][jj[1]];
					ckmin(junk, 4 - junk);
					ret += junk;
					ok[i][j] = ok[ii[1]][jj[1]] = ok[ii[2]][jj[2]] = ok[ii[3]][jj[3]] = false;
				}
			}
		}
		cout << ret << '\n';
	}

		 
}
/* problem link: 

*/

