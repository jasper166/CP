/**    
* LANG: C++ 
* author: atom 
* created: 28.06.2022 17:28:39
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
#define endl cout << '\n'

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
int t, n, a[MAX]; 

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	cin >> t;
	while (t--){
		cin >> n;
		map <int, int> mp;
		deque <int> dq;
		int zero = 0, neg = 0, pos = 0;
		FOR(i, 1, n){
			cin >> a[i];
			if (a[i] == 0) zero++;
			else{
				if (a[i] > 0) pos++;
				else neg++;
				dq.pb(a[i]);
			}
			mp[a[i]]++;
		}
		if (zero) dq.pb(0);
		sort(a + 1, a + n + 1);
		bool ok = true;
		if (neg >= 3 || pos >= 3){
			cout << "NO" << '\n';
			continue;
		}

		int li = dq.size();
		FOR(i, 0, li - 1)
			FOR(j, i + 1, li - 1)
				FOR(k, j + 1, li - 1){
					if (mp[dq[i] + dq[j] + dq[k]] == 0){
						ok = false;
						break;
					}
				}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}

}
/* problem link: 

*/

