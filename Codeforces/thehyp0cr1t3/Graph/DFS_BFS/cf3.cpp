/**    
* LANG: C++ 
* author: atom 
* created: 12.07.2022 12:00:06
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

int prefix[MAX], a[MAX], pos[MAX];
int sum_1, sum_2, sum_3, p, n;

int orz(){
    cin.tie(nullptr) -> sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    sum_1 = a[n - 1] + a[n];
    sum_2 = 0, p = n;

    for (int i = n - 2; i >= 1; i--){
        while (p > i && sum_1 - a[p] >= sum_2 + a[p]){
            sum_1 -= a[p];
            sum_2 += a[p];
            p--;
        }
        pos[i] = p;
        sum_1 += a[i];
    }    

    FOR(i, 1, n){
    	cout << pos[i] << ' ';
    }
    cout << '\n';
    int ans = INF, cur_Max, cur_Min;
    for (int i = 1; i <= n - 2; i++){
    	int cur_pos = pos[i];
        sum_1 = prefix[i];
        sum_2 = prefix[cur_pos] - prefix[i];
        sum_3 = prefix[n] - prefix[cur_pos];

        cur_Max = max({sum_1, sum_2, sum_3});
        cur_Min = min({sum_1, sum_2, sum_3});
        ckmin(ans, cur_Max - cur_Min);

        if (cur_pos >= i){
        	cur_pos--;
        	sum_1 = prefix[i];
        	sum_2 = prefix[cur_pos] - prefix[i];
        	sum_3 = prefix[n] - prefix[cur_pos];

        	cur_Max = max({sum_1, sum_2, sum_3});
        	cur_Min = min({sum_1, sum_2, sum_3});
        	ckmin(ans, cur_Max - cur_Min);

        	debug(sum_1, sum_2, sum_3);
    	    debug(cur_Min, cur_Max);
	        debug(ans);
        }
    }
    cout << ans << '\n';    
}
/* problem link: 

*/
    