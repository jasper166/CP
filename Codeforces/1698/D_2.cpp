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

int t, n; 

int orz(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> t;
    while (t--){
        cin >> n;
        vector <int> a;
        int l = 1, r = n, ans = n;
        while (l <= r){
            int m = (l + r) / 2;
            int res = 0;
            a.clear();
            a.assign(m, 0);
            cout << "? ";
            fflush(stdout);
            cout << 1 << " " << m << endl;
            fflush(stdout);
            FOR(i, 0, m - 1) cin >> a[i];
            FOR(i, 0, m - 1){
                if (a[i] <= m) res++;
            }
            if (res % 2){
                r = m - 1;
            }
            else {
                ans = m;
                l = m + 1;
            }
        }
        cout << "! " << l << endl;
        fflush(stdout);
    }
}
/* problem link: 

*/

