/**    
* LANG: C++ 
* author: atom 
* created: 04.07.2022 18:06:43
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
constexpr int MAX = 5005;
constexpr int INF = INT_MAX;
 
int t, n, maxi;
int a[MAX], dp[MAX], coconut[MAX];
int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> t;
	while (t--){
 	   	cin >> n;
 	   	FOR(i, 0, n + 2) dp[i] = -INF;
    	FOR(i, 1, n) cin >> a[i];

	    dp[0] = 0;
    	for(int i = 1; i <= n + 1; i++){
        	maxi = 0;
        	FOR(i, 0, n + 1) coconut[i] = 0;
			FORD(j, i - 1, 0){
            	if((i & 1) != (j & 1)){
                	if(a[i] == a[j] ||  !j || i == n + 1){
                    	if(!(maxi > (i - j - 1) / 2)){
                        dp[i] = max(dp[i], dp[j] + (i != (n + 1)));
                    }
                }
            }
            coconut[a[j]]++;
            maxi = max(maxi, coconut[a[j]]);
       	 }
    	}
    	cout << dp[n + 1] << '\n';
	}
		 
}
/* problem link: 

*/

