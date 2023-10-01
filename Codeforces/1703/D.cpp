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
constexpr int MAX = 1e6 + 2;
constexpr int INF = INT_MAX;
 
int t, n, ret[MAX], base = 31;

int get_hash(string s){
	int ans = 0;
	for (char x : s){
		ans = (ans * base + x - 'a' + 1) % MOD;
	}
	return ans;
};

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n;
		vector <string> s(n + 1);
		map<int, int> hash_T;
		vector <int> hash(n + 1);
		FOR(i, 1, n){
			cin >> s[i];
			int cur_hash = get_hash(s[i]);
			hash[i] = cur_hash;
			hash_T[cur_hash]++;
		}
		int ok = 0;
		FOR(i, 1, n){
			int tmp = hash[i];
			FOR(j, 1, n){
				if (j == i) continue;
				if (hash_T[tmp + hash[j]]){
					ok = 1;
					break;
				}
			}
			if (ok){
				ret[i] = 1;
				break;
			}
			ret[i] = 0;
		}
		FOR(i, 1, n){
			cout << ret[i];
		}
		cout << '\n';
	}

		 
}
/* problem link: 

*/

