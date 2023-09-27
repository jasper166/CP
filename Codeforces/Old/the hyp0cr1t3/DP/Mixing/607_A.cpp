#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define travel(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define orz main
#define sz(x) (int)(x).size()
#define eb emplace_back
#define pob pop_back
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert


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
void __print(const T &x) {int f = 0;cerr << '{'; for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T const& t, V const& ... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef LOCAL
#define debug(x...) cout << "#L" <<__LINE__<< ":" <<" [" << #x << "]=\n" <<"["; _print(x); cout << '\n';
#else
#define debug(...) 42
#endif


constexpr int MOD = (int) 1e9 + 7;
constexpr int INF = (int) 1e9;
constexpr int MAX = (int) 1e6 + 2;

int n, a[MAX], pos[MAX];
int dp[MAX];
void run_case(){
    cin >> n;
    FOR(i, 1, n){
        int x, y;
        cin >> x >> y;
        a[i] = x;
        pos[a[i]] = y;
    }
    if (pos[0]) dp[0] = 1;
    int maxi = *max_element(a + 1, a + 1 + n);
    //FOR(i, 1, maxi) cout << i << " \n"[i == n]; 
    FOR(i, 1, maxi){
        if (pos[i]){
          if (i > pos[i])  
            dp[i] = dp[i - pos[i] - 1] + 1;
          else dp[i] = 1;  
        }
        else 
            dp[i] = dp[i - 1];
    }
    int ret = 0;
    FOR(i, 1, n) ckmax(ret, dp[a[i]]);
    cout << n - ret << "\n";
}

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	
	int Test = 1;
	//cin >> Test;
	while (Test--){

		run_case();
	}

		 
}

